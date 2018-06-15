#pragma once
#include <map>
#include <unordered_map>
#include <set>
#include "Entities.h"

class CCacheAngle {
public:
	//Menu
	bool bCustomSetts = false;
	bool bCorrect = true;
	int iResolverType = 0;
	bool bPrioritize = false;
	int iHitbox = 1;
	bool bAutoBaim = false;
	int iAutoBaimAferShot = 2;
	int iHitboxAutoBaim = 4;
	bool bPrioritizeVis = true;
	float flMinDmg = 5.f;
	bool bInterpLagComp = false;

	//GlobalPlayer
	bool bFlip = false;
};

class COptions {
public:
	//Global
	bool bAutoHop = false;
	bool bAutoStrafe = false;

	//Menu related
	bool bShowMenu = false;
	bool vecPressedKeys[256] = {};

	//TargetList related
	CCacheAngle aCacheAngle[64];

	struct ResolverData
	{
		float simtime, flcycle[13], flprevcycle[13], flweight[13], flweightdatarate[13], fakewalkdetection[2], fakeanglesimtimedetection[2], fakewalkdetectionsimtime[2];
		float yaw, addyaw, lbycurtime;
		float shotsimtime, oldlby, lastmovinglby, balanceadjustsimtime, balanceadjustflcycle;
		int fakeanglesimtickdetectionaverage[4], amountgreaterthan2, amountequal1or2, amountequal0or1, amountequal1, amountequal0, resetmovetick, resetmovetick2;
		int tick, balanceadjusttick, missedshots, activity[13];
		bool bfakeangle, bfakewalk, playerhurtcalled, weaponfirecalled;
		Vector shotaimangles, hitboxPos, balanceadjustaimangles;
		uint32_t norder[13];
		char* resolvermode = "NONE", *fakewalk = "Not Moving";
	};
	ResolverData pResolverData[64];

	//VISUALS
	bool bESPEnable = false;
	bool bGlow = false;
	int bChams = 0;
	bool bSpecList = true;
	int bWeaponFOV = 0;
	bool bBox = false;
	bool bDroppedWeapon = false;
	bool bDrawInfo = false;
	bool bBarrel = false;
	bool bBombTimer = false;
	bool bHealthBar = false;
	int bBoxESP = 0; //bool bBoxESP = false;
	bool bArmorBar = false;
	bool bPlayerName = false;
	bool bPlayerIndex = false;
	bool bBoneESP = false;
	bool bWeaponESP = false;
	bool bNoScope = false;
	bool bThirdPerson = false;
	bool bSnapLines = false;
	bool bAALines = false;
	bool bSpreadCross = false;
	bool bAmmoESP = false;


	//AIMBOT
	bool bEnableRagebot = false;
	int bAimbotMode = 0;
	bool bAutoShoot = true;
	bool bAutoPistol = true;
	bool bBruteforceResolver = false;
	bool bAutoRevolver = true;
	bool bAutoScope = true;
	bool bSilentAim = false;
	int iHitchance = 0;
	int iHitChanceSeed = 256;

	bool bCorrect = true;
	bool bBackTack = false;
	int bBackTrackTicks = 12;
	int iResolverType = 0;
	bool aMultiHitboxes[15] = {
		true, true, true, true, true,
		true, true, true, true, true,
		true, true, true, true, true
	};
	bool bPrioritize = true;
	int iHitbox = 0;
	bool bAutoBaim = false;
	int iAutoBaimAferShot = 3;
	int iHitboxAutoBaim = 4;
	bool bPrioritizeVis = false;
	float flMinDmg = 5.f;
	bool bInterpLagComp = true;

	//ANTI-AIM
	bool bFakeLag = false;
	int iFakeLagAmount = 1;
	bool bAntiAimOn = false;
	int bAntiAimMode = 0;
	int iAAPitch = 0;
	int iAARealYaw = 0;
	int iAAFakeYaw = 0;
	bool bSlowMo = false;
	int iLBYReal = 0;
	int iLBYFake = 0;


	// Misc
	bool bNoVisRecoil = false;
	bool bNoFlash = false;
	bool bClantagchanger = false;
	bool bWaterMark = false;
	bool bIndicators = false;
	int iFov = 90;
	int iFov2 = 90;


	//SETTINGS
	float Corner = 7;
	float TESP[3] = { 1.f, 0, 0 };
	float CTESP[3] = { 0, 0, 1.f };
	float TESPV[3] = { 1.f, 1.f, 0 };
	float CTESPV[3] = { 0, 1.f, 1.f };

	float TGlow[3] = { 1.f, 0, 0 };
	float CTGlow[3] = { 0, 0, 1.f };
	float TGlowV[3] = { 1.f, 1.f, 0 };
	float CTGlowV[3] = { 0, 1.f, 1.f };

	float EnemyChamsVis[3] = { 1.f, 0, 0 };
	float EnemyChamsNVis[3] = { 0, 0, 1.f };
	float TeamChamsVis[3] = { 1.f, 1.f, 0 };
	float TeamChamsNVis[3] = { 0, 1.f, 1.f };
	float s_MenuTransparency = 1;
	float bESPAllyColor[4] = { 0.0f, 1.0f, 0.0f, 1.0f }; //RGBA color
	float bESPEnemyColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

	// TAB
	bool g_tRagebot = true;
	bool g_tLegitbot = false;
	bool g_tVisuals = false;
	bool g_tMisc = false;
	bool g_tSettings = false;
	bool g_hitBoxList = true;
};

extern COptions OptionsManager;