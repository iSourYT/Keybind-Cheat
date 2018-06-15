/*
Syn's Payhake Framework for Insanity & Razor
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Hacks.h"
#include "Interfaces.h"
#include "ESP.h"
#include "RenderManager.h"
#include "OptionsManager.h"
#include "MiscHacks.h"
#include "windows.h"
CEsp Esp;
CMiscHacks MiscHacks;
//CLegitBot LegitBot;
//CRageBot Ragebot;
void Hacks::SetupHacks()
{
	Esp.Init();
	MiscHacks.Init();
	//LegitBot.Init();
	//Ragebot.Init();

	hackManager.RegisterHack(&Esp);
	hackManager.RegisterHack(&MiscHacks);
	//hackManager.RegisterHack(&LegitBot);
	//hackManager.RegisterHack(&Ragebot);

	hackManager.Ready();
}

using PlaySoundFn = void(__stdcall*)(const char*);
extern PlaySoundFn oPlaySound;
PlaySoundFn oPlaySound;
void __stdcall Hooked__PlaySoundCSGO(const char* fileName)
{

}

void Hacks::DrawHacks()
{
	IClientEntity *pLocal = hackManager.pLocal();

	hackManager.Draw();
}

void Hacks::MoveHacks(CInput::CUserCmd *pCmd, bool &bSendPacket)
{
	Vector origView = pCmd->viewangles;
	IClientEntity *pLocal = hackManager.pLocal();
	hackManager.Move(pCmd, bSendPacket);
}

HackManager hackManager;

void HackManager::RegisterHack(CHack* hake)
{
	Hacks.push_back(hake);
	hake->Init();
}

void HackManager::Draw()
{
	if (!IsReady)
		return;
	pLocalInstance = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
	if (!pLocalInstance) return;

	for (auto &hack : Hacks)
	{
		hack->Draw();
	}
}
void HackManager::Move(CInput::CUserCmd *pCmd, bool &bSendPacket)
{
	if (!IsReady)
		return;
	pLocalInstance = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
	if (!pLocalInstance) return;

	for (auto &hack : Hacks)
	{
		hack->Move(pCmd, bSendPacket);
	}
}

IClientEntity* HackManager::pLocal()
{
	return pLocalInstance;
}

void HackManager::Ready()
{
	IsReady = true;
}
