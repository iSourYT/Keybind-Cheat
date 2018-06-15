#include "Hooks.h"
#include "Hacks.h"
#include <intrin.h>
#include "DLLMain.h"
#include "Interfaces.h"
#include "Chams.h"
#include "RenderManager.h"
#include "GrenadePrediction.h"
#include "MiscHacks.h"
#include "CRC32.h"
#include <map>
#include <iostream>
#include <cstdio>
#include <ctime>
#include "Interfaces.h"
#include "MiscDef.h"
#include "Entities.h"
#include "Hooks.h"
#include "GameEventManager.h"
#include <deque>
#include <algorithm>
#include "XorStr.h"
#include "GUI.h"

namespace G
{
	CInput::CUserCmd *UserCmd;
}


typedef void(__thiscall* DrawModelEx_)(void*, void*, void*, const ModelRenderInfo_t&, matrix3x4*);
typedef bool(__stdcall *create_move)(float, CInput::CUserCmd*);
typedef void(__thiscall* PaintTraverse_)(PVOID, unsigned int, bool, bool);
typedef void(__stdcall *FrameStageNotifyFn)(ClientFrameStage_t);

create_move oCreateMove;
PaintTraverse_ oPaintTraverse;
FrameStageNotifyFn oFrameStageNotify;
DrawModelEx_ oDrawModelExecute;


void __fastcall Hooked_DrawModelExecute(void* thisptr, int edx, void* ctx, void* state, const ModelRenderInfo_t &pInfo, matrix3x4 *pCustomBoneToWorld);
bool __stdcall CreateMoveClient_Hooked(/*void* self, int edx,*/ float frametime, CInput::CUserCmd* pCmd);
void __fastcall PaintTraverse_Hooked(PVOID pPanels, int edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce);
void  __stdcall Hooked_FrameStageNotify(ClientFrameStage_t curStage);

namespace Hooks
{
	// VMT Managers
	Utilities::Memory::VMTManager VMTPanel; // Hooking drawing functions
	Utilities::Memory::VMTManager VMTClient; // Maybe CreateMove
	Utilities::Memory::VMTManager VMTClientMode; // CreateMove for functionality
	Utilities::Memory::VMTManager VMTClientMode2; // CreateMove2 for functionality
	Utilities::Memory::VMTManager VMTModelRender; // DrawModelEx for chams
	Utilities::Memory::VMTManager VMTPrediction; // InPrediction for no vis recoil
	Utilities::Memory::VMTManager VMTPlaySound; // Autoaccept 
	Utilities::Memory::VMTManager VMTRenderView;
	Utilities::Memory::VMTManager VMTEventManager; // EventManager
	Utilities::Memory::VMTManager g_pD3DDevice9Hook; // EventManager
	Utilities::Memory::VMTManager VMTRunCommand; // EventManager
};

void Hooks::UndoHooks()
{
	VMTPanel.RestoreOriginal();
	VMTPrediction.RestoreOriginal();
	VMTModelRender.RestoreOriginal();
	VMTClientMode.RestoreOriginal();
	VMTClientMode2.RestoreOriginal();
	g_pD3DDevice9Hook.RestoreOriginal();
}


void Hooks::Initialise()
{
	VMTPanel.Initialise((DWORD*)Interfaces::Panels);
	oPaintTraverse = (PaintTraverse_)VMTPanel.HookMethod((DWORD)&PaintTraverse_Hooked, Offsets::VMT::Panel_PaintTraverse);

	VMTPrediction.Initialise((DWORD*)Interfaces::Prediction);
	//Hooked_InPrediction(Ex for no recoil)

	VMTModelRender.Initialise((DWORD*)Interfaces::ModelRender);
	//DME Hook

	VMTClientMode.Initialise((DWORD*)Interfaces::ClientMode);
	VMTClientMode.HookMethod((DWORD)CreateMoveClient_Hooked, 24);

	VMTClient.Initialise((DWORD*)Interfaces::Client);
	oFrameStageNotify = (FrameStageNotifyFn)VMTClient.HookMethod((DWORD)&Hooked_FrameStageNotify, 36);

	VMTEventManager.Initialise((DWORD*)Interfaces::GameEventManager);

	auto dwDevice = **(uint32_t**)(Utilities::Memory::FindPatternV2("shaderapidx9.dll", "A1 ? ? ? ? 50 8B 08 FF 51 0C") + 1);
	while (!(DirectX::g_hWindow = FindWindowA(XorStr("Valve001"), NULL))) Sleep(200);

	if (DirectX::g_hWindow)
		DirectX::g_pOldWindowProc = (WNDPROC)SetWindowLongPtr(DirectX::g_hWindow, GWLP_WNDPROC, (LONG_PTR)DirectX::Hooked_WndProc);

	g_pD3DDevice9Hook.Initialise((DWORD*)dwDevice);
	g_pD3DDevice9Hook.HookMethod((DWORD)DirectX::Hooked_Reset, 16);
	g_pD3DDevice9Hook.HookMethod((DWORD)DirectX::Hooked_EndScene, 42);
	DirectX::g_fnOriginalReset = (DirectX::Reset_t)g_pD3DDevice9Hook.HookMethod((DWORD)DirectX::Hooked_Reset, 16);
	DirectX::g_fnOriginalEndScene = (DirectX::EndScene_t)g_pD3DDevice9Hook.HookMethod((DWORD)DirectX::Hooked_EndScene, 42);
	VMTModelRender.Initialise((DWORD*)Interfaces::ModelRender);
	oDrawModelExecute = (DrawModelEx_)VMTModelRender.HookMethod((DWORD)&Hooked_DrawModelExecute, Offsets::VMT::ModelRender_DrawModelExecute);
}

class CFixMove {
public:
	void Start(CInput::CUserCmd*);
	void Stop(CInput::CUserCmd*);
	QAngle GetOldAngle();
private:
	QAngle old;
	float oldFowardMove;
	float oldSideMove;

	void CorrectMovement(QAngle vOldAngles, CInput::CUserCmd* pCmd, float fOldForward, float fOldSidemove);
};

void CFixMove::CorrectMovement(QAngle vOldAngles, CInput::CUserCmd* pCmd, float fOldForward, float fOldSidemove)
{
	//side/forward move correction
	float deltaView = pCmd->viewangles.y - vOldAngles.y;
	float f1;
	float f2;

	if (vOldAngles.y < 0.f)
		f1 = 360.0f + vOldAngles.y;
	else
		f1 = vOldAngles.y;

	if (pCmd->viewangles.y < 0.0f)
		f2 = 360.0f + pCmd->viewangles.y;
	else
		f2 = pCmd->viewangles.y;

	if (f2 < f1)
		deltaView = abs(f2 - f1);
	else
		deltaView = 360.0f - abs(f1 - f2);
	deltaView = 360.0f - deltaView;

	pCmd->forwardmove = cos(DEG2RAD(deltaView)) * fOldForward + cos(DEG2RAD(deltaView + 90.f)) * fOldSidemove;
	pCmd->sidemove = sin(DEG2RAD(deltaView)) * fOldForward + sin(DEG2RAD(deltaView + 90.f)) * fOldSidemove;
}

void CFixMove::Start(CInput::CUserCmd* pCmd) {
	old = pCmd->viewangles;
	oldFowardMove = pCmd->forwardmove;
	oldSideMove = pCmd->sidemove;
}

void CFixMove::Stop(CInput::CUserCmd* pCmd) {
	CorrectMovement(old, pCmd, oldFowardMove, oldSideMove);
}

QAngle CFixMove::GetOldAngle() {
	return old;
}


bool __stdcall CreateMoveClient_Hooked(/*void* self, int edx,*/ float frametime, CInput::CUserCmd* pCmd)
{
	Hooks::VMTClientMode.GetMethod<create_move>(24)(frametime, pCmd);
	if (!pCmd->command_number)
		return true;

	int sequence_number = 0;
	CInput::CVerifiedUserCmd *verifiedCommands = *(CInput::CVerifiedUserCmd **)(reinterpret_cast< uint32_t >(Interfaces::pInput) + 0xF0);
	CInput::CVerifiedUserCmd *verified = &verifiedCommands[sequence_number % 150];
	CInput::CUserCmd *cmd = Interfaces::pInput->GetUserCmd2(0, sequence_number);
	static CFixMove *FixMoveManager = new CFixMove();


	if (Interfaces::Engine->IsConnected() && Interfaces::Engine->IsInGame())
	{
		PVOID pebp;
		__asm mov pebp, ebp;
		bool* pbSendPacket = (bool*)(*(DWORD*)pebp - 0x1C);
		bool& bSendPacket = *pbSendPacket;

		IClientEntity *pEnt;
		IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

		if (!pLocal)
			return;

		// Backup for safety
		Vector origView = pCmd->viewangles;
		Vector viewforward, viewright, viewup, aimforward, aimright, aimup;
		Vector qAimAngles;
		qAimAngles.Init(0.0f, pCmd->viewangles.y, 0.0f);
		AngleVectors(qAimAngles, &viewforward, &viewright, &viewup);


		if (Interfaces::Engine->IsConnected() && Interfaces::Engine->IsInGame() && pLocal && pLocal->IsAlive()) {
			Hacks::MoveHacks(pCmd, bSendPacket);
		}


		FixMoveManager->Start(pCmd);

		FixMoveManager->Stop(pCmd);

	}

	if (!pCmd && !pCmd->command_number == 0)
		return Hooks::VMTClientMode.GetMethod<create_move>(24)(frametime, pCmd);


	return false;

	return false;
	oCreateMove(frametime, pCmd);
	verified->m_crc = pCmd->GetChecksum();
}



void __fastcall PaintTraverse_Hooked(PVOID pPanels, int edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce)
{

	IClientEntity* localplayer = (IClientEntity*)Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	static unsigned int FocusOverlayPanel = 0;
	static bool FoundPanel = false;

	if (!FoundPanel)
	{
		PCHAR szPanelName = (PCHAR)Interfaces::Panels->GetName(vguiPanel);
		if (strstr(szPanelName, "MatSystemTopPanel"))
		{
			FocusOverlayPanel = vguiPanel;
			FoundPanel = true;
		}
	}
	else if (FocusOverlayPanel == vguiPanel)
	{
		Render::Text(132, 20, Color(100, 100, 100, 255), Render::Fonts::ESP, "Welcome");
		Render::Text(132, 32, Color(100, 100, 100, 255), Render::Fonts::ESP, "User: oSour");

		// BunnyHop
		Render::Text(150, 48, Color(255, 255, 255, 255), Render::Fonts::ESP, "Bunnyhop:");
		if (GetAsyncKeyState(VK_NUMPAD1) & 1) OptionsManager.bAutoHop = !OptionsManager.bAutoHop;
		Render::Text(250, 48, OptionsManager.bAutoHop ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bAutoHop ? L"ON" : L"OFF");

		// AutoStrafe
		Render::Text(150, 64, Color(255, 255, 255, 255), Render::Fonts::ESP, "Autostrafe:");
		if (GetAsyncKeyState(VK_NUMPAD2) & 1) OptionsManager.bAutoStrafe = !OptionsManager.bAutoStrafe;
		Render::Text(250, 64, OptionsManager.bAutoStrafe ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bAutoStrafe ? L"ON" : L"OFF");

		// Chams
		static int Chams;
		if (true)
		{
		Render::Text(150, 80, Color(255, 255, 255, 255), Render::Fonts::ESP, "Chams:");

		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		Chams += 1;

		if (Chams > 4)
		Chams = 0;

		if (Chams < 0)
		Chams = 4;

		OptionsManager.bChams = Chams;
		switch (Chams)
		{
		case 0: Render::Text(250, 80, Color(255, 0, 0, 255), Render::Fonts::ESP, XorStr("OFF"));break;
		case 1: Render::Text(250, 80, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("Visible Only"));break;
		case 2: Render::Text(250, 80, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("Visible Flat"));break;
		case 3: Render::Text(250, 80, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("Full Chams"));break;
		case 4: Render::Text(250, 80, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("Flat Chams")); break;
		}
		}

		// Bomb Timer
		Render::Text(150, 96, Color(255, 255, 255, 255), Render::Fonts::ESP, "Bomb Timer:");
		if (GetAsyncKeyState(VK_NUMPAD4) & 1) OptionsManager.bBombTimer = !OptionsManager.bBombTimer;
		Render::Text(250, 96, OptionsManager.bBombTimer ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bBombTimer ? L"ON" : L"OFF");

		// Player ESP
		//Render::Text(150, 80, Color(255, 255, 255, 255), Render::Fonts::ESP, "Chams:");
		//if (GetAsyncKeyState(VK_NUMPAD3) & 1) OptionsManager.bChams = !OptionsManager.bChams;
		//Render::Text(250, 80, OptionsManager.bChams ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bChams ? L"ON" : L"OFF");

		// AntiAim
		//Render::Text(150, 96, Color(255, 255, 255, 255), Render::Fonts::ESP, "AA");
		//if (GetAsyncKeyState(VK_NUMPAD4) & 1) OptionsManager.bAntiAimOn = !OptionsManager.bAntiAimOn;
		//Render::Text(250, 96, OptionsManager.bAntiAimOn ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bAntiAimOn ? L"ON" : L"OFF");

		// AntiAim Mode
		/*if (true)
		{
			Render::Text(150, 112, Color(255, 255, 255, 255), Render::Fonts::ESP, "AA Mode:");

			if (GetAsyncKeyState(VK_NUMPAD5) & 1)
				OptionsManager.bAntiAimMode += 1;

			if (OptionsManager.bAntiAimMode > 9)
				OptionsManager.bAntiAimMode = 0;

			if (OptionsManager.bAntiAimMode < 0)
				OptionsManager.bAntiAimMode = 9;

			switch (OptionsManager.bAntiAimMode)
			{
			case 0: Render::Text(250, 112, Color(255, 0, 0, 255), Render::Fonts::ESP, XorStr("OFF")); break;
			case 1: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Backwards")); break;
			case 2: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Sideways")); break;
			case 3: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Fake Spin")); break;
			case 4: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("BackJitter")); break;
			case 5: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Crosshair")); break;
			case 6: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Lowerbody")); break;
			case 7: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Fake Lowerbody")); break;
			case 8: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Automatic Point")); break;
			case 9: Render::Text(250, 112, Color(255, 255, 0, 255), Render::Fonts::ESP, XorStr("Legit Trolling")); break;
			}
		}*/

		// Aimbot
		//Render::Text(150, 128, Color(255, 255, 255, 255), Render::Fonts::ESP, "Ragebot:");
		//if (GetAsyncKeyState(VK_NUMPAD6) & 1) OptionsManager.bEnableRagebot = !OptionsManager.bEnableRagebot;
		//Render::Text(250, 128, OptionsManager.bEnableRagebot ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bEnableRagebot ? L"ON" : L"OFF");

		// Aimbot Mode
		/*if (true)
		{
			Render::Text(150, 144, Color(255, 255, 255, 255), Render::Fonts::ESP, "HvH:");

			if (GetAsyncKeyState(VK_NUMPAD7) & 1)
				OptionsManager.bAimbotMode += 1;

			if (OptionsManager.bAimbotMode > 1)
				OptionsManager.bAimbotMode = 0;

			if (OptionsManager.bAimbotMode < 0)
				OptionsManager.bAimbotMode = 1;

			switch (OptionsManager.bAimbotMode)
			{
			case 0: Render::Text(250, 144, Color(255, 0, 0, 255), Render::Fonts::ESP, XorStr("OFF")); break;
			case 1: Render::Text(250, 144, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("ON")); break;
			}
		}*/

		//Render::Text(150, 160, Color(255, 255, 255, 255), Render::Fonts::ESP, "Resolver:");
		//if (GetAsyncKeyState(VK_NUMPAD8) & 1) OptionsManager.bBruteforceResolver = !OptionsManager.bBruteforceResolver;
		//Render::Text(250, 160, OptionsManager.bBruteforceResolver ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bBruteforceResolver ? L"ON" : L"OFF");

		// Simulated Mode
		//Render::Text(150, 176, Color(255, 255, 255, 255), Render::Fonts::ESP, "pSilent:");
		//if (GetAsyncKeyState(VK_NUMPAD9) & 1) OptionsManager.bSilentAim = !OptionsManager.bSilentAim;
		//Render::Text(250, 176, OptionsManager.bSilentAim ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bSilentAim ? L"ON" : L"OFF");


		// Weapon FOV Mode
		//static int WeaponFOV;
		/*if (true)
		{
			Render::Text(150, 192, Color(255, 255, 255, 255), Render::Fonts::ESP, "weapon fov:");

			if (GetAsyncKeyState(VK_NUMPAD0) & 1)
				WeaponFOV += 1;

			if (WeaponFOV > 3)
				WeaponFOV = 0;

			if (WeaponFOV < 0)
				WeaponFOV = 3;

			switch (WeaponFOV)
			{
			case 0: Render::Text(250, 192, Color(255, 0, 0, 255), Render::Fonts::ESP, XorStr("default")); OptionsManager.bWeaponFOV = 68; break;
			case 1: Render::Text(250, 192, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("80")); OptionsManager.bWeaponFOV = 80; break;
			case 2: Render::Text(250, 192, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("90")); OptionsManager.bWeaponFOV = 90; break;
			case 3: Render::Text(250, 192, Color(0, 255, 0, 255), Render::Fonts::ESP, XorStr("100")); OptionsManager.bWeaponFOV = 100; break;
			}
		}*/

		
		//Render::Text(150, 208, Color(255, 255, 255, 255), Render::Fonts::ESP, "BombTimer:");
		//if (GetAsyncKeyState(VK_F1) & 1) OptionsManager.bBombTimer = !OptionsManager.bBombTimer;
		//Render::Text(250, 208, OptionsManager.bBombTimer ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bBombTimer ? L"ON" : L"OFF");

		// DME Chams
		//Render::Text(150, 224, Color(255, 255, 255, 255), Render::Fonts::ESP, "dme chams:");
		//if (GetAsyncKeyState(VK_UP) & 1) OptionsManager.bDMEChams = !OptionsManager.bDMEChams;
		//Render::Text(250, 224, OptionsManager.bDMEChams ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255), Render::Fonts::ESP, OptionsManager.bDMEChams ? L"[+]" : L"[-]");

		if (Interfaces::Engine->IsConnected() && Interfaces::Engine->IsInGame())
			Hacks::DrawHacks();

	}
	oPaintTraverse(pPanels, vguiPanel, forceRepaint, allowForce);
}

void __fastcall Hooked_DrawModelExecute(void* thisptr, int edx, void* ctx, void* state, const ModelRenderInfo_t &pInfo, matrix3x4 *pCustomBoneToWorld)
{

	Color color;
	float flColor[3] = { 0.f };
	static IMaterial* CoveredLit = CreateMaterial(true);
	static IMaterial* OpenLit = CreateMaterial(false);
	static IMaterial* CoveredFlat = CreateMaterial(true, false);
	static IMaterial* OpenFlat = CreateMaterial(false, false);
	bool DontDraw = false;
	const char* ModelName = Interfaces::ModelInfo->GetModelName((model_t*)pInfo.pModel);
	IClientEntity* pModelEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(pInfo.entity_index);
	IClientEntity* pLocal = (IClientEntity*)Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());


	int ChamsStyle = OptionsManager.bChams;
	int HandsStyle;
	int WeaponsChams;

	IMaterial *covered = ChamsStyle == 1 || ChamsStyle == 3 ? CoveredLit : CoveredFlat;
	IMaterial *open = ChamsStyle == 1 || ChamsStyle == 3 ? OpenLit : OpenFlat;

	if (ChamsStyle != 0 && strstr(ModelName, "models/player") && OptionsManager.bChams > 0)
	{
		if (pModelEntity == nullptr)
			return;

		if (pLocal || pModelEntity->GetTeamNum() != pLocal->GetTeamNum())
		{


			IClientEntity* pModelEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(pInfo.entity_index);
			if (pModelEntity)
			{
				IClientEntity *local = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
				if (local)
				{
					if (pModelEntity->IsAlive() && pModelEntity->GetHealth() > 0 && pModelEntity->GetTeamNum() != local->GetTeamNum())
					{
						float alpha = 1.f;

						if (pModelEntity->HasGunGameImmunity())
							alpha = 0.5f;

						if (pModelEntity->GetTeamNum() == 2)
						{
							flColor[0] = OptionsManager.TESP[0];
							flColor[1] = OptionsManager.TESP[1];
							flColor[2] = OptionsManager.TESP[2];
						}
						else
						{
							flColor[0] = OptionsManager.CTESP[0];
							flColor[1] = OptionsManager.CTESP[1];
							flColor[2] = OptionsManager.CTESP[2];
						}

						if (ChamsStyle == 3 || ChamsStyle == 4)
						{
							Interfaces::RenderView->SetColorModulation(flColor);
							Interfaces::RenderView->SetBlend(1);
							Interfaces::ModelRender->ForcedMaterialOverride(covered);
							oDrawModelExecute(thisptr, ctx, state, pInfo, pCustomBoneToWorld);
						}
						else
						{
							Interfaces::RenderView->SetBlend(0);
						}

						if (pModelEntity->GetTeamNum() == 2)
						{
							flColor[0] = OptionsManager.TESPV[0];
							flColor[1] = OptionsManager.TESPV[1];
							flColor[2] = OptionsManager.TESPV[2];
						}
						else
						{
							flColor[0] = OptionsManager.CTESPV[0];
							flColor[1] = OptionsManager.CTESPV[1];
							flColor[2] = OptionsManager.CTESPV[2];
						}
						Interfaces::RenderView->SetColorModulation(flColor);
						Interfaces::RenderView->SetBlend(alpha);
						Interfaces::ModelRender->ForcedMaterialOverride(open);
					}

					else
					{
						DontDraw;
					}
				}
			}
		}
	}

	if (!DontDraw)
		oDrawModelExecute(thisptr, ctx, state, pInfo, pCustomBoneToWorld);
	Interfaces::ModelRender->ForcedMaterialOverride(NULL);
}


void  __stdcall Hooked_FrameStageNotify(ClientFrameStage_t curStage)
{
	IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	if (curStage == FRAME_NET_UPDATE_POSTDATAUPDATE_START)
	{
		
	}

	if (Interfaces::Engine->IsConnected() && Interfaces::Engine->IsInGame() && curStage == FRAME_RENDER_START) {

	}
	oFrameStageNotify(curStage);
}


