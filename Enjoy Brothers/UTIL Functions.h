

#pragma once

#include "SDK.h"
#include <Psapi.h>

#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

using IsReadyFn = void(__cdecl*)();
using ServerRankRevealAllFn = bool(__cdecl*)(float*);

struct Hitbox
{
	Hitbox(void)
	{
		hitbox = -1;
	}

	Hitbox(int newHitBox)
	{
		hitbox = newHitBox;
	}

	int  hitbox;
	Vector points[9];
};

enum
{
	FL_HIGH = (1 << 0),
	FL_LOW = (1 << 1),
	FL_SPECIAL = (1 << 2)
};

struct BestPoint
{
	BestPoint(void)
	{
		hitbox = -1;
		point = Vector(0, 0, 0);
		index = -1;
		dmg = -1;
		flags = 0;
	}

	BestPoint(int newHitBox)
	{
		hitbox = newHitBox;
		point = Vector(0, 0, 0);
		index = -1;
		dmg = -1;
		flags = 0;
	}

	Vector point;
	int  index;
	int  dmg;
	int  flags;
	int  hitbox;
};


namespace GameUtils
{
	extern DWORD FindPattern1(std::string moduleName, std::string pattern);
	extern ServerRankRevealAllFn ServerRankRevealAllEx;
	extern IsReadyFn IsReady;
	void NormaliseViewAngle(Vector &angle);
	void CL_FixMove(CInput::CUserCmd* cmd, Vector viewangles);
	bool IsVisible(IClientEntity* pLocal, IClientEntity* pEntity, int BoneID);
	bool IsBallisticWeapon(void* weapon);
	bool IsRevolver(void * weapon);
	bool IsPistol(void* weapon);
	bool IsSniper(void* weapon);
	bool IsG(void * weapon);
	bool IsScopedWeapon(void* weapon);
	int GetPlayerCompRank(IClientEntity* pEntity);
	extern void ServerRankRevealAll();
	unsigned short UTIL_GetAchievementEventMask();
	bool IsGLOCK(void * weapon);
	bool IsP250(void * weapon);
	bool IsTEC9(void * weapon);
	bool IsFSEVEN(void * weapon);
	bool IsUMP(void * weapon);
	bool IsMAC10(void * weapon);
	bool IsDuals(void * weapon);
	bool IsPistol(void* weapon);
	bool IsMP(void * weapon);
	void ClampViewAngle(Vector & angle);
	bool IsShotgun(void * weapon);
	bool IsMachinegun(void * weapon);
	bool IsGrenade(void * weapon);
	bool IsSSG08(void * weapon);
	bool IsAK47(void * weapon);
	bool IsDEAGLE(void * weapon);
	bool IsAutoSniper(void * weapon);
	bool IsMP9(void * weapon);
	bool IsMP7(void * weapon);
	bool IsM4A1(void * weapon);
	bool IsM4A1S(void * weapon);
	bool IsFAMAS(void * weapon);
	bool IsAWP(void * weapon);
	bool IsBizon(void * weapon);
	bool IsUSPS(void * weapon);
	bool IsGALIL(void * weapon);
	bool IsSniper(void* weapon);
	bool IsRifle(void * weapon);
};

// Trace Line Memes
void UTIL_TraceLine(const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask, const IClientEntity *ignore, int collisionGroup, trace_t *ptr);

void UTIL_ClipTraceToPlayers(const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask, ITraceFilter* filter, trace_t* tr);

bool IsBreakableEntity(IClientEntity* ent);

bool TraceToExit(Vector& end, trace_t& tr, Vector start, Vector vEnd, trace_t* trace);

void SayInChat(const char *text);

void SayInTeamChat(const char *text);

void SetName(std::string name);

Vector GetHitpointPosition(IClientEntity* pEntity, int Hitbox, Vector *Point);

//bool GetBestPoint(IClientEntity* pEntity, Hitbox* hitbox, Vector *point);

Vector GetHitboxPosition(IClientEntity* pEntity, int Hitbox);

Vector GetHitboxPosition2(IClientEntity* pEntity, int Hitbox);

//Vector GetHitscan(IClientEntity* pEntity, int Hitbox);

Vector GetEyePosition(IClientEntity* pEntity);

void ForceUpdate();

//unsigned short UTIL_GetAchievementEventMask();