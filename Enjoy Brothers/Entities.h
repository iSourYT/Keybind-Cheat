

#pragma once

#include "MiscDef.h"
#include "ClientRecvProps.h"
#include "offsets.h"
#include "Vector.h"
#include <time.h>
#include "Vector.h"
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <string>
#include <conio.h>
#include <vector>


extern float intervalPerTick;
#define TICK_INTERVAL			(  )
#define TIME_TO_TICKS( dt )		( (int)( 0.5f + (float)(dt) / intervalPerTick ) )

#define TEAM_CS_T 2
#define TEAM_CS_CT 3

#define BONE_USED_BY_HITBOX			0x00000100



#define ptr( x, x1, x2 ) *(x*)( (DWORD)x1 + (DWORD)x2 )






class IClientRenderable;
class IClientNetworkable;
class IClientUnknown;
class IClientThinkable;
class IClientEntity;
class CSWeaponInfo;

class CHudTexture
{
public:
	char type[64]; //0x0000
	char subtype[64]; //0x0040
	char unknowndata00[2]; //0x0080
	char charinFont; //0x0082
	char unknowndata01[1]; //0x0083
};//Size=0x00AC

class CSWeaponInfo
{
public:
	virtual ~CSWeaponInfo() {};
	char*		consoleName;			// 0x0004
	char		pad_0008[12];			// 0x0008
	int			iMaxClip1;				// 0x0014
	int			iMaxClip2;				// 0x0018
	int			iDefaultClip1;			// 0x001C
	int			iDefaultClip2;			// 0x0020
	char		pad_0024[8];			// 0x0024
	char*		szWorldModel;			// 0x002C
	char*		szViewModel;			// 0x0030
	char*		szDroppedModel;			// 0x0034
	char		pad_0038[4];			// 0x0038
	char*		N0000023E;				// 0x003C
	char		pad_0040[56];			// 0x0040
	char*		szEmptySound;			// 0x0078
	char		pad_007C[4];			// 0x007C
	char*		szBulletType;			// 0x0080
	char		pad_0084[4];			// 0x0084
	char*		szHudName;				// 0x0088
	char*		szWeaponName;			// 0x008C
	char		pad_0090[56];			// 0x0090
	int 		WeaponType;				// 0x00C8
	int			iWeaponPrice;			// 0x00CC
	int			iKillAward;				// 0x00D0
	char*		szAnimationPrefix;		// 0x00D4
	float		flCycleTime;			// 0x00D8
	float		flCycleTimeAlt;			// 0x00DC
	float		flTimeToIdle;			// 0x00E0
	float		flIdleInterval;			// 0x00E4
	bool		bFullAuto;				// 0x00E8
	char		pad_0x00E5[3];			// 0x00E9
	int			iDamage;				// 0x00EC
	float		flArmorRatio;			// 0x00F0
	int			iBullets;				// 0x00F4
	float		flPenetration;			// 0x00F8
	float		flFlinchVelocityModifierLarge;	// 0x00FC
	float		flFlinchVelocityModifierSmall;	// 0x0100
	float		flRange;				// 0x0104
	float		flRangeModifier;		// 0x0108
	float		flThrowVelocity;		// 0x010C
	char		pad_0x010C[12];			// 0x0110
	bool		bHasSilencer;			// 0x011C
	char		pad_0x0119[3];			// 0x011D
	char*		pSilencerModel;			// 0x0120
	int			iCrosshairMinDistance;	// 0x0124
	int			iCrosshairDeltaDistance;// 0x0128 - iTeam?
	float		flMaxPlayerSpeed;		// 0x012C
	float		flMaxPlayerSpeedAlt;	// 0x0130
	float		flSpread;				// 0x0134
	float		flSpreadAlt;			// 0x0138
	float		flInaccuracyCrouch;		// 0x013C
	float		flInaccuracyCrouchAlt;	// 0x0140
	float		flInaccuracyStand;		// 0x0144
	float		flInaccuracyStandAlt;	// 0x0148
	float		flInaccuracyJumpInitial;// 0x014C
	float		flInaccuracyJump;		// 0x0150
	float		flInaccuracyJumpAlt;	// 0x0154
	float		flInaccuracyLand;		// 0x0158
	float		flInaccuracyLandAlt;	// 0x015C
	float		flInaccuracyLadder;		// 0x0160
	float		flInaccuracyLadderAlt;	// 0x0164
	float		flInaccuracyFire;		// 0x0168
	float		flInaccuracyFireAlt;	// 0x016C
	float		flInaccuracyMove;		// 0x0170
	float		flInaccuracyMoveAlt;	// 0x0174
	float		flInaccuracyReload;		// 0x0178
	int			iRecoilSeed;			// 0x017C
	float		flRecoilAngle;			// 0x0180
	float		flRecoilAngleAlt;		// 0x0184
	float		flRecoilAngleVariance;	// 0x0188
	float		flRecoilAngleVarianceAlt;	// 0x018C
	float		flRecoilMagnitude;		// 0x0190
	float		flRecoilMagnitudeAlt;	// 0x0194
	float		flRecoilMagnitudeVariance;	// 0x0198
	float		flRecoilMagnitudeVarianceAlt;	// 0x019C
	float		flRecoveryTimeCrouch;	// 0x01A0
	float		flRecoveryTimeStand;	// 0x01A4
	float		flRecoveryTimeCrouchFinal;	// 0x01A8
	float		flRecoveryTimeStandFinal;	// 0x01AC
	int			iRecoveryTransitionStartBullet;// 0x01B0 
	int			iRecoveryTransitionEndBullet;	// 0x01B4
	bool		bUnzoomAfterShot;		// 0x01B8
	bool		bHideViewModelZoomed;	// 0x01B9
	char		pad_0x01B5[2];			// 0x01BA
	char		iZoomLevels[3];			// 0x01BC
	int			iZoomFOV[2];			// 0x01C0
	float		fZoomTime[3];			// 0x01C4
	char*		szWeaponClass;			// 0x01D4
	float		flAddonScale;			// 0x01D8
	char		pad_0x01DC[4];			// 0x01DC
	char*		szEjectBrassEffect;		// 0x01E0
	char*		szTracerEffect;			// 0x01E4
	int			iTracerFrequency;		// 0x01E8
	int			iTracerFrequencyAlt;	// 0x01EC
	char*		szMuzzleFlashEffect_1stPerson; // 0x01F0
	char		pad_0x01F4[4];			 // 0x01F4
	char*		szMuzzleFlashEffect_3rdPerson; // 0x01F8
	char		pad_0x01FC[4];			// 0x01FC
	char*		szMuzzleSmokeEffect;	// 0x0200
	float		flHeatPerShot;			// 0x0204
	char*		szZoomInSound;			// 0x0208
	char*		szZoomOutSound;			// 0x020C
	float		flInaccuracyPitchShift;	// 0x0210
	float		flInaccuracySoundThreshold;	// 0x0214
	float		flBotAudibleRange;		// 0x0218
	char		pad_0x0218[8];			// 0x0220
	char*		pWrongTeamMsg;			// 0x0224
	bool		bHasBurstMode;			// 0x0228
	char		pad_0x0225[3];			// 0x0229
	bool		bIsRevolver;			// 0x022C
	bool		bCannotShootUnderwater;	// 0x0230
};

enum class CSGOClassID
{
	CAK47 = 1,
	CBaseAnimating = 2,
	CBaseAnimatingOverlay = 3,
	CBaseAttributableItem = 4,
	CBaseButton = 5,
	CBaseCombatCharacter = 6,
	CBaseCombatWeapon = 7,
	CBaseCSGrenade = 8,
	CBaseCSGrenadeProjectile = 9,
	CBaseDoor = 10,
	CBaseEntity = 11,
	CBaseFlex = 12,
	CBaseGrenade = 13,
	CBaseParticleEntity = 14,
	CBasePlayer = 15,
	CBasePropDoor = 16,
	CBaseTeamObjectiveResource = 17,
	CBaseTempEntity = 18,
	CBaseToggle = 19,
	CBaseTrigger = 20,
	CBaseViewModel = 21,
	CBaseVPhysicsTrigger = 22,
	CBaseWeaponWorldModel = 23,
	CBeam = 24,
	CBeamSpotlight = 25,
	CBoneFollower = 26,
	CBreakableProp = 27,
	CBreakableSurface = 28,
	CC4 = 29,
	CCascadeLight = 30,
	CChicken = 31,
	CColorCorrection = 32,
	CColorCorrectionVolume = 33,
	CCSGameRulesProxy = 34,
	CCSPlayer = 35,
	CCSPlayerResource = 36,
	CCSRagdoll = 37,
	CCSTeam = 38,
	CDEagle = 39,
	CDecoyGrenade = 40,
	CDecoyProjectile = 41,
	CDynamicLight = 42,
	CDynamicProp = 43,
	CEconEntity = 44,
	CEconWearable = 45,
	CEmbers = 46,
	CEntityDissolve = 47,
	CEntityFlame = 48,
	CEntityFreezing = 49,
	CEntityParticleTrail = 50,
	CEnvAmbientLight = 51,
	CEnvDetailController = 52,
	CEnvDOFController = 53,
	CEnvParticleScript = 54,
	CEnvProjectedTexture = 55,
	CEnvQuadraticBeam = 56,
	CEnvScreenEffect = 57,
	CEnvScreenOverlay = 58,
	CEnvTonemapController = 59,
	CEnvWind = 60,
	CFEPlayerDecal = 61,
	CFireCrackerBlast = 62,
	CFireSmoke = 63,
	CFireTrail = 64,
	CFish = 65,
	CFlashbang = 66,
	CFogController = 67,
	CFootstepControl = 68,
	CFunc_Dust = 69,
	CFunc_LOD = 70,
	CFuncAreaPortalWindow = 71,
	CFuncBrush = 72,
	CFuncConveyor = 73,
	CFuncLadder = 74,
	CFuncMonitor = 75,
	CFuncMoveLinear = 76,
	CFuncOccluder = 77,
	CFuncReflectiveGlass = 78,
	CFuncRotating = 79,
	CFuncSmokeVolume = 80,
	CFuncTrackTrain = 81,
	CGameRulesProxy = 82,
	CHandleTest = 83,
	CHEGrenade = 84,
	CHostage = 85,
	CHostageCarriableProp = 86,
	CIncendiaryGrenade = 87,
	CInferno = 88,
	CInfoLadderDismount = 89,
	CInfoOverlayAccessor = 90,
	CItem_Healthshot = 91,
	CItemDogtags = 92,
	CKnife = 93,
	CKnifeGG = 94,
	CLightGlow = 95,
	CMaterialModifyControl = 96,
	CMolotovGrenade = 97,
	CMolotovProjectile = 98,
	CMovieDisplay = 99,
	CParticleFire = 100,
	CParticlePerformanceMonitor = 101,
	CParticleSystem = 102,
	CPhysBox = 103,
	CPhysBoxMultiplayer = 104,
	CPhysicsProp = 105,
	CPhysicsPropMultiplayer = 106,
	CPhysMagnet = 107,
	CPlantedC4 = 108,
	CPlasma = 109,
	CPlayerResource = 110,
	CPointCamera = 111,
	CPointCommentaryNode = 112,
	CPointWorldText = 113,
	CPoseController = 114,
	CPostProcessController = 115,
	CPrecipitation = 116,
	CPrecipitationBlocker = 117,
	CPredictedViewModel = 118,
	CProp_Hallucination = 119,
	CPropDoorRotating = 120,
	CPropJeep = 121,
	CPropVehicleDriveable = 122,
	CRagdollManager = 123,
	CRagdollProp = 124,
	CRagdollPropAttached = 125,
	CRopeKeyframe = 126,
	CSCAR17 = 127,
	CSceneEntity = 128,
	CSensorGrenade = 129,
	CSensorGrenadeProjectile = 130,
	CShadowControl = 131,
	CSlideshowDisplay = 132,
	CSmokeGrenade = 133,
	CSmokeGrenadeProjectile = 134,
	CSmokeStack = 135,
	CSpatialEntity = 136,
	CSpotlightEnd = 137,
	CSprite = 138,
	CSpriteOriented = 139,
	CSpriteTrail = 140,
	CStatueProp = 141,
	CSteamJet = 142,
	CSun = 143,
	CSunlightShadowControl = 144,
	CTeam = 145,
	CTeamplayRoundBasedRulesProxy = 146,
	CTEArmorRicochet = 147,
	CTEBaseBeam = 148,
	CTEBeamEntPoint = 149,
	CTEBeamEnts = 150,
	CTEBeamFollow = 151,
	CTEBeamLaser = 152,
	CTEBeamPoints = 153,
	CTEBeamRing = 154,
	CTEBeamRingPoint = 155,
	CTEBeamSpline = 156,
	CTEBloodSprite = 157,
	CTEBloodStream = 158,
	CTEBreakModel = 159,
	CTEBSPDecal = 160,
	CTEBubbles = 161,
	CTEBubbleTrail = 162,
	CTEClientProjectile = 163,
	CTEDecal = 164,
	CTEDust = 165,
	CTEDynamicLight = 166,
	CTEEffectDispatch = 167,
	CTEEnergySplash = 168,
	CTEExplosion = 169,
	CTEFireBullets = 170,
	CTEFizz = 171,
	CTEFootprintDecal = 172,
	CTEFoundryHelpers = 173,
	CTEGaussExplosion = 174,
	CTEGlowSprite = 175,
	CTEImpact = 176,
	CTEKillPlayerAttachments = 177,
	CTELargeFunnel = 178,
	CTEMetalSparks = 179,
	CTEMuzzleFlash = 180,
	CTEParticleSystem = 181,
	CTEPhysicsProp = 182,
	CTEPlantBomb = 183,
	CTEPlayerAnimEvent = 184,
	CTEPlayerDecal = 185,
	CTEProjectedDecal = 186,
	CTERadioIcon = 187,
	CTEShatterSurface = 188,
	CTEShowLine = 189,
	CTesla = 190,
	CTESmoke = 191,
	CTESparks = 192,
	CTESprite = 193,
	CTESpriteSpray = 194,
	CTest_ProxyToggle_Networkable = 194,
	CTestTraceline = 196,
	CTEWorldDecal = 197,
	CTriggerPlayerMovement = 198,
	CTriggerSoundOperator = 199,
	CVGuiScreen = 200,
	CVoteController = 201,
	CWaterBullet = 202,
	CWaterLODControl = 203,
	CWeaponAug = 204,
	CWeaponAWP = 205,
	CWeaponBaseItem = 206,
	CWeaponBizon = 207,
	CWeaponCSBase = 208,
	CWeaponCSBaseGun = 209,
	CWeaponCycler = 210,
	CWeaponElite = 211,
	CWeaponFamas = 212,
	CWeaponFiveSeven = 213,
	CWeaponG3SG1 = 214,
	CWeaponGalil = 215,
	CWeaponGalilAR = 216,
	CWeaponGlock = 217,
	CWeaponHKP2000 = 218,
	CWeaponM249 = 219,
	CWeaponM3 = 220,
	CWeaponM4A1 = 221,
	CWeaponMAC10 = 222,
	CWeaponMag7 = 223,
	CWeaponMP5Navy = 224,
	CWeaponMP7 = 225,
	CWeaponMP9 = 226,
	CWeaponNegev = 227,
	CWeaponNOVA = 228,
	CWeaponP228 = 229,
	CWeaponP250 = 230,
	CWeaponP90 = 231,
	CWeaponSawedoff = 232,
	CWeaponSCAR20 = 233,
	CWeaponScout = 234,
	CWeaponSG550 = 235,
	CWeaponSG552 = 236,
	CWeaponSG556 = 237,
	CWeaponSSG08 = 238,
	CWeaponTaser = 239,
	CWeaponTec9 = 240,
	CWeaponTMP = 241,
	CWeaponUMP45 = 242,
	CWeaponUSP = 243,
	CWeaponXM1014 = 244,
	CWorld = 245,
	DustTrail = 246,
	MovieExplosion = 247,
	ParticleSmokeGrenade = 248,
	RocketTrail = 249,
	SmokeTrail = 250,
	SporeExplosion = 251,
	SporeTrail = 252
};



struct  WeaponInfo_t
{
public:
	char		pad_0x0000[4];			// 0x0000
	char*		consoleName;			// 0x0004
	char		pad_0008[12];			// 0x0008
	int			iMaxClip1;				// 0x0014
	int			iMaxClip2;				// 0x0018
	int			iDefaultClip1;			// 0x001C
	int			iDefaultClip2;			// 0x0020
	char		pad_0024[8];			// 0x0024
	char*		szWorldModel;			// 0x002C
	char*		szViewModel;			// 0x0030
	char*		szDroppedModel;			// 0x0034
	char		pad_0038[4];			// 0x0038
	char*		N0000023E;				// 0x003C
	char		pad_0040[56];			// 0x0040
	char*		szEmptySound;			// 0x0078
	char		pad_007C[4];			// 0x007C
	char*		szBulletType;			// 0x0080
	char		pad_0084[4];			// 0x0084
	char*		szHudName;				// 0x0088
	char*		szWeaponName;			// 0x008C
	char		pad_0090[56];			// 0x0090
	int 		WeaponType;				// 0x00C8
	int			iWeaponPrice;			// 0x00CC
	int			iKillAward;				// 0x00D0
	char*		szAnimationPrefix;		// 0x00D4
	float		flCycleTime;			// 0x00D8
	float		flCycleTimeAlt;			// 0x00DC
	float		flTimeToIdle;			// 0x00E0
	float		flIdleInterval;			// 0x00E4
	bool		bFullAuto;				// 0x00E8
	char		pad_0x00E5[3];			// 0x00E9
	int			iDamage;				// 0x00EC
	float		flArmorRatio;			// 0x00F0
	int			iBullets;				// 0x00F4
	float		flPenetration;			// 0x00F8
	float		flFlinchVelocityModifierLarge;	// 0x00FC
	float		flFlinchVelocityModifierSmall;	// 0x0100
	float		flRange;				// 0x0104
	float		flRangeModifier;		// 0x0108
	float		flThrowVelocity;		// 0x010C
	char		pad_0x010C[12];			// 0x0110
	bool		bHasSilencer;			// 0x011C
	char		pad_0x0119[3];			// 0x011D
	char*		pSilencerModel;			// 0x0120
	int			iCrosshairMinDistance;	// 0x0124
	int			iCrosshairDeltaDistance;// 0x0128 - iTeam?
	float		flMaxPlayerSpeed;		// 0x012C
	float		flMaxPlayerSpeedAlt;	// 0x0130
	float		flSpread;				// 0x0134
	float		flSpreadAlt;			// 0x0138
	float		flInaccuracyCrouch;		// 0x013C
	float		flInaccuracyCrouchAlt;	// 0x0140
	float		flInaccuracyStand;		// 0x0144
	float		flInaccuracyStandAlt;	// 0x0148
	float		flInaccuracyJumpInitial;// 0x014C
	float		flInaccuracyJump;		// 0x0150
	float		flInaccuracyJumpAlt;	// 0x0154
	float		flInaccuracyLand;		// 0x0158
	float		flInaccuracyLandAlt;	// 0x015C
	float		flInaccuracyLadder;		// 0x0160
	float		flInaccuracyLadderAlt;	// 0x0164
	float		flInaccuracyFire;		// 0x0168
	float		flInaccuracyFireAlt;	// 0x016C
	float		flInaccuracyMove;		// 0x0170
	float		flInaccuracyMoveAlt;	// 0x0174
	float		flInaccuracyReload;		// 0x0178
	int			iRecoilSeed;			// 0x017C
	float		flRecoilAngle;			// 0x0180
	float		flRecoilAngleAlt;		// 0x0184
	float		flRecoilAngleVariance;	// 0x0188
	float		flRecoilAngleVarianceAlt;	// 0x018C
	float		flRecoilMagnitude;		// 0x0190
	float		flRecoilMagnitudeAlt;	// 0x0194
	float		flRecoilMagnitudeVariance;	// 0x0198
	float		flRecoilMagnitudeVarianceAlt;	// 0x019C
	float		flRecoveryTimeCrouch;	// 0x01A0
	float		flRecoveryTimeStand;	// 0x01A4
	float		flRecoveryTimeCrouchFinal;	// 0x01A8
	float		flRecoveryTimeStandFinal;	// 0x01AC
	int			iRecoveryTransitionStartBullet;// 0x01B0 
	int			iRecoveryTransitionEndBullet;	// 0x01B4
	bool		bUnzoomAfterShot;		// 0x01B8
	bool		bHideViewModelZoomed;	// 0x01B9
	char		pad_0x01B5[2];			// 0x01BA
	char		iZoomLevels[3];			// 0x01BC
	int			iZoomFOV[2];			// 0x01C0
	float		fZoomTime[3];			// 0x01C4
	char*		szWeaponClass;			// 0x01D4
	float		flAddonScale;			// 0x01D8
	char		pad_0x01DC[4];			// 0x01DC
	char*		szEjectBrassEffect;		// 0x01E0
	char*		szTracerEffect;			// 0x01E4
	int			iTracerFrequency;		// 0x01E8
	int			iTracerFrequencyAlt;	// 0x01EC
	char*		szMuzzleFlashEffect_1stPerson; // 0x01F0
	char		pad_0x01F4[4];			 // 0x01F4
	char*		szMuzzleFlashEffect_3rdPerson; // 0x01F8
	char		pad_0x01FC[4];			// 0x01FC
	char*		szMuzzleSmokeEffect;	// 0x0200
	float		flHeatPerShot;			// 0x0204
	char*		szZoomInSound;			// 0x0208
	char*		szZoomOutSound;			// 0x020C
	float		flInaccuracyPitchShift;	// 0x0210
	float		flInaccuracySoundThreshold;	// 0x0214
	float		flBotAudibleRange;		// 0x0218
	BYTE		pad_0x0218[8];			// 0x0220
	char*		pWrongTeamMsg;			// 0x0224
	bool		bHasBurstMode;			// 0x0228
	BYTE		pad_0x0225[3];			// 0x0229
	bool		bIsRevolver;			// 0x022C
	bool		bCannotShootUnderwater;	// 0x0230
	CHudTexture* iconWeaponS;
	CHudTexture* iconWeapon;
	CHudTexture* iconAmmo;
	CHudTexture* iconAmmo2;
	CHudTexture* iconCrosshair;
	CHudTexture* iconAutoaim;
	CHudTexture* iconZoomedCrosshair;
	CHudTexture* iconZoomedAutoaim;
	CHudTexture* iconWeaponSmall;
};

enum CSWeaponType
{
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_UNKNOWN
};


enum moveTypes
{
	MOVETYPE_NONE = 0,			// never moves
	MOVETYPE_ISOMETRIC,					// For players -- in TF2 commander view, etc.
	MOVETYPE_WALK,						// Player only - moving on the ground
	MOVETYPE_STEP,						// gravity, special edge handling -- monsters use this
	MOVETYPE_FLY,						// No gravity, but still collides with stuff
	MOVETYPE_FLYGRAVITY,				// flies through the air + is affected by gravity
	MOVETYPE_VPHYSICS,					// uses VPHYSICS for simulation
	MOVETYPE_PUSH,						// no clip to world, push and crush
	MOVETYPE_NOCLIP,					// No gravity, no collisions, still do velocity/avelocity
	MOVETYPE_LADDER,					// Used by players only when going onto a ladder
	MOVETYPE_OBSERVER,					// Observer movement, depends on player's observer mode
	MOVETYPE_CUSTOM,					// Allows the entity to describe its own physics
	MOVETYPE_LAST = MOVETYPE_CUSTOM,	// should always be defined as the last item in the list
	MOVETYPE_MAX_BITS = 4
};



/*enum class CSGOClassID
{
CTestTraceline = 189,
CTEWorldDecal = 190,
CTESpriteSpray = 187,
CTESprite = 186,
CTESparks = 185,
CTESmoke = 184,
CTEShowLine = 182,
CTEProjectedDecal = 179,
CTEPlayerDecal = 178,
CTEPhysicsProp = 175,
CTEParticleSystem = 174,
CTEMuzzleFlash = 173,
CTELargeFunnel = 171,
CTEKillPlayerAttachments = 170,
CTEImpact = 169,
CTEGlowSprite = 168,
CTEShatterSurface = 181,
CTEFootprintDecal = 165,
CTEFizz = 164,
CTEExplosion = 162,
CTEEnergySplash = 161,
CTEEffectDispatch = 160,
CTEDynamicLight = 159,
CTEDecal = 157,
CTEClientProjectile = 156,
CTEBubbleTrail = 155,
CTEBubbles = 154,
CTEBSPDecal = 153,
CTEBreakModel = 152,
CTEBloodStream = 151,
CTEBloodSprite = 150,
CTEBeamSpline = 149,
CTEBeamRingPoint = 148,
CTEBeamRing = 147,
CTEBeamPoints = 146,
CTEBeamLaser = 145,
CTEBeamFollow = 144,
CTEBeamEnts = 143,
CTEBeamEntPoint = 142,
CTEBaseBeam = 141,
CTEArmorRicochet = 140,
CTEMetalSparks = 172,
CSteamJet = 135,
CSmokeStack = 128,
DustTrail = 238,
CFireTrail = 62,
SporeTrail = 244,
SporeExplosion = 243,
RocketTrail = 241,
SmokeTrail = 242,
CPropVehicleDriveable = 117,
ParticleSmokeGrenade = 240,
CParticleFire = 96,
MovieExplosion = 239,
CTEGaussExplosion = 167,
CEnvQuadraticBeam = 55,
CEmbers = 45,
CEnvWind = 59,
CPrecipitation = 111,
CPrecipitationBlocker = 112,
CBaseTempEntity = 18,
NextBotCombatCharacter = 0,
CBaseAttributableItem = 4,
CEconEntity = 44,
CWeaponXM1014 = 236,
CWeaponTaser = 231,
CSmokeGrenade = 126,
CWeaponSG552 = 228,
CWeaponSawedoff = 224,
CWeaponNOVA = 220,
CIncendiaryGrenade = 85,
CMolotovGrenade = 93,
CWeaponM3 = 212,
CKnifeGG = 90,
CKnife = 89,
CHEGrenade = 82,
CFlashbang = 64,
CWeaponElite = 203,
CDecoyGrenade = 40,
CDEagle = 39,
CWeaponUSP = 235,
CWeaponM249 = 211,
CWeaponUMP45 = 234,
CWeaponTMP = 233,
CWeaponTec9 = 232,
CWeaponSSG08 = 230,
CWeaponSG556 = 229,
CWeaponSG550 = 227,
CWeaponScout = 226,
CWeaponSCAR20 = 225,
CSCAR17 = 122,
CWeaponP90 = 223,
CWeaponP250 = 222,
CWeaponP228 = 221,
CWeaponNegev = 219,
CWeaponMP9 = 218,
CWeaponMP7 = 217,
CWeaponMP5Navy = 216,
CWeaponMag7 = 215,
CWeaponMAC10 = 214,
CWeaponM4A1 = 213,
CWeaponHKP2000 = 210,
CWeaponGlock = 209,
CWeaponGalilAR = 208,
CWeaponGalil = 207,
CWeaponG3SG1 = 206,
CWeaponFiveSeven = 205,
CWeaponFamas = 204,
CWeaponBizon = 199,
CWeaponAWP = 198,
CWeaponAug = 197,
CAK47 = 1,
CWeaponCSBaseGun = 201,
CWeaponCSBase = 200,
CC4 = 29,
CBaseCSGrenade = 8,
CSmokeGrenadeProjectile = 127,
CMolotovProjectile = 94,
CDecoyProjectile = 41,
CFireCrackerBlast = 60,
CInferno = 86,
CChicken = 31,
CFootstepControl = 66,
CCSGameRulesProxy = 34,
CWeaponCubemap = 0,
CWeaponCycler = 202,
CTEPlantBomb = 176,
CTEFireBullets = 163,
CTERadioIcon = 180,
CPlantedC4 = 104,
CCSTeam = 38,
CCSPlayerResource = 36,
CCSPlayer = 35,
CCSRagdoll = 37,
CTEPlayerAnimEvent = 177,
CHostage = 83,
CHostageCarriableProp = 84,
CBaseCSGrenadeProjectile = 9,
CHandleTest = 81,
CTeamplayRoundBasedRulesProxy = 139,
CSpriteTrail = 133,
CSpriteOriented = 132,
CSprite = 131,
CRagdollPropAttached = 120,
CRagdollProp = 119,
CPredictedViewModel = 113,
CPoseController = 109,
CGameRulesProxy = 80,
CInfoLadderDismount = 87,
CFuncLadder = 72,
CTEFoundryHelpers = 166,
CEnvDetailController = 51,
CWorld = 237,
CWaterLODControl = 196,
CWaterBullet = 195,
CVoteController = 194,
CVGuiScreen = 193,
CPropJeep = 116,
CPropVehicleChoreoGeneric = 0,
CTriggerSoundOperator = 192,
CBaseVPhysicsTrigger = 22,
CTriggerPlayerMovement = 191,
CBaseTrigger = 20,
CTest_ProxyToggle_Networkable = 188,
CTesla = 183,
CBaseTeamObjectiveResource = 17,
CTeam = 138,
CSunlightShadowControl = 137,
CSun = 136,
CParticlePerformanceMonitor = 97,
CSpotlightEnd = 130,
CSpatialEntity = 129,
CSlideshowDisplay = 125,
CShadowControl = 124,
CSceneEntity = 123,
CRopeKeyframe = 121,
CRagdollManager = 118,
CPhysicsPropMultiplayer = 102,
CPhysBoxMultiplayer = 100,
CPropDoorRotating = 115,
CBasePropDoor = 16,
CDynamicProp = 43,
CProp_Hallucination = 114,
CPostProcessController = 110,
CPointCommentaryNode = 108,
CPointCamera = 107,
CPlayerResource = 106,
CPlasma = 105,
CPhysMagnet = 103,
CPhysicsProp = 101,
CStatueProp = 134,
CPhysBox = 99,
CParticleSystem = 98,
CMovieDisplay = 95,
CMaterialModifyControl = 92,
CLightGlow = 91,
CInfoOverlayAccessor = 88,
CFuncTrackTrain = 79,
CFuncSmokeVolume = 78,
CFuncRotating = 77,
CFuncReflectiveGlass = 76,
CFuncOccluder = 75,
CFuncMoveLinear = 74,
CFuncMonitor = 73,
CFunc_LOD = 68,
CTEDust = 158,
CFunc_Dust = 67,
CFuncConveyor = 71,
CFuncBrush = 70,
CBreakableSurface = 28,
CFuncAreaPortalWindow = 69,
CFish = 63,
CFireSmoke = 61,
CEnvTonemapController = 58,
CEnvScreenEffect = 56,
CEnvScreenOverlay = 57,
CEnvProjectedTexture = 54,
CEnvParticleScript = 53,
CFogController = 65,
CEnvDOFController = 52,
CCascadeLight = 30,
CEnvAmbientLight = 50,
CEntityParticleTrail = 49,
CEntityFreezing = 48,
CEntityFlame = 47,
CEntityDissolve = 46,
CDynamicLight = 42,
CColorCorrectionVolume = 33,
CColorCorrection = 32,
CBreakableProp = 27,
CBeamSpotlight = 25,
CBaseButton = 5,
CBaseToggle = 19,
CBasePlayer = 15,
CBaseFlex = 12,
CBaseEntity = 11,
CBaseDoor = 10,
CBaseCombatCharacter = 6,
CBaseAnimatingOverlay = 3,
CBoneFollower = 26,
CBaseAnimating = 2,
CAI_BaseNPC = 0,
CBeam = 24,
CBaseViewModel = 21,
CBaseParticleEntity = 14,
CBaseGrenade = 13,
CBaseCombatWeapon = 7,
CBaseWeaponWorldModel = 23
};*/

enum class CSGOHitboxID
{
	Head = 0,
	Neck,
	NeckLower,
	Pelvis,
	Stomach,
	LowerChest,
	Chest,
	UpperChest,
	RightThigh,
	LeftThigh,
	RightShin,
	LeftShin,
	RightFoot,
	LeftFoot,
	RightHand,
	LeftHand,
	RightUpperArm,
	RightLowerArm,
	LeftUpperArm,
	LeftLowerArm,
	Max,
};

// Weapon IDs
enum ItemDefinitionIndex : int
{
	WEAPON_DEAGLE = 1,
	WEAPON_ELITE = 2,
	WEAPON_FIVESEVEN = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALILAR = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_TASER = 31,
	WEAPON_HKP2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556 = 39,
	WEAPON_SSG08 = 40,
	WEAPON_KNIFE_CT = 42,
	WEAPON_FLASHBANG = 43,
	WEAPON_HEGRENADE = 44,
	WEAPON_SMOKEGRENADE = 45,
	WEAPON_MOLOTOV = 46,
	WEAPON_DECOY = 47,
	WEAPON_INCGRENADE = 48,
	WEAPON_C4 = 49,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER = 60,
	WEAPON_USP_SILENCER = 61,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_KNIFE_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9_BAYONET = 508,
	WEAPON_KNIFE_TACTICAL = 509,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY = 515,
	WEAPON_KNIFE_PUSH = 516,
	WEAPON_GLOVE_SPORTY = 5030
};

class ScriptCreatedItem
{
public:
	CPNETVAR_FUNC(int*, ItemDefinitionIndex, 0xE67AB3B8); //m_iItemDefinitionIndex
	CPNETVAR_FUNC(int*, ItemIDHigh, 0x714778A); //m_iItemIDHigh
	CPNETVAR_FUNC(int*, ItemIDLow, 0x3A3DFC74); //m_iItemIDLow
};

class AttributeContainer
{
public:
	CPNETVAR_FUNC(ScriptCreatedItem*, m_Item, 0x7E029CE5);
};


class CBaseCombatWeapon
{
public:
	CNETVAR_FUNC(float, GetNextPrimaryAttack, 0xDB7B106E); //m_flNextPrimaryAttack
	CNETVAR_FUNC(int, GetAmmoInClip, 0x97B6F70C); //m_iClip1
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin
	CPNETVAR_FUNC(int*, FallbackPaintKit, 0xADE4C870); // m_nFallbackPaintKit
	CPNETVAR_FUNC(int*, FallbackSeed, 0xC2D0683D); // m_nFallbackSeed
	CPNETVAR_FUNC(int*, ItemDefinitionIndex, 0xE67AB3B8); //m_iItemDefinitionIndex
	CPNETVAR_FUNC(float*, FallbackWear, 0xA263576C); //m_flFallbackWear
	CPNETVAR_FUNC(int*, FallbackStatTrak, 0x1ED78768); //m_nFallbackStatTrak
	CPNETVAR_FUNC(int*, OwnerXuidLow, 0xAD8D897F);
	CPNETVAR_FUNC(int*, OwnerXuidHigh, 0x90511E77);
	CPNETVAR_FUNC(int*, ViewModelIndex, 0x7F7C89C1);
	CPNETVAR_FUNC(int*, ModelIndex, 0x27016F83);
	CPNETVAR_FUNC(int*, WorldModelIndex, 0x4D8AD9F3);
	CPNETVAR_FUNC(char*, szCustomName, 0x0);
	CPNETVAR_FUNC(AttributeContainer*, m_AttributeManager, 0xCFFCE089);
	CNETVAR_FUNC(int, GetZoomLevel, 0x26553F1A);

	float GetInaccuracy()
	{
		typedef float(__thiscall* oInaccuracy)(PVOID);
		return call_vfunc< oInaccuracy >(this, 469)(this); // 484  old
	}


	int CBaseCombatWeapon::GetAmmo()
	{
		return *(int*)((DWORD)this + offsets.m_iClip1);
	}

	int CBaseCombatWeapon::GetAmmo2()
	{
		return *(int*)((DWORD)this + offsets.m_iClip2);
	}

	bool CBaseCombatWeapon::HaveAmmo()
	{
		return GetAmmo() > 0;
	}


	float GetInnacc()
	{
		typedef float(__thiscall *OrigFn)(void *);
		return call_vfunc<OrigFn>(this, 484)(this);
	}

	void SetModelIndex(int modelIndex) {
		typedef void(__thiscall* OriginalFn)(PVOID, int);
		return call_vfunc<OriginalFn>(this, 75)(this, modelIndex);
	}

	float GetSpread()
	{
		typedef float(__thiscall* oWeaponSpread)(PVOID);
		return call_vfunc< oWeaponSpread >(this, 439)(this);
	}

	void PreDataUpdate(int updateType)
	{
		PVOID pNetworkable = (PVOID)((DWORD)(this) + 0x8);
		typedef void(__thiscall* OriginalFn)(PVOID, int);
		return call_vfunc<OriginalFn>(pNetworkable, 6)(pNetworkable, updateType);
	}

	void UpdateAccPenalty()
	{
		typedef void(__thiscall *OrigFn)(void *);
		return call_vfunc<OrigFn>(this, 485)(this);
	}

	bool IsScoped(int x = 0)
	{
		return GetZoomLevel() > 0;
	}
	WeaponInfo_t* GetWpnData()
	{
		if (!this)
			return nullptr;

		typedef WeaponInfo_t*(__thiscall* OriginalFn)(void*);
		return call_vfunc< OriginalFn >(this, 446)(this);
	}
	CSWeaponInfo* GetCSWpnData()
	{
		if (!this)
			return nullptr;

		typedef CSWeaponInfo*(__thiscall* OriginalFn)(void*);
		return call_vfunc< OriginalFn >(this, 446)(this);
	}
};


class CCSBomb
{
public:

	HANDLE GetOwnerHandle()
	{
		return *(HANDLE*)((uintptr_t)this + GET_NETVAR("DT_BaseEntity", "m_hOwner"));
	}

	float GetC4BlowTime()
	{
		return *(float*)((uintptr_t)this + GET_NETVAR("DT_PlantedC4", "m_flC4Blow"));
	}

	float GetC4DefuseCountDown()
	{
		return *(float*)((uintptr_t)this + GET_NETVAR("DT_PlantedC4", "m_flDefuseCountDown"));
	}

	int GetBombDefuser()
	{
		return *(int*)((uintptr_t)this + GET_NETVAR("DT_PlantedC4", "m_hBombDefuser"));
	}

	bool IsBombDefused()
	{
		return *(bool*)((uintptr_t)this + GET_NETVAR("DT_PlantedC4", "m_bBombDefused"));
	}
};

class CLocalPlayerExclusive
{
public:
	CNETVAR_FUNC(Vector, GetViewPunchAngle, 0x68F014C0);//m_viewPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngle, 0xBF25C290);//m_aimPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngleVel, 0x8425E045);//m_aimPunchAngleVel

	Vector GetAimPunchAngle2()
	{
		return *(Vector*)((uintptr_t)this + 0x70);
	}
};


enum DrawModelFlags_t
{
	STUDIO_NONE = 0x00000000,
	STUDIO_RENDER = 0x00000001,
	STUDIO_VIEWXFORMATTACHMENTS = 0x00000002,
	STUDIO_DRAWTRANSLUCENTSUBMODELS = 0x00000004,
	STUDIO_TWOPASS = 0x00000008,
	STUDIO_STATIC_LIGHTING = 0x00000010,
	STUDIO_WIREFRAME = 0x00000020,
	STUDIO_ITEM_BLINK = 0x00000040,
	STUDIO_NOSHADOWS = 0x00000080,
	STUDIO_WIREFRAME_VCOLLIDE = 0x00000100,
	STUDIO_NOLIGHTING_OR_CUBEMAP = 0x00000200,
	STUDIO_SKIP_FLEXES = 0x00000400,
	STUDIO_DONOTMODIFYSTENCILSTATE = 0x00000800,
	// Not a studio flag, but used to flag model as a non-sorting brush model
	STUDIO_TRANSPARENCY = 0x80000000,
	// Not a studio flag, but used to flag model as using shadow depth material override
	STUDIO_SHADOWDEPTHTEXTURE = 0x40000000,
	// Not a studio flag, but used to flag model as doing custom rendering into shadow texture
	STUDIO_SHADOWTEXTURE = 0x20000000,
	STUDIO_SKIP_DECALS = 0x10000000,
};

class CollisionProperty
{
public:
	CNETVAR_FUNC(Vector, GetMins, 0xF6F78BAB);//m_vecMins
	CNETVAR_FUNC(Vector, GetMaxs, 0xE47C6FC4);//m_vecMaxs
	CNETVAR_FUNC(unsigned char, GetSolidType, 0xB86722A1);//m_nSolidType
	CNETVAR_FUNC(unsigned short, GetSolidFlags, 0x63BB24C1);//m_usSolidFlags
	CNETVAR_FUNC(int, GetSurroundsType, 0xB677A0BB); //m_nSurroundType


	const Vector& OBBMins() {
		typedef Vector&(__thiscall *OrigFn)(void*);
		return call_vfunc<OrigFn>(this, 1)(this);
	}
	const Vector& OBBMaxs() {
		typedef Vector&(__thiscall *OrigFn)(void*);
		return call_vfunc<OrigFn>(this, 2)(this);
	}

	bool IsSolid()
	{
		return (GetSolidType() != SOLID_NONE) && ((GetSolidFlags() & FSOLID_NOT_SOLID) == 0);
	}
};


template <typename Fn> __forceinline Fn CallVMTFunction(void* pClassBase, int nFunctionIndex)
{
	return (Fn)((PDWORD)*(PDWORD*)pClassBase)[nFunctionIndex];
}

class IClientRenderable
{
public:
	//virtual void*					GetIClientUnknown() = 0;
	virtual Vector const&			GetRenderOrigin(void) = 0;
	virtual Vector const&			GetRenderAngles(void) = 0;
	virtual bool					ShouldDraw(void) = 0;
	virtual bool					IsTransparent(void) = 0;
	virtual bool					UsesPowerOfTwoFrameBufferTexture() = 0;
	virtual bool					UsesFullFrameBufferTexture() = 0;
	virtual void					GetShadowHandle() const = 0;
	virtual void*					RenderHandle() = 0;
	virtual const model_t*				GetModel() const = 0;
	virtual int						DrawModel(int flags) = 0;
	virtual int						GetBody() = 0;
	virtual void					ComputeFxBlend() = 0;



	bool SetupBones(matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		typedef bool(__thiscall* oSetupBones)(PVOID, matrix3x4*, int, int, float);
		return call_vfunc< oSetupBones>(this, 13)(this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}
};

class IClientNetworkable
{
public:
	virtual IClientUnknown*	GetIClientUnknown() = 0;
	virtual void			Release() = 0;
	virtual ClientClass*	GetClientClass() = 0;// FOR NETVARS FIND YOURSELF ClientClass* stuffs
	virtual void			NotifyShouldTransmit( /* ShouldTransmitState_t state*/) = 0;
	virtual void			OnPreDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			OnDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PreDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PostDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			unknown();
	virtual bool			IsDormant(void) = 0;
	virtual int				GetIndex(void) const = 0;
	virtual void			ReceiveMessage(int classID /*, bf_read &msg*/) = 0;
	virtual void*			GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

class IClientUnknown
{
public:
	virtual void*		GetCollideable() = 0;
	virtual IClientNetworkable*	GetClientNetworkable() = 0;
	virtual IClientRenderable*	GetClientRenderable() = 0;
	virtual IClientEntity*		GetIClientEntity() = 0;
	virtual IClientEntity*		GetBaseEntity() = 0;
	virtual IClientThinkable*	GetClientThinkable() = 0;
};

class IClientThinkable
{
public:
	virtual IClientUnknown*		GetIClientUnknown() = 0;
	virtual void				ClientThink() = 0;
	virtual void*				GetThinkHandle() = 0;
	virtual void				SetThinkHandle(void* hThink) = 0;
	virtual void				Release() = 0;
};

#define VirtualFn( cast )typedef cast( __thiscall* OriginalFn )

typedef float VMatrix[3][4];

class C_AnimationLayer
{
public:
	char  pad_0000[20];
	uint32_t m_nOrder; //0x0014
	uint32_t m_nSequence; //0x0018
	float_t m_flPrevCycle; //0x001C
	float_t m_flWeight; //0x0020
	float_t m_flWeightDeltaRate; //0x0024
	float_t m_flPlaybackRate; //0x0028
	float_t m_flCycle; //0x002C
	void *m_pOwner; //0x0030 // player's thisptr
	char  pad_0038[4]; //0x0034
}; //Size: 0x0038



typedef enum
{
	ACT_INVALID = -1,			// So we have something more succint to check for than '-1'
	ACT_RESET = 0,				// Set m_Activity to this invalid value to force a reset to m_IdealActivity
	ACT_IDLE,
	ACT_TRANSITION,
	ACT_COVER,					// FIXME: obsolete? redundant with ACT_COVER_LOW?
	ACT_COVER_MED,				// FIXME: unsupported?
	ACT_COVER_LOW,				// FIXME: rename ACT_IDLE_CROUCH?
	ACT_WALK,
	ACT_WALK_AIM,
	ACT_WALK_CROUCH,
	ACT_WALK_CROUCH_AIM,
	ACT_RUN,
	ACT_RUN_AIM,
	ACT_RUN_CROUCH,
	ACT_RUN_CROUCH_AIM,
	ACT_RUN_PROTECTED,
	ACT_SCRIPT_CUSTOM_MOVE,
	ACT_RANGE_ATTACK1,
	ACT_RANGE_ATTACK2,
	ACT_RANGE_ATTACK1_LOW,		// FIXME: not used yet, crouched versions of the range attack
	ACT_RANGE_ATTACK2_LOW,		// FIXME: not used yet, crouched versions of the range attack
	ACT_DIESIMPLE,
	ACT_DIEBACKWARD,
	ACT_DIEFORWARD,
	ACT_DIEVIOLENT,
	ACT_DIERAGDOLL,
	ACT_FLY,				// Fly (and flap if appropriate)
	ACT_HOVER,
	ACT_GLIDE,
	ACT_SWIM,
	ACT_JUMP,
	ACT_HOP,				// vertical jump
	ACT_LEAP,				// long forward jump
	ACT_LAND,
	ACT_CLIMB_UP,
	ACT_CLIMB_DOWN,
	ACT_CLIMB_DISMOUNT,
	ACT_SHIPLADDER_UP,
	ACT_SHIPLADDER_DOWN,
	ACT_STRAFE_LEFT,
	ACT_STRAFE_RIGHT,
	ACT_ROLL_LEFT,			// tuck and roll, left
	ACT_ROLL_RIGHT,			// tuck and roll, right
	ACT_TURN_LEFT,			// turn quickly left (stationary)
	ACT_TURN_RIGHT,			// turn quickly right (stationary)
	ACT_CROUCH,				// FIXME: obsolete? only used be soldier (the act of crouching down from a standing position)
	ACT_CROUCHIDLE,			// FIXME: obsolete? only used be soldier (holding body in crouched position (loops))
	ACT_STAND,				// FIXME: obsolete? should be transition (the act of standing from a crouched position)
	ACT_USE,
	ACT_ALIEN_BURROW_IDLE,
	ACT_ALIEN_BURROW_OUT,

	ACT_SIGNAL1,
	ACT_SIGNAL2,
	ACT_SIGNAL3,

	ACT_SIGNAL_ADVANCE,		// Squad handsignals, specific.
	ACT_SIGNAL_FORWARD,
	ACT_SIGNAL_GROUP,
	ACT_SIGNAL_HALT,
	ACT_SIGNAL_LEFT,
	ACT_SIGNAL_RIGHT,
	ACT_SIGNAL_TAKECOVER,

	ACT_LOOKBACK_RIGHT,		// look back over shoulder without turning around.
	ACT_LOOKBACK_LEFT,
	ACT_COWER,				// FIXME: unused, should be more extreme version of crouching
	ACT_SMALL_FLINCH,		// FIXME: needed? shouldn't flinching be down with overlays?
	ACT_BIG_FLINCH,
	ACT_MELEE_ATTACK1,
	ACT_MELEE_ATTACK2,
	ACT_RELOAD,
	ACT_RELOAD_START,
	ACT_RELOAD_FINISH,
	ACT_RELOAD_LOW,
	ACT_ARM,				// pull out gun, for instance
	ACT_DISARM,				// reholster gun
	ACT_DROP_WEAPON,
	ACT_DROP_WEAPON_SHOTGUN,
	ACT_PICKUP_GROUND,		// pick up something in front of you on the ground
	ACT_PICKUP_RACK,		// pick up something from a rack or shelf in front of you.
	ACT_IDLE_ANGRY,			// FIXME: being used as an combat ready idle?  alternate idle animation in which the monster is clearly agitated. (loop)

	ACT_IDLE_RELAXED,
	ACT_IDLE_STIMULATED,
	ACT_IDLE_AGITATED,
	ACT_IDLE_STEALTH,
	ACT_IDLE_HURT,

	ACT_WALK_RELAXED,
	ACT_WALK_STIMULATED,
	ACT_WALK_AGITATED,
	ACT_WALK_STEALTH,

	ACT_RUN_RELAXED,
	ACT_RUN_STIMULATED,
	ACT_RUN_AGITATED,
	ACT_RUN_STEALTH,

	ACT_IDLE_AIM_RELAXED,
	ACT_IDLE_AIM_STIMULATED,
	ACT_IDLE_AIM_AGITATED,
	ACT_IDLE_AIM_STEALTH,

	ACT_WALK_AIM_RELAXED,
	ACT_WALK_AIM_STIMULATED,
	ACT_WALK_AIM_AGITATED,
	ACT_WALK_AIM_STEALTH,

	ACT_RUN_AIM_RELAXED,
	ACT_RUN_AIM_STIMULATED,
	ACT_RUN_AIM_AGITATED,
	ACT_RUN_AIM_STEALTH,

	ACT_CROUCHIDLE_STIMULATED,
	ACT_CROUCHIDLE_AIM_STIMULATED,
	ACT_CROUCHIDLE_AGITATED,

	ACT_WALK_HURT,			// limp  (loop)
	ACT_RUN_HURT,			// limp  (loop)
	ACT_SPECIAL_ATTACK1,	// very monster specific special attacks.
	ACT_SPECIAL_ATTACK2,
	ACT_COMBAT_IDLE,		// FIXME: unused?  agitated idle.
	ACT_WALK_SCARED,
	ACT_RUN_SCARED,
	ACT_VICTORY_DANCE,		// killed a player, do a victory dance.
	ACT_DIE_HEADSHOT,		// die, hit in head. 
	ACT_DIE_CHESTSHOT,		// die, hit in chest
	ACT_DIE_GUTSHOT,		// die, hit in gut
	ACT_DIE_BACKSHOT,		// die, hit in back
	ACT_FLINCH_HEAD,
	ACT_FLINCH_CHEST,
	ACT_FLINCH_STOMACH,
	ACT_FLINCH_LEFTARM,
	ACT_FLINCH_RIGHTARM,
	ACT_FLINCH_LEFTLEG,
	ACT_FLINCH_RIGHTLEG,
	ACT_FLINCH_PHYSICS,
	ACT_FLINCH_HEAD_BACK,
	ACT_FLINCH_CHEST_BACK,
	ACT_FLINCH_STOMACH_BACK,
	ACT_FLINCH_CROUCH_FRONT,
	ACT_FLINCH_CROUCH_BACK,
	ACT_FLINCH_CROUCH_LEFT,
	ACT_FLINCH_CROUCH_RIGHT,

	ACT_IDLE_ON_FIRE,		// ON FIRE animations
	ACT_WALK_ON_FIRE,
	ACT_RUN_ON_FIRE,

	ACT_RAPPEL_LOOP,		// Rappel down a rope!

	ACT_180_LEFT,			// 180 degree left turn
	ACT_180_RIGHT,

	ACT_90_LEFT,			// 90 degree turns
	ACT_90_RIGHT,

	ACT_STEP_LEFT,			// Single steps
	ACT_STEP_RIGHT,
	ACT_STEP_BACK,
	ACT_STEP_FORE,

	ACT_GESTURE_RANGE_ATTACK1,
	ACT_GESTURE_RANGE_ATTACK2,
	ACT_GESTURE_MELEE_ATTACK1,
	ACT_GESTURE_MELEE_ATTACK2,
	ACT_GESTURE_RANGE_ATTACK1_LOW,	// FIXME: not used yet, crouched versions of the range attack
	ACT_GESTURE_RANGE_ATTACK2_LOW,	// FIXME: not used yet, crouched versions of the range attack

	ACT_MELEE_ATTACK_SWING_GESTURE,

	ACT_GESTURE_SMALL_FLINCH,
	ACT_GESTURE_BIG_FLINCH,
	ACT_GESTURE_FLINCH_BLAST,			// Startled by an explosion
	ACT_GESTURE_FLINCH_BLAST_SHOTGUN,
	ACT_GESTURE_FLINCH_BLAST_DAMAGED,	// Damaged by an explosion
	ACT_GESTURE_FLINCH_BLAST_DAMAGED_SHOTGUN,
	ACT_GESTURE_FLINCH_HEAD,
	ACT_GESTURE_FLINCH_CHEST,
	ACT_GESTURE_FLINCH_STOMACH,
	ACT_GESTURE_FLINCH_LEFTARM,
	ACT_GESTURE_FLINCH_RIGHTARM,
	ACT_GESTURE_FLINCH_LEFTLEG,
	ACT_GESTURE_FLINCH_RIGHTLEG,

	ACT_GESTURE_TURN_LEFT,
	ACT_GESTURE_TURN_RIGHT,
	ACT_GESTURE_TURN_LEFT45,
	ACT_GESTURE_TURN_RIGHT45,
	ACT_GESTURE_TURN_LEFT90,
	ACT_GESTURE_TURN_RIGHT90,
	ACT_GESTURE_TURN_LEFT45_FLAT,
	ACT_GESTURE_TURN_RIGHT45_FLAT,
	ACT_GESTURE_TURN_LEFT90_FLAT,
	ACT_GESTURE_TURN_RIGHT90_FLAT,

	// HALF-LIFE 1 compatability stuff goes here. Temporary!
	ACT_BARNACLE_HIT,		// barnacle tongue hits a monster
	ACT_BARNACLE_PULL,		// barnacle is lifting the monster ( loop )
	ACT_BARNACLE_CHOMP,		// barnacle latches on to the monster
	ACT_BARNACLE_CHEW,		// barnacle is holding the monster in its mouth ( loop )

							// Sometimes, you just want to set an NPC's sequence to a sequence that doesn't actually
							// have an activity. The AI will reset the NPC's sequence to whatever its IDEAL activity
							// is, though. So if you set ideal activity to DO_NOT_DISTURB, the AI will not interfere
							// with the NPC's current sequence. (SJB)
							ACT_DO_NOT_DISTURB,

							ACT_SPECIFIC_SEQUENCE,

							// viewmodel (weapon) activities
							// FIXME: move these to the specific viewmodels, no need to make global
							ACT_VM_DRAW,
							ACT_VM_HOLSTER,
							ACT_VM_IDLE,
							ACT_VM_FIDGET,
							ACT_VM_PULLBACK,
							ACT_VM_PULLBACK_HIGH,
							ACT_VM_PULLBACK_LOW,
							ACT_VM_THROW,
							ACT_VM_PULLPIN,
							ACT_VM_PRIMARYATTACK,		// fire
							ACT_VM_SECONDARYATTACK,		// alt. fire
							ACT_VM_RELOAD,
							ACT_VM_DRYFIRE,				// fire with no ammo loaded.
							ACT_VM_HITLEFT,				// bludgeon, swing to left - hit (primary attk)
							ACT_VM_HITLEFT2,			// bludgeon, swing to left - hit (secondary attk)
							ACT_VM_HITRIGHT,			// bludgeon, swing to right - hit (primary attk)
							ACT_VM_HITRIGHT2,			// bludgeon, swing to right - hit (secondary attk)
							ACT_VM_HITCENTER,			// bludgeon, swing center - hit (primary attk)
							ACT_VM_HITCENTER2,			// bludgeon, swing center - hit (secondary attk)
							ACT_VM_MISSLEFT,			// bludgeon, swing to left - miss (primary attk)
							ACT_VM_MISSLEFT2,			// bludgeon, swing to left - miss (secondary attk)
							ACT_VM_MISSRIGHT,			// bludgeon, swing to right - miss (primary attk)
							ACT_VM_MISSRIGHT2,			// bludgeon, swing to right - miss (secondary attk)
							ACT_VM_MISSCENTER,			// bludgeon, swing center - miss (primary attk)
							ACT_VM_MISSCENTER2,			// bludgeon, swing center - miss (secondary attk)
							ACT_VM_HAULBACK,			// bludgeon, haul the weapon back for a hard strike (secondary attk)
							ACT_VM_SWINGHARD,			// bludgeon, release the hard strike (secondary attk)
							ACT_VM_SWINGMISS,
							ACT_VM_SWINGHIT,
							ACT_VM_IDLE_TO_LOWERED,
							ACT_VM_IDLE_LOWERED,
							ACT_VM_LOWERED_TO_IDLE,
							ACT_VM_RECOIL1,
							ACT_VM_RECOIL2,
							ACT_VM_RECOIL3,
							ACT_VM_PICKUP,
							ACT_VM_RELEASE,

							ACT_VM_ATTACH_SILENCER,
							ACT_VM_DETACH_SILENCER,

							//===========================
							// HL2 Specific Activities
							//===========================
							// SLAM	Specialty Activities
							ACT_SLAM_STICKWALL_IDLE,
							ACT_SLAM_STICKWALL_ND_IDLE,
							ACT_SLAM_STICKWALL_ATTACH,
							ACT_SLAM_STICKWALL_ATTACH2,
							ACT_SLAM_STICKWALL_ND_ATTACH,
							ACT_SLAM_STICKWALL_ND_ATTACH2,
							ACT_SLAM_STICKWALL_DETONATE,
							ACT_SLAM_STICKWALL_DETONATOR_HOLSTER,
							ACT_SLAM_STICKWALL_DRAW,
							ACT_SLAM_STICKWALL_ND_DRAW,
							ACT_SLAM_STICKWALL_TO_THROW,
							ACT_SLAM_STICKWALL_TO_THROW_ND,
							ACT_SLAM_STICKWALL_TO_TRIPMINE_ND,
							ACT_SLAM_THROW_IDLE,
							ACT_SLAM_THROW_ND_IDLE,
							ACT_SLAM_THROW_THROW,
							ACT_SLAM_THROW_THROW2,
							ACT_SLAM_THROW_THROW_ND,
							ACT_SLAM_THROW_THROW_ND2,
							ACT_SLAM_THROW_DRAW,
							ACT_SLAM_THROW_ND_DRAW,
							ACT_SLAM_THROW_TO_STICKWALL,
							ACT_SLAM_THROW_TO_STICKWALL_ND,
							ACT_SLAM_THROW_DETONATE,
							ACT_SLAM_THROW_DETONATOR_HOLSTER,
							ACT_SLAM_THROW_TO_TRIPMINE_ND,
							ACT_SLAM_TRIPMINE_IDLE,
							ACT_SLAM_TRIPMINE_DRAW,
							ACT_SLAM_TRIPMINE_ATTACH,
							ACT_SLAM_TRIPMINE_ATTACH2,
							ACT_SLAM_TRIPMINE_TO_STICKWALL_ND,
							ACT_SLAM_TRIPMINE_TO_THROW_ND,
							ACT_SLAM_DETONATOR_IDLE,
							ACT_SLAM_DETONATOR_DRAW,
							ACT_SLAM_DETONATOR_DETONATE,
							ACT_SLAM_DETONATOR_HOLSTER,
							ACT_SLAM_DETONATOR_STICKWALL_DRAW,
							ACT_SLAM_DETONATOR_THROW_DRAW,

							// Shotgun Specialty Activities
							ACT_SHOTGUN_RELOAD_START,
							ACT_SHOTGUN_RELOAD_FINISH,
							ACT_SHOTGUN_PUMP,

							// SMG2 special activities
							ACT_SMG2_IDLE2,
							ACT_SMG2_FIRE2,
							ACT_SMG2_DRAW2,
							ACT_SMG2_RELOAD2,
							ACT_SMG2_DRYFIRE2,
							ACT_SMG2_TOAUTO,
							ACT_SMG2_TOBURST,

							// Physcannon special activities
							ACT_PHYSCANNON_UPGRADE,

							// weapon override activities
							ACT_RANGE_ATTACK_AR1,
							ACT_RANGE_ATTACK_AR2,
							ACT_RANGE_ATTACK_AR2_LOW,
							ACT_RANGE_ATTACK_AR2_GRENADE,
							ACT_RANGE_ATTACK_HMG1,
							ACT_RANGE_ATTACK_ML,
							ACT_RANGE_ATTACK_SMG1,
							ACT_RANGE_ATTACK_SMG1_LOW,
							ACT_RANGE_ATTACK_SMG2,
							ACT_RANGE_ATTACK_SHOTGUN,
							ACT_RANGE_ATTACK_SHOTGUN_LOW,
							ACT_RANGE_ATTACK_PISTOL,
							ACT_RANGE_ATTACK_PISTOL_LOW,
							ACT_RANGE_ATTACK_SLAM,
							ACT_RANGE_ATTACK_TRIPWIRE,
							ACT_RANGE_ATTACK_THROW,
							ACT_RANGE_ATTACK_SNIPER_RIFLE,
							ACT_RANGE_ATTACK_RPG,
							ACT_MELEE_ATTACK_SWING,

							ACT_RANGE_AIM_LOW,
							ACT_RANGE_AIM_SMG1_LOW,
							ACT_RANGE_AIM_PISTOL_LOW,
							ACT_RANGE_AIM_AR2_LOW,

							ACT_COVER_PISTOL_LOW,
							ACT_COVER_SMG1_LOW,

							// weapon override activities
							ACT_GESTURE_RANGE_ATTACK_AR1,
							ACT_GESTURE_RANGE_ATTACK_AR2,
							ACT_GESTURE_RANGE_ATTACK_AR2_GRENADE,
							ACT_GESTURE_RANGE_ATTACK_HMG1,
							ACT_GESTURE_RANGE_ATTACK_ML,
							ACT_GESTURE_RANGE_ATTACK_SMG1,
							ACT_GESTURE_RANGE_ATTACK_SMG1_LOW,
							ACT_GESTURE_RANGE_ATTACK_SMG2,
							ACT_GESTURE_RANGE_ATTACK_SHOTGUN,
							ACT_GESTURE_RANGE_ATTACK_PISTOL,
							ACT_GESTURE_RANGE_ATTACK_PISTOL_LOW,
							ACT_GESTURE_RANGE_ATTACK_SLAM,
							ACT_GESTURE_RANGE_ATTACK_TRIPWIRE,
							ACT_GESTURE_RANGE_ATTACK_THROW,
							ACT_GESTURE_RANGE_ATTACK_SNIPER_RIFLE,
							ACT_GESTURE_MELEE_ATTACK_SWING,

							ACT_IDLE_RIFLE,
							ACT_IDLE_SMG1,
							ACT_IDLE_ANGRY_SMG1,
							ACT_IDLE_PISTOL,
							ACT_IDLE_ANGRY_PISTOL,
							ACT_IDLE_ANGRY_SHOTGUN,
							ACT_IDLE_STEALTH_PISTOL,

							ACT_IDLE_PACKAGE,
							ACT_WALK_PACKAGE,
							ACT_IDLE_SUITCASE,
							ACT_WALK_SUITCASE,

							ACT_IDLE_SMG1_RELAXED,
							ACT_IDLE_SMG1_STIMULATED,
							ACT_WALK_RIFLE_RELAXED,
							ACT_RUN_RIFLE_RELAXED,
							ACT_WALK_RIFLE_STIMULATED,
							ACT_RUN_RIFLE_STIMULATED,

							ACT_IDLE_AIM_RIFLE_STIMULATED,
							ACT_WALK_AIM_RIFLE_STIMULATED,
							ACT_RUN_AIM_RIFLE_STIMULATED,

							ACT_IDLE_SHOTGUN_RELAXED,
							ACT_IDLE_SHOTGUN_STIMULATED,
							ACT_IDLE_SHOTGUN_AGITATED,

							// Policing activities
							ACT_WALK_ANGRY,
							ACT_POLICE_HARASS1,
							ACT_POLICE_HARASS2,

							// Manned guns
							ACT_IDLE_MANNEDGUN,

							// Melee weapon
							ACT_IDLE_MELEE,
							ACT_IDLE_ANGRY_MELEE,

							// RPG activities
							ACT_IDLE_RPG_RELAXED,
							ACT_IDLE_RPG,
							ACT_IDLE_ANGRY_RPG,
							ACT_COVER_LOW_RPG,
							ACT_WALK_RPG,
							ACT_RUN_RPG,
							ACT_WALK_CROUCH_RPG,
							ACT_RUN_CROUCH_RPG,
							ACT_WALK_RPG_RELAXED,
							ACT_RUN_RPG_RELAXED,

							ACT_WALK_RIFLE,
							ACT_WALK_AIM_RIFLE,
							ACT_WALK_CROUCH_RIFLE,
							ACT_WALK_CROUCH_AIM_RIFLE,
							ACT_RUN_RIFLE,
							ACT_RUN_AIM_RIFLE,
							ACT_RUN_CROUCH_RIFLE,
							ACT_RUN_CROUCH_AIM_RIFLE,
							ACT_RUN_STEALTH_PISTOL,

							ACT_WALK_AIM_SHOTGUN,
							ACT_RUN_AIM_SHOTGUN,

							ACT_WALK_PISTOL,
							ACT_RUN_PISTOL,
							ACT_WALK_AIM_PISTOL,
							ACT_RUN_AIM_PISTOL,
							ACT_WALK_STEALTH_PISTOL,
							ACT_WALK_AIM_STEALTH_PISTOL,
							ACT_RUN_AIM_STEALTH_PISTOL,

							// Reloads
							ACT_RELOAD_PISTOL,
							ACT_RELOAD_PISTOL_LOW,
							ACT_RELOAD_SMG1,
							ACT_RELOAD_SMG1_LOW,
							ACT_RELOAD_SHOTGUN,
							ACT_RELOAD_SHOTGUN_LOW,

							ACT_GESTURE_RELOAD,
							ACT_GESTURE_RELOAD_PISTOL,
							ACT_GESTURE_RELOAD_SMG1,
							ACT_GESTURE_RELOAD_SHOTGUN,

							// Busy animations
							ACT_BUSY_LEAN_LEFT,
							ACT_BUSY_LEAN_LEFT_ENTRY,
							ACT_BUSY_LEAN_LEFT_EXIT,
							ACT_BUSY_LEAN_BACK,
							ACT_BUSY_LEAN_BACK_ENTRY,
							ACT_BUSY_LEAN_BACK_EXIT,
							ACT_BUSY_SIT_GROUND,
							ACT_BUSY_SIT_GROUND_ENTRY,
							ACT_BUSY_SIT_GROUND_EXIT,
							ACT_BUSY_SIT_CHAIR,
							ACT_BUSY_SIT_CHAIR_ENTRY,
							ACT_BUSY_SIT_CHAIR_EXIT,
							ACT_BUSY_STAND,
							ACT_BUSY_QUEUE,

							// Dodge animations
							ACT_DUCK_DODGE,

							// For NPCs being lifted/eaten by barnacles:
							// being swallowed by a barnacle
							ACT_DIE_BARNACLE_SWALLOW,
							// being lifted by a barnacle
							ACT_GESTURE_BARNACLE_STRANGLE,

							ACT_PHYSCANNON_DETACH,	// An activity to be played if we're picking this up with the physcannon
							ACT_PHYSCANNON_ANIMATE, // An activity to be played by an object being picked up with the physcannon, but has different behavior to DETACH
							ACT_PHYSCANNON_ANIMATE_PRE,	// An activity to be played by an object being picked up with the physcannon, before playing the ACT_PHYSCANNON_ANIMATE
							ACT_PHYSCANNON_ANIMATE_POST,// An activity to be played by an object being picked up with the physcannon, after playing the ACT_PHYSCANNON_ANIMATE

							ACT_DIE_FRONTSIDE,
							ACT_DIE_RIGHTSIDE,
							ACT_DIE_BACKSIDE,
							ACT_DIE_LEFTSIDE,

							ACT_OPEN_DOOR,

							// Dynamic interactions
							ACT_DI_ALYX_ZOMBIE_MELEE,
							ACT_DI_ALYX_ZOMBIE_TORSO_MELEE,
							ACT_DI_ALYX_HEADCRAB_MELEE,
							ACT_DI_ALYX_ANTLION,

							ACT_DI_ALYX_ZOMBIE_SHOTGUN64,
							ACT_DI_ALYX_ZOMBIE_SHOTGUN26,

							ACT_READINESS_RELAXED_TO_STIMULATED,
							ACT_READINESS_RELAXED_TO_STIMULATED_WALK,
							ACT_READINESS_AGITATED_TO_STIMULATED,
							ACT_READINESS_STIMULATED_TO_RELAXED,

							ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED,
							ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED_WALK,
							ACT_READINESS_PISTOL_AGITATED_TO_STIMULATED,
							ACT_READINESS_PISTOL_STIMULATED_TO_RELAXED,

							ACT_IDLE_CARRY,
							ACT_WALK_CARRY,

							//===========================
							// TF2 Specific Activities
							//===========================
							ACT_STARTDYING,
							ACT_DYINGLOOP,
							ACT_DYINGTODEAD,

							ACT_RIDE_MANNED_GUN,

							// All viewmodels
							ACT_VM_SPRINT_ENTER,
							ACT_VM_SPRINT_IDLE,
							ACT_VM_SPRINT_LEAVE,

							// Looping weapon firing
							ACT_FIRE_START,
							ACT_FIRE_LOOP,
							ACT_FIRE_END,

							ACT_CROUCHING_GRENADEIDLE,
							ACT_CROUCHING_GRENADEREADY,
							ACT_CROUCHING_PRIMARYATTACK,
							ACT_OVERLAY_GRENADEIDLE,
							ACT_OVERLAY_GRENADEREADY,
							ACT_OVERLAY_PRIMARYATTACK,
							ACT_OVERLAY_SHIELD_UP,
							ACT_OVERLAY_SHIELD_DOWN,
							ACT_OVERLAY_SHIELD_UP_IDLE,
							ACT_OVERLAY_SHIELD_ATTACK,
							ACT_OVERLAY_SHIELD_KNOCKBACK,
							ACT_SHIELD_UP,
							ACT_SHIELD_DOWN,
							ACT_SHIELD_UP_IDLE,
							ACT_SHIELD_ATTACK,
							ACT_SHIELD_KNOCKBACK,
							ACT_CROUCHING_SHIELD_UP,
							ACT_CROUCHING_SHIELD_DOWN,
							ACT_CROUCHING_SHIELD_UP_IDLE,
							ACT_CROUCHING_SHIELD_ATTACK,
							ACT_CROUCHING_SHIELD_KNOCKBACK,

							// turning in place
							ACT_TURNRIGHT45,
							ACT_TURNLEFT45,

							ACT_TURN,

							ACT_OBJ_ASSEMBLING,
							ACT_OBJ_DISMANTLING,
							ACT_OBJ_STARTUP,
							ACT_OBJ_RUNNING,
							ACT_OBJ_IDLE,
							ACT_OBJ_PLACING,
							ACT_OBJ_DETERIORATING,
							ACT_OBJ_UPGRADING,

							// Deploy
							ACT_DEPLOY,
							ACT_DEPLOY_IDLE,
							ACT_UNDEPLOY,

							// Crossbow
							ACT_CROSSBOW_DRAW_UNLOADED,

							// Gauss
							ACT_GAUSS_SPINUP,
							ACT_GAUSS_SPINCYCLE,

							//===========================
							// CSPort Specific Activities
							//===========================

							ACT_VM_PRIMARYATTACK_SILENCED,		// fire
							ACT_VM_RELOAD_SILENCED,
							ACT_VM_DRYFIRE_SILENCED,				// fire with no ammo loaded.
							ACT_VM_IDLE_SILENCED,
							ACT_VM_DRAW_SILENCED,
							ACT_VM_IDLE_EMPTY_LEFT,
							ACT_VM_DRYFIRE_LEFT,

							// new for CS2
							ACT_VM_IS_DRAW,
							ACT_VM_IS_HOLSTER,
							ACT_VM_IS_IDLE,
							ACT_VM_IS_PRIMARYATTACK,

							ACT_PLAYER_IDLE_FIRE,
							ACT_PLAYER_CROUCH_FIRE,
							ACT_PLAYER_CROUCH_WALK_FIRE,
							ACT_PLAYER_WALK_FIRE,
							ACT_PLAYER_RUN_FIRE,

							ACT_IDLETORUN,
							ACT_RUNTOIDLE,

							ACT_VM_DRAW_DEPLOYED,

							ACT_HL2MP_IDLE_MELEE,
							ACT_HL2MP_RUN_MELEE,
							ACT_HL2MP_IDLE_CROUCH_MELEE,
							ACT_HL2MP_WALK_CROUCH_MELEE,
							ACT_HL2MP_GESTURE_RANGE_ATTACK_MELEE,
							ACT_HL2MP_GESTURE_RELOAD_MELEE,
							ACT_HL2MP_JUMP_MELEE,

							// Portal!
							ACT_VM_FIZZLE,

							// Multiplayer
							ACT_MP_STAND_IDLE,
							ACT_MP_CROUCH_IDLE,
							ACT_MP_CROUCH_DEPLOYED_IDLE,
							ACT_MP_CROUCH_DEPLOYED,
							ACT_MP_DEPLOYED_IDLE,
							ACT_MP_RUN,
							ACT_MP_WALK,
							ACT_MP_AIRWALK,
							ACT_MP_CROUCHWALK,
							ACT_MP_SPRINT,
							ACT_MP_JUMP,
							ACT_MP_JUMP_START,
							ACT_MP_JUMP_FLOAT,
							ACT_MP_JUMP_LAND,
							ACT_MP_DOUBLEJUMP,
							ACT_MP_SWIM,
							ACT_MP_DEPLOYED,
							ACT_MP_SWIM_DEPLOYED,
							ACT_MP_VCD,

							ACT_MP_ATTACK_STAND_PRIMARYFIRE,
							ACT_MP_ATTACK_STAND_PRIMARYFIRE_DEPLOYED,
							ACT_MP_ATTACK_STAND_SECONDARYFIRE,
							ACT_MP_ATTACK_STAND_GRENADE,
							ACT_MP_ATTACK_CROUCH_PRIMARYFIRE,
							ACT_MP_ATTACK_CROUCH_PRIMARYFIRE_DEPLOYED,
							ACT_MP_ATTACK_CROUCH_SECONDARYFIRE,
							ACT_MP_ATTACK_CROUCH_GRENADE,
							ACT_MP_ATTACK_SWIM_PRIMARYFIRE,
							ACT_MP_ATTACK_SWIM_SECONDARYFIRE,
							ACT_MP_ATTACK_SWIM_GRENADE,
							ACT_MP_ATTACK_AIRWALK_PRIMARYFIRE,
							ACT_MP_ATTACK_AIRWALK_SECONDARYFIRE,
							ACT_MP_ATTACK_AIRWALK_GRENADE,
							ACT_MP_RELOAD_STAND,
							ACT_MP_RELOAD_STAND_LOOP,
							ACT_MP_RELOAD_STAND_END,
							ACT_MP_RELOAD_CROUCH,
							ACT_MP_RELOAD_CROUCH_LOOP,
							ACT_MP_RELOAD_CROUCH_END,
							ACT_MP_RELOAD_SWIM,
							ACT_MP_RELOAD_SWIM_LOOP,
							ACT_MP_RELOAD_SWIM_END,
							ACT_MP_RELOAD_AIRWALK,
							ACT_MP_RELOAD_AIRWALK_LOOP,
							ACT_MP_RELOAD_AIRWALK_END,
							ACT_MP_ATTACK_STAND_PREFIRE,
							ACT_MP_ATTACK_STAND_POSTFIRE,
							ACT_MP_ATTACK_STAND_STARTFIRE,
							ACT_MP_ATTACK_CROUCH_PREFIRE,
							ACT_MP_ATTACK_CROUCH_POSTFIRE,
							ACT_MP_ATTACK_SWIM_PREFIRE,
							ACT_MP_ATTACK_SWIM_POSTFIRE,

							// Multiplayer - Primary
							ACT_MP_STAND_PRIMARY,
							ACT_MP_CROUCH_PRIMARY,
							ACT_MP_RUN_PRIMARY,
							ACT_MP_WALK_PRIMARY,
							ACT_MP_AIRWALK_PRIMARY,
							ACT_MP_CROUCHWALK_PRIMARY,
							ACT_MP_JUMP_PRIMARY,
							ACT_MP_JUMP_START_PRIMARY,
							ACT_MP_JUMP_FLOAT_PRIMARY,
							ACT_MP_JUMP_LAND_PRIMARY,
							ACT_MP_SWIM_PRIMARY,
							ACT_MP_DEPLOYED_PRIMARY,
							ACT_MP_SWIM_DEPLOYED_PRIMARY,

							ACT_MP_ATTACK_STAND_PRIMARY,		// RUN, WALK
							ACT_MP_ATTACK_STAND_PRIMARY_DEPLOYED,
							ACT_MP_ATTACK_CROUCH_PRIMARY,		// CROUCHWALK
							ACT_MP_ATTACK_CROUCH_PRIMARY_DEPLOYED,
							ACT_MP_ATTACK_SWIM_PRIMARY,
							ACT_MP_ATTACK_AIRWALK_PRIMARY,

							ACT_MP_RELOAD_STAND_PRIMARY,		// RUN, WALK
							ACT_MP_RELOAD_STAND_PRIMARY_LOOP,
							ACT_MP_RELOAD_STAND_PRIMARY_END,
							ACT_MP_RELOAD_CROUCH_PRIMARY,		// CROUCHWALK
							ACT_MP_RELOAD_CROUCH_PRIMARY_LOOP,
							ACT_MP_RELOAD_CROUCH_PRIMARY_END,
							ACT_MP_RELOAD_SWIM_PRIMARY,
							ACT_MP_RELOAD_SWIM_PRIMARY_LOOP,
							ACT_MP_RELOAD_SWIM_PRIMARY_END,
							ACT_MP_RELOAD_AIRWALK_PRIMARY,
							ACT_MP_RELOAD_AIRWALK_PRIMARY_LOOP,
							ACT_MP_RELOAD_AIRWALK_PRIMARY_END,

							ACT_MP_ATTACK_STAND_GRENADE_PRIMARY,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_GRENADE_PRIMARY,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_GRENADE_PRIMARY,
							ACT_MP_ATTACK_AIRWALK_GRENADE_PRIMARY,

							// Secondary
							ACT_MP_STAND_SECONDARY,
							ACT_MP_CROUCH_SECONDARY,
							ACT_MP_RUN_SECONDARY,
							ACT_MP_WALK_SECONDARY,
							ACT_MP_AIRWALK_SECONDARY,
							ACT_MP_CROUCHWALK_SECONDARY,
							ACT_MP_JUMP_SECONDARY,
							ACT_MP_JUMP_START_SECONDARY,
							ACT_MP_JUMP_FLOAT_SECONDARY,
							ACT_MP_JUMP_LAND_SECONDARY,
							ACT_MP_SWIM_SECONDARY,

							ACT_MP_ATTACK_STAND_SECONDARY,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_SECONDARY,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_SECONDARY,
							ACT_MP_ATTACK_AIRWALK_SECONDARY,

							ACT_MP_RELOAD_STAND_SECONDARY,		// RUN, WALK
							ACT_MP_RELOAD_STAND_SECONDARY_LOOP,
							ACT_MP_RELOAD_STAND_SECONDARY_END,
							ACT_MP_RELOAD_CROUCH_SECONDARY,		// CROUCHWALK
							ACT_MP_RELOAD_CROUCH_SECONDARY_LOOP,
							ACT_MP_RELOAD_CROUCH_SECONDARY_END,
							ACT_MP_RELOAD_SWIM_SECONDARY,
							ACT_MP_RELOAD_SWIM_SECONDARY_LOOP,
							ACT_MP_RELOAD_SWIM_SECONDARY_END,
							ACT_MP_RELOAD_AIRWALK_SECONDARY,
							ACT_MP_RELOAD_AIRWALK_SECONDARY_LOOP,
							ACT_MP_RELOAD_AIRWALK_SECONDARY_END,

							ACT_MP_ATTACK_STAND_GRENADE_SECONDARY,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_GRENADE_SECONDARY,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_GRENADE_SECONDARY,
							ACT_MP_ATTACK_AIRWALK_GRENADE_SECONDARY,

							// Melee
							ACT_MP_STAND_MELEE,
							ACT_MP_CROUCH_MELEE,
							ACT_MP_RUN_MELEE,
							ACT_MP_WALK_MELEE,
							ACT_MP_AIRWALK_MELEE,
							ACT_MP_CROUCHWALK_MELEE,
							ACT_MP_JUMP_MELEE,
							ACT_MP_JUMP_START_MELEE,
							ACT_MP_JUMP_FLOAT_MELEE,
							ACT_MP_JUMP_LAND_MELEE,
							ACT_MP_SWIM_MELEE,

							ACT_MP_ATTACK_STAND_MELEE,		// RUN, WALK
							ACT_MP_ATTACK_STAND_MELEE_SECONDARY,
							ACT_MP_ATTACK_CROUCH_MELEE,		// CROUCHWALK
							ACT_MP_ATTACK_CROUCH_MELEE_SECONDARY,
							ACT_MP_ATTACK_SWIM_MELEE,
							ACT_MP_ATTACK_AIRWALK_MELEE,

							ACT_MP_ATTACK_STAND_GRENADE_MELEE,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_GRENADE_MELEE,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_GRENADE_MELEE,
							ACT_MP_ATTACK_AIRWALK_GRENADE_MELEE,

							// Item1
							ACT_MP_STAND_ITEM1,
							ACT_MP_CROUCH_ITEM1,
							ACT_MP_RUN_ITEM1,
							ACT_MP_WALK_ITEM1,
							ACT_MP_AIRWALK_ITEM1,
							ACT_MP_CROUCHWALK_ITEM1,
							ACT_MP_JUMP_ITEM1,
							ACT_MP_JUMP_START_ITEM1,
							ACT_MP_JUMP_FLOAT_ITEM1,
							ACT_MP_JUMP_LAND_ITEM1,
							ACT_MP_SWIM_ITEM1,

							ACT_MP_ATTACK_STAND_ITEM1,		// RUN, WALK
							ACT_MP_ATTACK_STAND_ITEM1_SECONDARY,
							ACT_MP_ATTACK_CROUCH_ITEM1,		// CROUCHWALK
							ACT_MP_ATTACK_CROUCH_ITEM1_SECONDARY,
							ACT_MP_ATTACK_SWIM_ITEM1,
							ACT_MP_ATTACK_AIRWALK_ITEM1,

							// Item2
							ACT_MP_STAND_ITEM2,
							ACT_MP_CROUCH_ITEM2,
							ACT_MP_RUN_ITEM2,
							ACT_MP_WALK_ITEM2,
							ACT_MP_AIRWALK_ITEM2,
							ACT_MP_CROUCHWALK_ITEM2,
							ACT_MP_JUMP_ITEM2,
							ACT_MP_JUMP_START_ITEM2,
							ACT_MP_JUMP_FLOAT_ITEM2,
							ACT_MP_JUMP_LAND_ITEM2,
							ACT_MP_SWIM_ITEM2,

							ACT_MP_ATTACK_STAND_ITEM2,		// RUN, WALK
							ACT_MP_ATTACK_STAND_ITEM2_SECONDARY,
							ACT_MP_ATTACK_CROUCH_ITEM2,		// CROUCHWALK
							ACT_MP_ATTACK_CROUCH_ITEM2_SECONDARY,
							ACT_MP_ATTACK_SWIM_ITEM2,
							ACT_MP_ATTACK_AIRWALK_ITEM2,

							// Flinches
							ACT_MP_GESTURE_FLINCH,
							ACT_MP_GESTURE_FLINCH_PRIMARY,
							ACT_MP_GESTURE_FLINCH_SECONDARY,
							ACT_MP_GESTURE_FLINCH_MELEE,
							ACT_MP_GESTURE_FLINCH_ITEM1,
							ACT_MP_GESTURE_FLINCH_ITEM2,

							ACT_MP_GESTURE_FLINCH_HEAD,
							ACT_MP_GESTURE_FLINCH_CHEST,
							ACT_MP_GESTURE_FLINCH_STOMACH,
							ACT_MP_GESTURE_FLINCH_LEFTARM,
							ACT_MP_GESTURE_FLINCH_RIGHTARM,
							ACT_MP_GESTURE_FLINCH_LEFTLEG,
							ACT_MP_GESTURE_FLINCH_RIGHTLEG,

							// Team Fortress specific - medic heal, medic infect, etc.....
							ACT_MP_GRENADE1_DRAW,
							ACT_MP_GRENADE1_IDLE,
							ACT_MP_GRENADE1_ATTACK,
							ACT_MP_GRENADE2_DRAW,
							ACT_MP_GRENADE2_IDLE,
							ACT_MP_GRENADE2_ATTACK,

							ACT_MP_PRIMARY_GRENADE1_DRAW,
							ACT_MP_PRIMARY_GRENADE1_IDLE,
							ACT_MP_PRIMARY_GRENADE1_ATTACK,
							ACT_MP_PRIMARY_GRENADE2_DRAW,
							ACT_MP_PRIMARY_GRENADE2_IDLE,
							ACT_MP_PRIMARY_GRENADE2_ATTACK,

							ACT_MP_SECONDARY_GRENADE1_DRAW,
							ACT_MP_SECONDARY_GRENADE1_IDLE,
							ACT_MP_SECONDARY_GRENADE1_ATTACK,
							ACT_MP_SECONDARY_GRENADE2_DRAW,
							ACT_MP_SECONDARY_GRENADE2_IDLE,
							ACT_MP_SECONDARY_GRENADE2_ATTACK,

							ACT_MP_MELEE_GRENADE1_DRAW,
							ACT_MP_MELEE_GRENADE1_IDLE,
							ACT_MP_MELEE_GRENADE1_ATTACK,
							ACT_MP_MELEE_GRENADE2_DRAW,
							ACT_MP_MELEE_GRENADE2_IDLE,
							ACT_MP_MELEE_GRENADE2_ATTACK,

							ACT_MP_ITEM1_GRENADE1_DRAW,
							ACT_MP_ITEM1_GRENADE1_IDLE,
							ACT_MP_ITEM1_GRENADE1_ATTACK,
							ACT_MP_ITEM1_GRENADE2_DRAW,
							ACT_MP_ITEM1_GRENADE2_IDLE,
							ACT_MP_ITEM1_GRENADE2_ATTACK,

							ACT_MP_ITEM2_GRENADE1_DRAW,
							ACT_MP_ITEM2_GRENADE1_IDLE,
							ACT_MP_ITEM2_GRENADE1_ATTACK,
							ACT_MP_ITEM2_GRENADE2_DRAW,
							ACT_MP_ITEM2_GRENADE2_IDLE,
							ACT_MP_ITEM2_GRENADE2_ATTACK,

							// Building
							ACT_MP_STAND_BUILDING,
							ACT_MP_CROUCH_BUILDING,
							ACT_MP_RUN_BUILDING,
							ACT_MP_WALK_BUILDING,
							ACT_MP_AIRWALK_BUILDING,
							ACT_MP_CROUCHWALK_BUILDING,
							ACT_MP_JUMP_BUILDING,
							ACT_MP_JUMP_START_BUILDING,
							ACT_MP_JUMP_FLOAT_BUILDING,
							ACT_MP_JUMP_LAND_BUILDING,
							ACT_MP_SWIM_BUILDING,

							ACT_MP_ATTACK_STAND_BUILDING,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_BUILDING,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_BUILDING,
							ACT_MP_ATTACK_AIRWALK_BUILDING,

							ACT_MP_ATTACK_STAND_GRENADE_BUILDING,		// RUN, WALK
							ACT_MP_ATTACK_CROUCH_GRENADE_BUILDING,		// CROUCHWALK
							ACT_MP_ATTACK_SWIM_GRENADE_BUILDING,
							ACT_MP_ATTACK_AIRWALK_GRENADE_BUILDING,

							ACT_MP_STAND_PDA,
							ACT_MP_CROUCH_PDA,
							ACT_MP_RUN_PDA,
							ACT_MP_WALK_PDA,
							ACT_MP_AIRWALK_PDA,
							ACT_MP_CROUCHWALK_PDA,
							ACT_MP_JUMP_PDA,
							ACT_MP_JUMP_START_PDA,
							ACT_MP_JUMP_FLOAT_PDA,
							ACT_MP_JUMP_LAND_PDA,
							ACT_MP_SWIM_PDA,

							ACT_MP_ATTACK_STAND_PDA,
							ACT_MP_ATTACK_SWIM_PDA,

							ACT_MP_GESTURE_VC_HANDMOUTH,
							ACT_MP_GESTURE_VC_FINGERPOINT,
							ACT_MP_GESTURE_VC_FISTPUMP,
							ACT_MP_GESTURE_VC_THUMBSUP,
							ACT_MP_GESTURE_VC_NODYES,
							ACT_MP_GESTURE_VC_NODNO,

							ACT_MP_GESTURE_VC_HANDMOUTH_PRIMARY,
							ACT_MP_GESTURE_VC_FINGERPOINT_PRIMARY,
							ACT_MP_GESTURE_VC_FISTPUMP_PRIMARY,
							ACT_MP_GESTURE_VC_THUMBSUP_PRIMARY,
							ACT_MP_GESTURE_VC_NODYES_PRIMARY,
							ACT_MP_GESTURE_VC_NODNO_PRIMARY,

							ACT_MP_GESTURE_VC_HANDMOUTH_SECONDARY,
							ACT_MP_GESTURE_VC_FINGERPOINT_SECONDARY,
							ACT_MP_GESTURE_VC_FISTPUMP_SECONDARY,
							ACT_MP_GESTURE_VC_THUMBSUP_SECONDARY,
							ACT_MP_GESTURE_VC_NODYES_SECONDARY,
							ACT_MP_GESTURE_VC_NODNO_SECONDARY,

							ACT_MP_GESTURE_VC_HANDMOUTH_MELEE,
							ACT_MP_GESTURE_VC_FINGERPOINT_MELEE,
							ACT_MP_GESTURE_VC_FISTPUMP_MELEE,
							ACT_MP_GESTURE_VC_THUMBSUP_MELEE,
							ACT_MP_GESTURE_VC_NODYES_MELEE,
							ACT_MP_GESTURE_VC_NODNO_MELEE,

							ACT_MP_GESTURE_VC_HANDMOUTH_ITEM1,
							ACT_MP_GESTURE_VC_FINGERPOINT_ITEM1,
							ACT_MP_GESTURE_VC_FISTPUMP_ITEM1,
							ACT_MP_GESTURE_VC_THUMBSUP_ITEM1,
							ACT_MP_GESTURE_VC_NODYES_ITEM1,
							ACT_MP_GESTURE_VC_NODNO_ITEM1,

							ACT_MP_GESTURE_VC_HANDMOUTH_ITEM2,
							ACT_MP_GESTURE_VC_FINGERPOINT_ITEM2,
							ACT_MP_GESTURE_VC_FISTPUMP_ITEM2,
							ACT_MP_GESTURE_VC_THUMBSUP_ITEM2,
							ACT_MP_GESTURE_VC_NODYES_ITEM2,
							ACT_MP_GESTURE_VC_NODNO_ITEM2,

							ACT_MP_GESTURE_VC_HANDMOUTH_BUILDING,
							ACT_MP_GESTURE_VC_FINGERPOINT_BUILDING,
							ACT_MP_GESTURE_VC_FISTPUMP_BUILDING,
							ACT_MP_GESTURE_VC_THUMBSUP_BUILDING,
							ACT_MP_GESTURE_VC_NODYES_BUILDING,
							ACT_MP_GESTURE_VC_NODNO_BUILDING,

							ACT_MP_GESTURE_VC_HANDMOUTH_PDA,
							ACT_MP_GESTURE_VC_FINGERPOINT_PDA,
							ACT_MP_GESTURE_VC_FISTPUMP_PDA,
							ACT_MP_GESTURE_VC_THUMBSUP_PDA,
							ACT_MP_GESTURE_VC_NODYES_PDA,
							ACT_MP_GESTURE_VC_NODNO_PDA,


							ACT_VM_UNUSABLE,
							ACT_VM_UNUSABLE_TO_USABLE,
							ACT_VM_USABLE_TO_UNUSABLE,

							// Specific viewmodel activities for weapon roles
							ACT_PRIMARY_VM_DRAW,
							ACT_PRIMARY_VM_HOLSTER,
							ACT_PRIMARY_VM_IDLE,
							ACT_PRIMARY_VM_PULLBACK,
							ACT_PRIMARY_VM_PRIMARYATTACK,
							ACT_PRIMARY_VM_SECONDARYATTACK,
							ACT_PRIMARY_VM_RELOAD,
							ACT_PRIMARY_VM_DRYFIRE,
							ACT_PRIMARY_VM_IDLE_TO_LOWERED,
							ACT_PRIMARY_VM_IDLE_LOWERED,
							ACT_PRIMARY_VM_LOWERED_TO_IDLE,

							ACT_SECONDARY_VM_DRAW,
							ACT_SECONDARY_VM_HOLSTER,
							ACT_SECONDARY_VM_IDLE,
							ACT_SECONDARY_VM_PULLBACK,
							ACT_SECONDARY_VM_PRIMARYATTACK,
							ACT_SECONDARY_VM_SECONDARYATTACK,
							ACT_SECONDARY_VM_RELOAD,
							ACT_SECONDARY_VM_DRYFIRE,
							ACT_SECONDARY_VM_IDLE_TO_LOWERED,
							ACT_SECONDARY_VM_IDLE_LOWERED,
							ACT_SECONDARY_VM_LOWERED_TO_IDLE,

							ACT_MELEE_VM_DRAW,
							ACT_MELEE_VM_HOLSTER,
							ACT_MELEE_VM_IDLE,
							ACT_MELEE_VM_PULLBACK,
							ACT_MELEE_VM_PRIMARYATTACK,
							ACT_MELEE_VM_SECONDARYATTACK,
							ACT_MELEE_VM_RELOAD,
							ACT_MELEE_VM_DRYFIRE,
							ACT_MELEE_VM_IDLE_TO_LOWERED,
							ACT_MELEE_VM_IDLE_LOWERED,
							ACT_MELEE_VM_LOWERED_TO_IDLE,

							ACT_PDA_VM_DRAW,
							ACT_PDA_VM_HOLSTER,
							ACT_PDA_VM_IDLE,
							ACT_PDA_VM_PULLBACK,
							ACT_PDA_VM_PRIMARYATTACK,
							ACT_PDA_VM_SECONDARYATTACK,
							ACT_PDA_VM_RELOAD,
							ACT_PDA_VM_DRYFIRE,
							ACT_PDA_VM_IDLE_TO_LOWERED,
							ACT_PDA_VM_IDLE_LOWERED,
							ACT_PDA_VM_LOWERED_TO_IDLE,

							ACT_ITEM1_VM_DRAW,
							ACT_ITEM1_VM_HOLSTER,
							ACT_ITEM1_VM_IDLE,
							ACT_ITEM1_VM_PULLBACK,
							ACT_ITEM1_VM_PRIMARYATTACK,
							ACT_ITEM1_VM_SECONDARYATTACK,
							ACT_ITEM1_VM_RELOAD,
							ACT_ITEM1_VM_DRYFIRE,
							ACT_ITEM1_VM_IDLE_TO_LOWERED,
							ACT_ITEM1_VM_IDLE_LOWERED,
							ACT_ITEM1_VM_LOWERED_TO_IDLE,

							ACT_ITEM2_VM_DRAW,
							ACT_ITEM2_VM_HOLSTER,
							ACT_ITEM2_VM_IDLE,
							ACT_ITEM2_VM_PULLBACK,
							ACT_ITEM2_VM_PRIMARYATTACK,
							ACT_ITEM2_VM_SECONDARYATTACK,
							ACT_ITEM2_VM_RELOAD,
							ACT_ITEM2_VM_DRYFIRE,
							ACT_ITEM2_VM_IDLE_TO_LOWERED,
							ACT_ITEM2_VM_IDLE_LOWERED,
							ACT_ITEM2_VM_LOWERED_TO_IDLE,

							// Infested activities
							ACT_RELOAD_SUCCEED,
							ACT_RELOAD_FAIL,
							// Autogun
							ACT_WALK_AIM_AUTOGUN,
							ACT_RUN_AIM_AUTOGUN,
							ACT_IDLE_AUTOGUN,
							ACT_IDLE_AIM_AUTOGUN,
							ACT_RELOAD_AUTOGUN,
							ACT_CROUCH_IDLE_AUTOGUN,
							ACT_RANGE_ATTACK_AUTOGUN,
							ACT_JUMP_AUTOGUN,
							// Pistol
							ACT_IDLE_AIM_PISTOL,
							// PDW
							ACT_WALK_AIM_DUAL,
							ACT_RUN_AIM_DUAL,
							ACT_IDLE_DUAL,
							ACT_IDLE_AIM_DUAL,
							ACT_RELOAD_DUAL,
							ACT_CROUCH_IDLE_DUAL,
							ACT_RANGE_ATTACK_DUAL,
							ACT_JUMP_DUAL,
							// Shotgun
							ACT_IDLE_SHOTGUN,
							ACT_IDLE_AIM_SHOTGUN,
							ACT_CROUCH_IDLE_SHOTGUN,
							ACT_JUMP_SHOTGUN,
							// Rifle
							ACT_IDLE_AIM_RIFLE,
							ACT_RELOAD_RIFLE,
							ACT_CROUCH_IDLE_RIFLE,
							ACT_RANGE_ATTACK_RIFLE,
							ACT_JUMP_RIFLE,

							// Infested General AI
							ACT_SLEEP,
							ACT_WAKE,

							// Shield Bug
							ACT_FLICK_LEFT,
							ACT_FLICK_LEFT_MIDDLE,
							ACT_FLICK_RIGHT_MIDDLE,
							ACT_FLICK_RIGHT,
							ACT_SPINAROUND,

							// Mortar Bug
							ACT_PREP_TO_FIRE,
							ACT_FIRE,
							ACT_FIRE_RECOVER,

							// Shaman
							ACT_SPRAY,

							// Boomer
							ACT_PREP_EXPLODE,
							ACT_EXPLODE,

							// this is the end of the global activities, private per-monster activities start here.
							LAST_SHARED_ACTIVITY,
} Activity;

class __declspec (novtable)IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
public:
	virtual void			Release(void) = 0;
	virtual void			blahblahpad(void) = 0;
	virtual Vector&	GetAbsOrigin(void) const = 0;//in broken place use GetOrigin Below
	virtual const Vector&	GetAbsAngles(void) const = 0;
	Vector				GetPredicted(Vector p0);
	//---                 NetVars                  ---//

	template<class T>
	inline T GetFieldValue(int offset) {
		return *(T*)((DWORD)this + offset);
	}
	template<class T>
	T* GetFieldPointer(int offset) {
		return (T*)((DWORD)this + offset);
	}

	C_AnimationLayer& GetAnimOverlay(int Index)
	{
		return (*(C_AnimationLayer**)((DWORD)this + 0x2970))[Index];
	}

	int GetNumAnimOverlays()
	{
		return *(int*)((DWORD)this + 0x297C);
	}



	int EntIndex() {
		void *pNetworked = (void*)(this + 0x8);
		typedef int(__thiscall *OrigFn)(void*);
		return call_vfunc<OrigFn>(pNetworked, 10)(pNetworked);
	}

	Vector& GetAbsOrigin3(void)
	{
		VirtualFn(Vector&)(PVOID);
		return call_vfunc< OriginalFn >(this, 10)(this);
	}

	IClientNetworkable* GetNetworkable()
	{
		return reinterpret_cast<IClientNetworkable*>((DWORD)this + 0x8);
	}

	int GetIndex2()
	{
		//	void* networkable = (void*)(this + 0x8);
		//typedef int(__thiscall* OriginalFn)(PVOID);
		//return getvfunc<OriginalFn>(this, 76)(this);
		return GetNetworkable()->GetIndex();
	}

	int GetGlowIndex()
	{
		return *(int*)(this + 0xA310);
	}
	CPNETVAR_FUNC(char*, GetLastPlaceName, 0x9911c2d7);
	CPNETVAR_FUNC(CLocalPlayerExclusive*, localPlayerExclusive, 0x7177BC3E);// m_Local
	CPNETVAR_FUNC(CollisionProperty*, collisionProperty, 0xE477CBD0);//m_Collision
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CPNETVAR_FUNC(int*, GetPointerFlags, 0xE456D580); //m_fFlags
	CNETVAR_FUNC(float, GetLowerBodyYaw, 0xE6996CCF); //m_flLowerBodyYawTarget
	CNETVAR_FUNC(int, GetFlags, 0xE456D580); //m_fFlags
	CNETVAR_FUNC(float, GetTargetYaw, 0xE6996CCF)
		CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin 0x0134
	CNETVAR_FUNC(Vector, GetRotation, 0x6BEA197A); //m_angRotation
	CNETVAR_FUNC(int, GetTeamNum, 0xC08B6C6E); //m_iTeamNum
	CNETVAR_FUNC(int, GetMaxHealth, 0xC52E1C28); //m_iMaxHealth
	CNETVAR_FUNC(int, GetHealth, 0xA93054E3); //m_iHealth
	CNETVAR_FUNC(float, GetFlashDuration, 0x4B5938D5); //m_flFlashDuration
	CNETVAR_FUNC(float, GetFlashAlpha, 0xFE79FB98); //m_flFlashMaxAlpha
	CNETVAR_FUNC(unsigned char, GetLifeState, 0xD795CCFC); //m_lifeState
	CNETVAR_FUNC(HANDLE, GetActiveWeaponHandle, 0xB4FECDA3); //m_hActiveWeapon
	CNETVAR_FUNC(int, GetTickBase, 0xD472B079); //m_nTickBase
	CNETVAR_FUNC(Vector, GetViewOffset, 0xA9F74931); //m_vecViewOffset[0]
	CNETVAR_FUNC(Vector, GetViewPunch, 0x68F014C0);
	CNETVAR_FUNC(Vector, GetPunch, 0xBF25C290);
	CNETVAR_FUNC(Vector, GetVelocity, 0x40C1CA24); //m_vecVelocity[0]
	CNETVAR_FUNC(bool, HasGunGameImmunity, 0x6AD6FA0D); //m_bGunGameImmunity
	CNETVAR_FUNC(int, ArmorValue, 0x3898634); //m_ArmorValue
	CNETVAR_FUNC(bool, HasHelmet, 0x7B97F18A); //m_bHasHelmet
	CNETVAR_FUNC(int, GetObserverMode, 0x2441D093); // m_iObserverMode
	CNETVAR_FUNC(HANDLE, GetObserverTargetHandle, 0x8660FD83); //m_hObserverTarget
	CNETVAR_FUNC(int, GetShotsFired, 0x3F2F6C66); //m_nTickBase
	CNETVAR_FUNC(float, GetSimulationTime, 0xC4560E44); //m_flSimulationTime
	CNETVAR_FUNC(float, GetAnimTime, 0xD27E8416);
	CNETVAR_FUNC(bool, IsDefusing, 0xA2C14106); //m_bIsDefusing
	CNETVAR_FUNC(bool, IsScoped, 0x61B9C22C); //m_bIsScoped
	CNETVAR_FUNC(int, GetMoney, 0xF4B3E183); //m_iAccount
											 //CNETVAR_FUNC(int, GetPlayerCompRank, 0x75671F7F);
											 // ----------------------------------------------//
	int				GetAmmo();
	int				GetAmmo2();
	bool			HaveAmmo();

	bool IsAlive()
	{
		return (GetLifeState() == LIFE_ALIVE && GetHealth() > 0);
	}



	bool IsAlive2()
	{
		if (this != nullptr)
		{
			return (GetLifeState() == LIFE_ALIVE && GetHealth() > 0);
		}
	}

	IClientRenderable* GetClientRenderable2()
	{
		return reinterpret_cast<IClientRenderable*>(this + 0x4);
	}

	int DrawModel2(DrawModelFlags_t flags, uint8_t alpha)
	{
		typedef int(__thiscall* origfn)(void*, DrawModelFlags_t, uint8_t);
		return call_vfunc<origfn>(this->GetClientRenderable(), 9)(this->GetClientRenderable(), flags, alpha);
	}

	float GetLBYDelta()
	{
		return GetEyeAnglesPointer()->y - GetLowerBodyYaw();
	}


	bool isMoving() {
		return GetVelocity().Length() > 0.1f;
	}

	int GetMoveType()
	{
		if (!this)
			return 0;

		return ptr(int, this, 0x258);
	}

	QAngle* GetEyeAnglesPointer()
	{
		return reinterpret_cast<QAngle*>((DWORD)this + (DWORD)0xAA08);
	}

	QAngle GetEyeAngles()
	{
		return *reinterpret_cast<QAngle*>((DWORD)this + (DWORD)0xAA08);
	}

	float GetCycle()
	{
		return *reinterpret_cast<int*>((DWORD)this + GET_NETVAR("DT_CSPlayer", "m_flCycle"));
	}

	float GetFriction()
	{
		return *reinterpret_cast<float*>(uintptr_t(this + GET_NETVAR("DT_CSPlayer", "m_flFriction")));
	}

	Vector getAbsOriginal()
	{
		typedef Vector&(__thiscall *o_getAbsOriginal)(void*);
		return call_vfunc<o_getAbsOriginal>(this, 10)(this);
	}

	Vector getAbsAechse()
	{
		typedef Vector&(__thiscall *o_getAbsAechse)(void*);
		return call_vfunc<o_getAbsAechse>(this, 11)(this);
	}

	QAngle* GetEyeAnglesXY()
	{
		return (QAngle*)((DWORD)this + GET_NETVAR("DT_CSPlayer", "m_angEyeAngles"));
	}

	QAngle GetEyeAnglesTrans() {
		return *(QAngle*)((uintptr_t)this + GET_NETVAR("DT_CSPlayer", "m_angEyeAngles"));
	}

	Vector* GetOrigin1337() {
		static int m_vecOrigin = GET_NETVAR("DT_BaseEntity", "m_vecOrigin");
		return GetFieldPointer<Vector>(m_vecOrigin);
	}

	int GetHitboxSet()
	{
		return *(int*)(this + GET_NETVAR("DT_BaseAnimating", "m_nHitboxSet"));
	}

	float OldSimulationTime[65];


	float getCycle()
	{
		return *(float*)((DWORD)this + 0xA14);
	}

	int GetSequence() {
		if (!this)
			return 0.0f;
		return *(int*)((uintptr_t)this + GET_NETVAR("DT_CSPlayer", "m_nSequence"));
	}

	int getSequence()
	{
		return *(int*)((DWORD)this + 0x28AC);
	}

	float getPoseParams(int idx)
	{
		return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x2764 + sizeof(float) * idx);
	}

	float GetLowerBodyYawTarget() /*m_flLowerBodyYawTarget*/
	{
		return *(float*)((DWORD)this + GET_NETVAR("DT_CSPlayer", "m_flLowerBodyYawTarget"));
	}
	Vector *GetEyeAngles3() /*m_angEyeAngles*/
	{
		return (Vector*)((DWORD)this + GET_NETVAR("DT_CSPlayer", "m_angEyeAngles[0]"));
	}
	Vector GetBonePos(int i)
	{
		matrix3x4 boneMatrix[128];
		if (this->SetupBones(boneMatrix, 128, BONE_USED_BY_HITBOX, GetTickCount64()))
		{
			return Vector(boneMatrix[i][0][3], boneMatrix[i][1][3], boneMatrix[i][2][3]);
		}
		return Vector(0, 0, 0);
	}

	//std::array<float, 24> GetPoseParameters() {
	//	return *(std::array<float, 24>*)((uintptr_t)this + 0x2764); // + m_flPoseParameter
	//}

	Vector GetHeadPos()
	{
		return this->GetBonePos(6);
	}

	Vector GetHeadAngle()
	{
		return GetAbsOrigin() + GetViewOffset();
	}

	bool IsPlayer()
	{
		return GetClientClass()->m_ClassID == (int)CSGOClassID::CCSPlayer;
	}

	Vector GetOrigin2() {
		return *(Vector*)((DWORD)this + 0x00000134);
	}

	Vector GetViewAngles2() {
		return *(Vector*)((DWORD)this + 0x00000104);
	}

	Vector GetAbsOrigin2() {
		__asm {
			MOV ECX, this
			MOV EAX, DWORD PTR DS : [ECX]
			CALL DWORD PTR DS : [EAX + 0x28]
		}
	}
	Vector GetAbsAngles2() {
		__asm {
			MOV ECX, this;
			MOV EAX, DWORD PTR DS : [ECX];
			CALL DWORD PTR DS : [EAX + 0x2C]
		}
	}

	Vector GetEyePosition() {
		Vector Origin = *(Vector*)((DWORD)this + 0x00000134);
		Vector View = *(Vector*)((DWORD)this + 0x00000104);
		return(Origin + View);
	}

	Vector GetVecOrigin()
	{
		return *(Vector*)((DWORD)this + 0x134);
	}
	Vector GetAimPunch() {
		return *(Vector*)((DWORD)this + 0x00003018);
	}
	bool IsImmune() {
		return *(bool*)((DWORD)this + 0x000038A0);
	}
	ClientClass *GetClientClass2() {
		PVOID Networkable = (PVOID)((DWORD)(this) + 0x8);
		using Original = ClientClass*(__thiscall*)(PVOID);
		return call_vfunc<Original>(Networkable, 2)(Networkable);
	}
	HANDLE GetWeaponHandle() {
		return *(HANDLE*)((DWORD)this + 0x00002EE8);
	}

	WeaponInfo_t* GetWpnData()
	{
		if (!this)
			return nullptr;

		typedef WeaponInfo_t*(__thiscall* OriginalFn)(void*);
		return call_vfunc< OriginalFn >(this, 446)(this);
	}
	CSWeaponInfo* GetCSWpnData()
	{
		if (!this)
			return nullptr;

		typedef CSWeaponInfo*(__thiscall* OriginalFn)(void*);
		return call_vfunc< OriginalFn >(this, 446)(this);
	}

	void setAbsOriginal(Vector origin) // 55 8B EC 83 E4 F8 51 53 56 57 8B F1
	{
		using SetAbsOriginFn = void(__thiscall*)(void*, const Vector &origin);
		static SetAbsOriginFn SetAbsOrigin;

		if (!SetAbsOrigin)                                                           // ("client.dll", (PBYTE)"\x55\x8B\xEC\x83\xE4\xF8\x51\x53\x56\x57\x8B\xF1\xE8\x00\x00", "xxxxxxxxxxxxx??");
			SetAbsOrigin = (SetAbsOriginFn)(Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x55\x8B\xEC\x83\xE4\xF8\x51\x53\x56\x57\x8B\xF1\xE8\x00\x00", "xxxxxxxxxxxxx??"));

		SetAbsOrigin(this, origin);
	}

	void SetAngle2(Vector wantedang)
	{
		typedef void(__thiscall* SetAngleFn)(void*, const Vector &);
		static SetAngleFn SetAngle = (SetAngleFn)((DWORD)Utilities::Memory::FindPatternV2("client.dll", "55 8B EC 83 E4 F8 83 EC 64 53 56 57 8B F1 E8"));
		SetAngle(this, wantedang);
	}

	//void SetPoseParameters(std::array<float, 24> arr) {
	//	*(std::array<float, 24>*)((uintptr_t)this + GET_NETVAR("DT_CSPlayer", "m_flPoseParameter")) = arr;
	//}




	void InvalidateBoneCache() {
		static DWORD dwBoneCache = Utilities::Memory::FindPattern("client.dll", (BYTE*)"\x80\x3D\x00\x00\x00\x00\x00\x74\x16\xA1\x00\x00\x00\x00\x48\xC7\x81", "xx?????xxx????xxx");
		static DWORD dwForceBone = 0x267C;
		unsigned long iModelBoneCounter = **(unsigned long**)(dwBoneCache + 10);

		*(int*)((DWORD)this + dwForceBone + 0x20) = 0;
		*(unsigned int*)((DWORD)this + 0x2914) = 0xFF7FFFFF;
		*(unsigned int*)((DWORD)this + 0x2680) = (iModelBoneCounter - 1);
	}

	void setAbsAechse(Vector aechse)
	{
		using SetAbsAnglesFn = void(__thiscall*)(IClientEntity*, const Vector &angles);
		static SetAbsAnglesFn SetAbsAngles;

		if (!SetAbsAngles)
			SetAbsAngles = (SetAbsAnglesFn)(Utilities::Memory::FindPattern("client.dll", (BYTE*)"\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x64\x53\x56\x57\x8B\xF1\xE8", "xxxxxxxxxxxxxxx"));

		SetAbsAngles(this, aechse);

	}

	void updateClientSideAnimation()
	{
		typedef void(__thiscall *o_updateClientSideAnimation)(void*);
		call_vfunc<o_updateClientSideAnimation>(this, 218)(this);
	}
};
