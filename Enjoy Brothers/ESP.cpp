#include <iostream>
#include <algorithm>
#include "ESP.h"
#include "Interfaces.h"
#include "RenderManager.h"
#include "OptionsManager.h"
#include "Hooks.h"

float damage;
char bombdamagestringdead[24];
char bombdamagestringalive[24];
#define charenc( s ) ( s )

void CEsp::Init()
{
	BombCarrier = nullptr;
}

void CEsp::Move(CInput::CUserCmd *pCmd, bool &bSendPacket)
{

}

void CEsp::Draw()
{

	Color color;



	ClientClass* cClass;
	IClientEntity *pLocal = hackManager.pLocal();

	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		ClientClass* cClass;
		player_info_t pinfo;
		if (pEntity && pEntity != pLocal && !pEntity->IsDormant() && pEntity != nullptr)
		{
			if (Interfaces::Engine->GetPlayerInfo(i, &pinfo) && pEntity->IsAlive())
			{
			}
			ClientClass* cClass = (ClientClass*)pEntity->GetClientClass();
			if (OptionsManager.bBombTimer)
			{
				if (cClass->m_ClassID == (int)CSGOClassID::CPlantedC4)
					DrawBombPlanted(pEntity, cClass);
			}
		}
	}

	if (OptionsManager.bSpecList)
		SpecList();

	if (OptionsManager.bNoFlash)
	{
		DWORD m_flFlashMaxAlpha = NetVar.GetNetVar(0xFE79FB98);
		*(float*)((DWORD)pLocal + m_flFlashMaxAlpha) = 0;
	}
	else
	{
		DWORD m_flFlashMaxAlpha = NetVar.GetNetVar(0xFE79FB98);
		*(float*)((DWORD)pLocal + m_flFlashMaxAlpha) = 255;
	}
}

void CEsp::DrawBombPlanted(IClientEntity* pEntity, ClientClass* cClass)
{
	BombCarrier = nullptr;
	Vector vOrig; Vector vScreen;
	vOrig = pEntity->GetOrigin();
	CCSBomb* Bomb = (CCSBomb*)pEntity;
	int Width;
	int Height;
	Interfaces::Engine->GetScreenSize(Width, Height);
	float flBlow = Bomb->GetC4BlowTime();
	float TimeRemaining = flBlow - (Interfaces::Globals->interval_per_tick * hackManager.pLocal()->GetTickBase());
	float defuse = Bomb->GetC4DefuseCountDown();
	int r = 255 - TimeRemaining * 6;
	int g = TimeRemaining * 6;

	if (TimeRemaining > 0 && !Bomb->IsBombDefused())
	{
		float flDistance = hackManager.pLocal()->GetEyePosition().DistTo(pEntity->GetEyePosition());
		float a = 450.7f;
		float b = 75.68f;
		float c = 789.2f;
		float d = ((flDistance - b) / c);
		float flDamage = a * exp(-d * d);
		damage = float((std::max)((int)ceilf(CSGO_Armor(flDamage, hackManager.pLocal()->ArmorValue())), 0));


		char buffer[64];
		sprintf_s(buffer, "Explodes in %.1f", TimeRemaining);

		sprintf_s(bombdamagestringdead, sizeof(bombdamagestringdead) - 1, "Health left: 0");
		sprintf_s(bombdamagestringalive, sizeof(bombdamagestringalive) - 1, "Health left: %.0f", hackManager.pLocal()->GetHealth() - damage);

		if (TimeRemaining > -2.f)
		{
			if (damage >= hackManager.pLocal()->GetHealth())
			{
				Render::Text(5, 46, Color(250, 42, 42, 255), Render::Fonts::ESP, bombdamagestringdead);
			}
			else if (hackManager.pLocal()->GetHealth() > damage)
			{
				Render::Text(5, 46, Color(0, 255, 0, 255), Render::Fonts::ESP, bombdamagestringalive);
			}
		}

		Render::Text(5, 25, Color(r, g, 0, 255), Render::Fonts::ESP, buffer);

		int w;
		int h;
		Interfaces::Engine->GetScreenSize(w, h);
		int halfX = w / 2;
		int thirdY = h / 3;

		if (Bomb->GetBombDefuser() > 0)
		{
			float countdown = Bomb->GetC4DefuseCountDown() - (hackManager.pLocal()->GetTickBase() * Interfaces::Globals->interval_per_tick);
			if (countdown > 0.01f)
			{
				if (TimeRemaining > countdown)
				{
					char defuseTimeString[24];
					sprintf_s(defuseTimeString, sizeof(defuseTimeString) - 1, "Defusing: %.1f", countdown);
					RECT TimeSize = Render::GetTextSize(Render::Fonts::ESP, defuseTimeString);
					Render::Text(halfX - TimeSize.right / 2, thirdY, Color(0, 0, 255, 255), Render::Fonts::ESP, defuseTimeString);
				}
			}
		}
		if (Render::WorldToScreen(vOrig, vScreen))
		{
			float flBlow = Bomb->GetC4BlowTime();
			float TimeRemaining = flBlow - (Interfaces::Globals->interval_per_tick * hackManager.pLocal()->GetTickBase());
			char buffer[64];
			sprintf_s(buffer, "Explodes in %.1f", TimeRemaining);
			Render::Text(vScreen.x, vScreen.y, Color(r, g, 0, 255), Render::Fonts::ESP, buffer);
		}
	}
}

void CEsp::SpecList()
{
	IClientEntity *pLocal = hackManager.pLocal();

	RECT scrn = Render::GetViewport();
	int ayy = 0;

	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
		{
			IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
			player_info_t pinfo;

			if (pEntity &&  pEntity != pLocal)
			{
				if (Interfaces::Engine->GetPlayerInfo(i, &pinfo) && !pEntity->IsAlive() && !pEntity->IsDormant())
				{
					HANDLE obs = pEntity->GetObserverTargetHandle();

					if (obs)
					{
						IClientEntity *pTarget = Interfaces::EntList->GetClientEntityFromHandle(obs);
						player_info_t pinfo2;
						if (pTarget == pLocal)
						{
							if (Interfaces::Engine->GetPlayerInfo(pTarget->GetIndex(), &pinfo2))
							{
								char buf[255]; sprintf_s(buf, "%s", pinfo.name);
								RECT TextSize = Render::GetTextSize(Render::Fonts::ESP, buf);
								Render::Text(scrn.right - TextSize.right - 4, (scrn.top / 4) + (16 * ayy), pTarget->GetIndex() == pLocal->GetIndex() ? Color(255, 255, 255, 255) : Color(255, 255, 255, 255), Render::Fonts::ESP, pinfo.name);
								ayy++;
							}
						}
					}
				}
			}
		}
}
