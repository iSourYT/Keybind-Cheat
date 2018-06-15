

#pragma once


#include "Utilities.h"

// Various offsets
namespace Offsets
{
	// Sets up all the shit we need
	void Initialise();

	// Addresses of loaded game modules
	namespace Modules
	{
		extern DWORD Client;
		extern DWORD Engine;
		extern DWORD VGUI2;
		extern DWORD VGUISurface;
		extern DWORD Material;
		extern DWORD VPhysics;
		extern DWORD Stdlib;
	};

	// Virtual Method Table Indexes
	namespace VMT
	{
		//CHL Client
		extern DWORD CHL_GetAllClasses;

		//Engine Client
		extern DWORD Engine_GetScreenSize;
		extern DWORD Engine_GetPlayerInfo;
		extern DWORD Engine_GetLocalPlayer;
		extern DWORD Engine_Time;
		extern DWORD Engine_GetViewAngles;
		extern DWORD Engine_SetViewAngles;
		extern DWORD Engine_GetMaxClients;
		extern DWORD Engine_IsConnected;
		extern DWORD Engine_IsInGame;
		extern DWORD Engine_WorldToScreenMatrix;
		extern DWORD Engine_GetNetChannelInfo;
		extern DWORD Engine_ClientCmd_Unrestricted;

		// Panels
		extern DWORD Panel_GetName;
		extern DWORD Panel_PaintTraverse;

		// Surface
		extern DWORD Surface_DrawSetColorA;
		extern DWORD Surface_DrawSetColorB;
		extern DWORD Surface_DrawFilledRect;
		extern DWORD Surface_DrawOutlinedRect;
		extern DWORD Surface_DrawLine;
		extern DWORD Surface_DrawSetTextFont;
		extern DWORD Surface_DrawSetTextColorA;
		extern DWORD Surface_DrawSetTextColorB;
		extern DWORD Surface_DrawSetTextPos;
		extern DWORD Surface_DrawPrintText;
		extern DWORD Surface_DrawSetTextureRGBA;
		extern DWORD Surface_DrawSetTexture;
		extern DWORD Surface_CreateNewTextureID;
		extern DWORD Surface_FontCreate;
		extern DWORD Surface_SetFontGlyphSet;
		extern DWORD Surface_GetTextSize;
		extern DWORD Surface_DrawOutlinedCircle;
		extern DWORD Surface_SurfaceGetCursorPos;
		extern DWORD Surface_DrawTexturedPolygon;

		extern DWORD Material_GetName;
		extern DWORD Material_SetMaterialVarFlag;
		extern DWORD Material_GetMaterialVarFlag;
		extern DWORD Material_AlphaModulate;
		extern DWORD Material_ColorModulate;
		extern DWORD Material_IncrementReferenceCount;

		extern DWORD MaterialSystem_FindMaterial;
		extern DWORD MaterialSystem_CreateMaterial;

		extern DWORD ModelRender_ForcedMaterialOverride;
		extern DWORD ModelRender_DrawModelExecute;

		extern DWORD ModelInfo_GetModelName;
		extern DWORD ModelInfo_GetStudiomodel;

		extern DWORD RenderView_SetBlend;
		extern DWORD RenderView_SetColorModulation;

		// Weapon entities
		extern DWORD Weapon_GetSpread;
	};

	// Addresses of engine functions to call
	namespace Functions
	{
		extern DWORD KeyValues_KeyValues;
		extern DWORD KeyValues_LoadFromBuffer;
		extern DWORD dwCalcPlayerView;
		extern DWORD dwGetPlayerCompRank;
		extern DWORD dwIsReady;
	};

};

struct COffsets
{
	DWORD dwCompRanks;
	DWORD dwCompWins;
	DWORD m_iHealth;
	DWORD m_iTeamNum;
	DWORD m_bDormant;
	DWORD m_bGunGameImmunity;
	DWORD m_lifeState;
	DWORD m_fFlags;
	DWORD m_Local;
	DWORD m_nTickBase;
	DWORD m_bSpotted;
	DWORD m_nForceBone;
	DWORD m_mBoneMatrix;
	DWORD m_nModelIndex;
	DWORD m_viewPunchAngle;
	DWORD m_aimPunchAngle;
	DWORD m_vecOrigin;
	DWORD m_vecViewOffset;
	DWORD m_vecVelocity;
	DWORD m_szLastPlaceName;
	DWORD m_flNextPrimaryAttack;
	DWORD m_hActiveWeapon;
	DWORD m_fAccuracyPenalty;
	DWORD m_Collision;
	DWORD m_iShotsFired;
	DWORD m_iWeaponID;
	DWORD m_nMoveType;
	DWORD m_nHitboxSet;
	DWORD m_bHasHelmet;
	DWORD m_ArmorValue;
	DWORD m_CollisionGroup;
	DWORD m_iClass;
	DWORD m_bIsBroken;
	DWORD m_angEyeAngles;
	DWORD m_hOwnerEntity;
	DWORD modIdx = 0x00;
	DWORD m_flC4Blow;
	DWORD m_flFlashDuration;
	DWORD m_iGlowIndex;
	DWORD m_angEyeAnglesY;
	DWORD m_bHasDefuser;
	DWORD m_flLowerBodyYawTarget;
	DWORD m_bBombTicking;
	DWORD m_bBombDefused;
	DWORD m_hBombDefuser;

	DWORD m_bIsScoped;
	DWORD m_bIsDefusing;
	DWORD deadflag;
	DWORD viewModel = 0x00;
	DWORD m_hObserverTarget;

	DWORD m_nFallbackPaintKit;
	DWORD m_nFallbackSeed;
	DWORD m_flFallbackWear;
	DWORD m_nFallbackStatTrak;
	DWORD m_AttributeManager;
	DWORD m_Item;
	DWORD m_iEntityLevel;
	DWORD m_iItemIDHigh;
	DWORD m_iItemIDLow;
	DWORD m_iAccountID;
	DWORD m_flPostponeFireReadyTime;
	DWORD m_iEntityQuality;
	DWORD custName = 0x00;
	DWORD m_OriginalOwnerXuidLow;
	DWORD m_OriginalOwnerXuidHigh;
	DWORD m_iItemDefinitionIndex;
	DWORD m_hMyWearables = 0;
	DWORD ViewModelIndex;
	DWORD WorldModelIndex;
	DWORD m_iClip1;
	DWORD m_iClip2;
	DWORD m_bReloadVisuallyComplete;

	//sigs
	DWORD CalcPlayerView;
	DWORD ChangeClanTag;
	DWORD d3d9Device;
	DWORD SendPacket;
	DWORD GlowManager;
	DWORD LoadFromBufferEx;
	DWORD InitKeyValuesEx;
	DWORD ServerRankRevealAllEx;
	DWORD IsReadyEx;
	DWORD LoadSkyBoxName;
	DWORD FullUpdate;

};
extern COffsets offsets;

namespace Offsets
{
	extern void GrabOffsets();
}