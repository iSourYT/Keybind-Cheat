

#pragma once

// Includes

#include "SDK.h"

// Namespace to contain all the valve interfaces
namespace Interfaces
{
	// Gets handles to all the interfaces needed
	void Initialise();

	extern IBaseClientDLL* Client;
	extern IVEngineClient* Engine;
	extern IPanel* Panels;
	extern IClientEntityList* EntList;
	extern ISurface* Surface;
	extern IVDebugOverlay* DebugOverlay;
	extern IVDebugOverlay2* DebugOverlay2;
	extern IClientModeShared* ClientMode;

	extern CGlobalVarsBase *Globals;
	extern DWORD *Prediction;
	extern CMaterialSystem* MaterialSystem;
	extern CMaterialSystem2* MaterialSystem2;
	extern CVRenderView* RenderView;
	extern IVModelRender* ModelRender;
	extern CModelInfo* ModelInfo;
	extern IEngineTrace* Trace;
	extern IPhysicsSurfaceProps* PhysProps;
	extern ICVar *CVar;
	extern CInput* pInput;
	extern IMoveHelper* MoveHelper;
	extern IGameMovement *GameMovement;
	extern IPrediction* GamePrediction;
	extern IVEffects* Dilight;
	extern IGameEventManager* GameEventManager;
	extern CHudChat* ChatElement;
	extern IGameEventManager2 *GameEventManager2;
};