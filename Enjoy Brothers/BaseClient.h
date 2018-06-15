
#pragma once

#include "MiscDef.h"
#include "ClientRecvProps.h"
#include "offsets.h"


class IBaseClientDLL
{
public:

	ClientClass* GetAllClasses(void)
	{
		typedef ClientClass* (__thiscall* OriginalFn)(PVOID); //Anything inside a VTable is a __thiscall unless it completly disregards the thisptr. You can also call them as __stdcalls, but you won't have access to the __thisptr.
		return call_vfunc<OriginalFn>(this, 8)(this); //Return the pointer to the head CClientClass.
	}
};

class CHudChat
{
public:
	void ChatPrintf(int iPlayerIndex, int iFilter, const char* fmt, ...)
	{
		call_vfunc<void(__cdecl*)(void*, int, int, const char*, ...)>(this, 26)(this, iPlayerIndex, iFilter, fmt);
	}
};