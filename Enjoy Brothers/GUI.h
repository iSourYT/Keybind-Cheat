#include "CommonIncludes.h"

#include <map>

#include "imgui_memory_editor.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include <d3d9types.h>
#include "XorStr.h"


class CGUI
{
public:
	CGUI();

	// Draws all windows 
	void Draw();

	// Handle all input etc
	void Update();

	// Draws a single window
	//bool DrawWindow(CWindow* window);

	// Registers a window
	//void RegisterWindow(CWindow* window);

	// Config saving/loading
	//void SaveWindowState(CWindow* window, std::string Filename);
	//void LoadWindowState(std::string Filename, CWindow * window);
	//void LoadWindowState(CWindow* window, std::string Filename);

	// Window Binds
	//void BindWindow(unsigned char Key, CWindow* window);

	// Input
	bool GetKeyPress(unsigned int key);
	bool GetKeyState(unsigned int key);
	bool IsMouseInRegion(int y, int x2, int y2, int x);
	bool IsMouseInRegion(RECT region);
	POINT GetMouse();

private:
	// Input
	// keyboard
	bool keys[256];
	bool oldKeys[256];
	// Mouse
	POINT Mouse;
	bool MenuOpen;

	// Window Dragging
	bool IsDraggingWindow;
	//CWindow* DraggingWindow;
	int DragOffsetX; int DragOffsetY;

	// Windows
	//std::vector<CWindow*> Windows;

	// KeyBinds -> Windows Map
	//std::map<int, CWindow*> WindowBinds;

};

extern CGUI GUI;


#include <d3d9.h>


#include "imgui_memory_editor.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"


#include "Utilities.h"

#include "OptionsManager.h"


//#pragma comment(lib, "d3d9.lib")
//#pragma comment(lib, "d3dx9.lib")

extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace DirectX {
	typedef long(__stdcall* EndScene_t)(IDirect3DDevice9* device);
	typedef long(__stdcall* Reset_t)(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pp);

	extern EndScene_t g_fnOriginalEndScene;
	extern Reset_t g_fnOriginalReset;

	extern WNDPROC g_pOldWindowProc;
	extern HWND g_hWindow;

	HRESULT   __stdcall Hooked_EndScene(IDirect3DDevice9* pDevice);
	HRESULT   __stdcall Hooked_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
	LRESULT   __stdcall Hooked_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}