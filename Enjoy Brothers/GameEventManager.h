#pragma once 
#include <windows.h>


class IGameEvent
{
public:
	virtual ~IGameEvent() = 0;
	virtual const char* GetName() const = 0;
	virtual bool  IsReliable() const = 0;
	virtual bool  IsLocal() const = 0;
	virtual bool  IsEmpty(const char* KeyName = NULL) = 0;
	virtual bool  GetBool(const char* KeyName = NULL, bool defaultValue = false) = 0;
	virtual int   GetInt(const char* KeyName = NULL, int defaultValue = 0) = 0;
	virtual unsigned long long GetUint64(char const* KeyName = NULL, unsigned long long defaultValue = 0) = 0;
	virtual float GetFloat(const char* KeyName = NULL, float defaultValue = 0.0f) = 0;
	virtual const char* GetString(const char* KeyName = NULL, const char* defaultValue = "") = 0;
	virtual const wchar_t* GetWString(char const* KeyName = NULL, const wchar_t* defaultValue = L"") = 0;

	virtual void SetBool(const char* KeyName, bool value) = 0;
	virtual void SetInt(const char* KeyName, int value) = 0;
	virtual void SetUInt64(const char* KeyName, unsigned long long value) = 0;
	virtual void SetFloat(const char* KeyName, float value) = 0;
	virtual void SetString(const char* KeyName, const char* value) = 0;
	virtual void SetWString(const char* KeyName, const wchar_t* value) = 0;
};

class IGameEvent2 {
public:
	const char* GetName() {
		return call_vfunc<const char*(__thiscall *)(void*)>(this, 1)(this);
	}

	int GetInt(const char* szKeyName, int nDefault = 0) {
		return call_vfunc<int(__thiscall *)(void*, const char*, int)>(this, 6)(this, szKeyName, nDefault);
	}

	const char* GetString(const char* szKeyName) {
		return call_vfunc<const char*(__thiscall *)(void*, const char*, int)>(this, 9)(this, szKeyName, 0);
	}

	void SetString(const char* szKeyName, const char* szValue) {
		return call_vfunc<void(__thiscall *)(void*, const char*, const char*)>(this, 16)(this, szKeyName, szValue);
	}
};

/*class IGameEventListener2
{
public:
virtual	~IGameEventListener2() {};
virtual void HandleGameEvent(IGameEvent *pEvent) = 0;
virtual int IndicateEventHandling() = 0;

}; */

class IGameEventListener2 {
public:
	virtual	~IGameEventListener2(void) {};

	// FireEvent is called by EventManager if event just occured
	// KeyValue memory will be freed by manager if not needed anymore
	virtual void FireGameEvent(IGameEvent *event) = 0;

	virtual int	 GetEventDebugID(void) = 0;
};

typedef void(*DamageCallback_t)(IGameEvent*);
class DamageEventListener : public IGameEventListener2
{
public:
	DamageEventListener(DamageCallback_t NewCallback) { Callback = NewCallback; }
	virtual void HandleGameEvent(IGameEvent *pEvent)
	{
		Callback(pEvent);
	}
	virtual int IndicateEventHandling()
	{
		return 0x2A;
	}
private:
	DamageCallback_t Callback;
};



/*class IGameEventManager2
{
public:
virtual int pad(void* ptr) = 0;
virtual int LoadEventsFromFile(const char *filename) = 0;
virtual void Reset() = 0;
virtual bool AddListener(IGameEventListener2* listener, const char *name, bool bServerSide) = 0;
virtual bool FindListener(IGameEventListener2* listener, const char *name) = 0;
virtual int RemoveListener(IGameEventListener2* listener) = 0;
virtual IGameEvent* CreateEvent(const char* name, bool bForce, unsigned int dwUnknown) = 0;
virtual bool FireEvent(IGameEvent* event, bool bDontBroadcast = false) = 0;
virtual bool FireEventClientSide(IGameEvent* event) = 0;
virtual IGameEvent* DuplicateEvent(IGameEvent* event) = 0;
virtual void FreeEvent(IGameEvent* event) = 0;
virtual bool SerializeEvent(IGameEvent* event, void* buf) = 0;
virtual IGameEvent* UnserializeEvent(void* buf) = 0;
}; */

class bf_write;
class bf_read;

class IGameEventManager2 {
public:
	virtual	~IGameEventManager2(void) {};

	// load game event descriptions from a file eg "resource\gameevents.res"
	virtual int LoadEventsFromFile(const char *filename) = 0;

	// removes all and anything
	virtual void  Reset() = 0;

	// adds a listener for a particular event
	virtual bool AddListener(IGameEventListener2 *listener, const char *name, bool bServerSide) = 0;

	// returns true if this listener is listens to given event
	virtual bool FindListener(IGameEventListener2 *listener, const char *name) = 0;

	// removes a listener 
	virtual void RemoveListener(IGameEventListener2 *listener) = 0;

	// create an event by name, but doesn't fire it. returns NULL is event is not
	// known or no listener is registered for it. bForce forces the creation even if no listener is active
	virtual IGameEvent *CreateEvent(const char *name, bool bForce = false, int *pCookie = NULL) = 0;

	// fires a server event created earlier, if bDontBroadcast is set, event is not send to clients
	virtual bool FireEvent(IGameEvent *event, bool bDontBroadcast = false) = 0;

	// fires an event for the local client only, should be used only by client code
	virtual bool FireEventClientSide(IGameEvent *event) = 0;

	// create a new copy of this event, must be free later
	virtual IGameEvent *DuplicateEvent(IGameEvent *event) = 0;

	// if an event was created but not fired for some reason, it has to bee freed, same UnserializeEvent
	virtual void FreeEvent(IGameEvent *event) = 0;

	// write/read event to/from bitbuffer
	virtual bool SerializeEvent(IGameEvent *event, bf_write *buf) = 0;
	virtual IGameEvent *UnserializeEvent(bf_read *buf) = 0; // create new KeyValues, must be deleted
};