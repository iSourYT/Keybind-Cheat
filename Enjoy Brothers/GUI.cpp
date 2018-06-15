#include "GUI.h"
#include "OptionsManager.h"
#include "SDK.h"
#include <ios>
#include <iosfwd>


CGUI::CGUI()
{

}

bool CGUI::GetKeyPress(unsigned int key)
{
	if (keys[key] == true && oldKeys[key] == false)
		return true;
	else
		return false;
}

bool CGUI::GetKeyState(unsigned int key)
{
	return keys[key];
}

bool CGUI::IsMouseInRegion(int y, int x2, int y2, int x)
{
	if (Mouse.x > x && Mouse.y > y && Mouse.x < x2 && Mouse.y < y2)
		return true;
	else
		return false;
}

bool CGUI::IsMouseInRegion(RECT region)
{
	return IsMouseInRegion(region.top, region.left + region.right, region.top + region.bottom, region.left);
}

POINT CGUI::GetMouse()
{
	return Mouse;
}

CGUI GUI;


namespace DirectX {
	EndScene_t g_fnOriginalEndScene;
	Reset_t g_fnOriginalReset;

	WNDPROC g_pOldWindowProc;
	HWND g_hWindow;

	bool g_IsInitialized = false;

	HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9* pDevice) {
		if (!g_IsInitialized) {
			ImGui_ImplDX9_Init(g_hWindow, pDevice);

			ImGuiStyle& style = ImGui::GetStyle();

			ImColor mainColor = ImColor(54, 54, 54, 255);
			ImColor bodyColor = ImColor(24, 24, 24, 240);
			ImColor fontColor = ImColor(255, 255, 255, 255);

			ImVec4 mainColorHovered = ImVec4(mainColor.Value.x + 0.1f, mainColor.Value.y + 0.1f, mainColor.Value.z + 0.1f, mainColor.Value.w);
			ImVec4 mainColorActive = ImVec4(mainColor.Value.x + 0.2f, mainColor.Value.y + 0.2f, mainColor.Value.z + 0.2f, mainColor.Value.w);
			ImVec4 menubarColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w - 0.8f);
			ImVec4 frameBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .1f);
			ImVec4 tooltipBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .05f);
			//	aimtux style

			style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
			style.Colors[ImGuiCol_WindowBg] = bodyColor;
			style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_Border] = ImVec4(0.19f, 0.41f, 0.57f, 1.0f);
			style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_FrameBg] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.24f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_TitleBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
			style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
			style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
			style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
			style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.46f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.40f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_ComboBg] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
			style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.40f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_Border] = fontColor;
			style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.38f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_Button] = mainColor;
			style.Colors[ImGuiCol_ButtonHovered] = mainColorHovered;
			style.Colors[ImGuiCol_ButtonActive] = mainColorActive;
			style.Colors[ImGuiCol_Header] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_Column] = ImVec4(0.00f, 0.50f, 0.50f, 0.33f);
			style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.00f, 0.50f, 0.50f, 0.47f);
			style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.00f, 0.70f, 0.70f, 1.00f);
			style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_CloseButton] = ImVec4(0.19f, 0.41f, 0.57f, 0.46f);
			style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.36f, 0.60f, 0.76f, 0.46f);
			style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 2.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 2.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 2.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 2.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
			style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.04f, 0.10f, 0.09f, 0.51f);
			// midnight style
			/*ImGuiStyle& style = ImGui::GetStyle();
			style.Colors[ImGuiCol_Text] = ImVec4(0.31f, 0.25f, 0.24f, 1.00f);
			style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
			style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.74f, 0.74f, 0.94f, 1.00f);
			style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.68f, 0.68f, 0.68f, 0.00f);
			style.Colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
			style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_FrameBg] = ImVec4(0.62f, 0.70f, 0.72f, 0.56f);
			style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.95f, 0.33f, 0.14f, 0.47f);
			style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.97f, 0.31f, 0.13f, 0.81f);
			style.Colors[ImGuiCol_TitleBg] = ImVec4(0.42f, 0.75f, 1.00f, 0.53f);
			style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.65f, 0.80f, 0.20f);
			style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.40f, 0.62f, 0.80f, 0.15f);
			style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.39f, 0.64f, 0.80f, 0.30f);
			style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.28f, 0.67f, 0.80f, 0.59f);
			style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.25f, 0.48f, 0.53f, 0.67f);
			style.Colors[ImGuiCol_ComboBg] = ImVec4(0.89f, 0.98f, 1.00f, 0.99f);
			style.Colors[ImGuiCol_CheckMark] = ImVec4(0.48f, 0.47f, 0.47f, 0.71f);
			style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.31f, 0.47f, 0.99f, 1.00f);
			style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.79f, 0.18f, 0.78f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.82f, 1.00f, 0.81f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.72f, 1.00f, 1.00f, 0.86f);
			style.Colors[ImGuiCol_Header] = ImVec4(0.65f, 0.78f, 0.84f, 0.80f);
			style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.75f, 0.88f, 0.94f, 0.80f);
			style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.55f, 0.68f, 0.74f, 0.80f);//ImVec4(0.46f, 0.84f, 0.90f, 1.00f);
			style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.60f, 0.60f, 0.80f, 0.30f);
			style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
			style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
			style.Colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.75f, 0.98f, 0.50f);
			style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 0.47f, 0.41f, 0.60f);
			style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.16f, 0.00f, 1.00f);
			style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.99f, 0.54f, 0.43f);*/

			style.Alpha = 1.0;
			style.ChildWindowRounding = 3;
			style.WindowRounding = 3;
			style.GrabRounding = 1;
			style.GrabMinSize = 20;
			style.FrameRounding = 0;
			style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
			style.ItemInnerSpacing = ImVec2(8, 6);
			style.ItemSpacing = ImVec2(5, 8);




			g_IsInitialized = true;
		}
		else {
			ImGui::GetIO().MouseDrawCursor = OptionsManager.bShowMenu;

			//Begins a new ImGui frame.
			ImGui_ImplDX9_NewFrame();


			ImGui::SetNextWindowPos(ImVec2(100, 200), ImGuiSetCond_FirstUseEver);








			if (OptionsManager.bShowMenu) {
				//Begin Main window code




				ImGui::Begin(XorStr(""), &OptionsManager.bShowMenu, ImVec2(750, 500), OptionsManager.s_MenuTransparency, ImGuiWindowFlags_NoCollapse);
				{
					int tabWidth = ImGui::GetWindowWidth() / 5 - 10;
					if (ImGui::Button(XorStr("Rage"), ImVec2(tabWidth, 75))) {
						OptionsManager.g_tRagebot = true;
						OptionsManager.g_tLegitbot = false;
						OptionsManager.g_tVisuals = false;
						OptionsManager.g_tMisc = false;
						OptionsManager.g_tSettings = false;
					}
					ImGui::SameLine();
					if (ImGui::Button(XorStr("Legit"), ImVec2(tabWidth, 75))) {
						OptionsManager.g_tRagebot = false;
						OptionsManager.g_tLegitbot = true;
						OptionsManager.g_tVisuals = false;
						OptionsManager.g_tMisc = false;
						OptionsManager.g_tSettings = false;
					}
					ImGui::SameLine();
					if (ImGui::Button(XorStr("Visuals"), ImVec2(tabWidth, 75))) {
						OptionsManager.g_tRagebot = false;
						OptionsManager.g_tLegitbot = false;
						OptionsManager.g_tVisuals = true;
						OptionsManager.g_tMisc = false;
						OptionsManager.g_tSettings = false;

					}
					ImGui::SameLine();
					if (ImGui::Button(XorStr("Misc"), ImVec2(tabWidth, 75))) {
						OptionsManager.g_tRagebot = false;
						OptionsManager.g_tLegitbot = false;
						OptionsManager.g_tVisuals = false;
						OptionsManager.g_tMisc = true;
						OptionsManager.g_tSettings = false;

					}
					ImGui::SameLine();
					if (ImGui::Button(XorStr("Settings"), ImVec2(tabWidth, 75))) {
						OptionsManager.g_tRagebot = false;
						OptionsManager.g_tLegitbot = false;
						OptionsManager.g_tVisuals = false;
						OptionsManager.g_tMisc = false;
						OptionsManager.g_tSettings = true;

					}

					ImGui::Separator();

					// Tabs
					if (OptionsManager.g_tRagebot) {
						ImGui::Text(XorStr("Rage:"));
						ImGui::Separator();

						ImGui::BeginChild("Rage", ImVec2(720, 325), true);
						{
							ImGui::Checkbox("Enable Ragebot", &OptionsManager.bEnableRagebot);





						}
						ImGui::EndChild();


					}

					if (OptionsManager.g_tLegitbot) {
						ImGui::Text(XorStr("Legit:"));
						ImGui::Separator();

					}

					if (OptionsManager.g_tVisuals) {
						ImGui::Text(XorStr("Visuals:"));
						ImGui::Separator();

						ImGui::BeginChild("Visuals", ImVec2(720, 325), true);
						{
							const char *opt_ChamsType[] = { "Off", "Visible Only", "Visible Flat", "Full Chams", "Flat Chams" };
							ImGui::Combo("Cham Type", &OptionsManager.bChams, opt_ChamsType, 5);

							ImGui::Checkbox("Bomb Timer", &OptionsManager.bBombTimer);
							
							ImGui::Checkbox("Weapon Icons", &OptionsManager.bWeaponESP);





						}
						ImGui::EndChild();

					}

					if (OptionsManager.g_tMisc) {
						ImGui::Text(XorStr("Misc:"));
						ImGui::Separator();

						ImGui::BeginChild("Misc", ImVec2(720, 325), true);
						{
							ImGui::Checkbox("Bunnyhop", &OptionsManager.bAutoHop);

							ImGui::Checkbox("Auto Strafe", &OptionsManager.bAutoStrafe);

						}
						ImGui::EndChild();


					}
					if (OptionsManager.g_tSettings) {
						ImGui::Text(XorStr("Settings:"));
						ImGui::Separator();

						if (ImGui::CollapsingHeader(XorStr("Menu"))) {
							ImGui::SliderFloat(XorStr("Menu Transparency"), &OptionsManager.s_MenuTransparency, .1, 1, "%0.1f");
						}
					}
				}

				ImGui::End();

				/*
				ImGui::SetNextWindowPos(ImVec2(550, 200), ImGuiSetCond_FirstUseEver);
				//Begin Target window code
				ImGui::Begin(XorStr("Narcissisti.cc v72 ALPHA - Target Selector"), &OptionsManager.bShowMenu, ImVec2(400, 500), 1.f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
				{
				for (int i = 1; i < SSDK::I::Engine()->GetMaxClients(); ++i) {
				CBaseEntity *pClient = (CBaseEntity*)SSDK::I::EntityList()->GetClientEntity(i);
				if (pClient) {
				if (*pClient->GetTeamNum() != *CBaseEntity::GetLocalPlayer()->GetTeamNum()) {
				SSDK::PlayerInfo entInfo;
				SSDK::I::Engine()->GetPlayerInfo(i, &entInfo);
				if (ImGui::CollapsingHeader(entInfo.szName)) {
				ImGui::Checkbox(XorStr("Use custom settings"), &OptionsManager.aCacheAngle[i].bCustomSetts);
				ImGui::Checkbox(XorStr("Resolve angle"), &OptionsManager.aCacheAngle[i].bCorrect);
				static const char *szResolveType[] = { XorStr("Simple"), XorStr("Delta calc"), XorStr("Delta calc 2"), XorStr("Anti-Anti-Resolver") };
				ImGui::Combo(XorStr("Resolver type"), &OptionsManager.aCacheAngle[i].iResolverType, szResolveType, ARRAYSIZE(szResolveType));
				ImGui::Checkbox(XorStr("Awall Prioritize visible parts"), &OptionsManager.aCacheAngle[i].bPrioritizeVis);
				ImGui::Checkbox(XorStr("Prioritize selected hitbox"), &OptionsManager.aCacheAngle[i].bPrioritize);
				ImGui::SliderInt(XorStr("Select hitbox"), &OptionsManager.aCacheAngle[i].iHitbox, 0, 20);
				ImGui::SliderFloat(XorStr("Min dmg"), &OptionsManager.aCacheAngle[i].flMinDmg, 0, 100);
				ImGui::Checkbox(XorStr("Auto baim"), &OptionsManager.aCacheAngle[i].bAutoBaim);
				ImGui::SliderInt(XorStr("Baim after shot"), &OptionsManager.aCacheAngle[i].iAutoBaimAferShot, 0, 10);
				ImGui::SliderInt(XorStr("Select hitbox auto baim"), &OptionsManager.aCacheAngle[i].iHitboxAutoBaim, 0, 20);
				ImGui::Checkbox(XorStr("Disable interp/Lag compensate"), &OptionsManager.aCacheAngle[i].bInterpLagComp);
				}
				}
				}
				}
				}
				ImGui::End();
				*/
			}
			ImGui::Render();
		}

		return g_fnOriginalEndScene(pDevice);
	}

	HRESULT __stdcall Hooked_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters) {
		if (!g_IsInitialized) return g_fnOriginalReset(pDevice, pPresentationParameters);
		ImGui_ImplDX9_InvalidateDeviceObjects();

		auto hr = g_fnOriginalReset(pDevice, pPresentationParameters);
		ImGui_ImplDX9_CreateDeviceObjects();
		return hr;
	}

	LRESULT __stdcall Hooked_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg) {
		case WM_LBUTTONDOWN:
			OptionsManager.vecPressedKeys[VK_LBUTTON] = true;
			break;
		case WM_LBUTTONUP:
			OptionsManager.vecPressedKeys[VK_LBUTTON] = false;
			break;
		case WM_RBUTTONDOWN:
			OptionsManager.vecPressedKeys[VK_RBUTTON] = true;
			break;
		case WM_RBUTTONUP:
			OptionsManager.vecPressedKeys[VK_RBUTTON] = false;
			break;
		case WM_KEYDOWN:
			OptionsManager.vecPressedKeys[wParam] = true;
			break;
		case WM_KEYUP:
			OptionsManager.vecPressedKeys[wParam] = false;
			break;
		default: break;
		}

		static ConVar *conMouseEnable = Interfaces::CVar->FindVar(XorStr("cl_mouseenable"));
		static bool isDown = false;
		static bool isClicked = false;
		if (OptionsManager.vecPressedKeys[VK_INSERT]) {
			isClicked = false;
			isDown = true;
		}
		else if (!OptionsManager.vecPressedKeys[VK_INSERT] && isDown) {
			isClicked = true;
			isDown = false;
		}
		else {
			isClicked = false;
			isDown = false;
		}

		if (isClicked) {
			if (OptionsManager.bShowMenu) {
				//CONFIG SAVER - LOAD
				//std::ofstream ofs("hvhacademy.save", std::ios::binary);
				//ofs.write((char*)&OptionsManager, sizeof(OptionsManager));



			}
			OptionsManager.bShowMenu = !OptionsManager.bShowMenu;
			conMouseEnable->SetValue(!OptionsManager.bShowMenu);
		}


		if (g_IsInitialized && OptionsManager.bShowMenu && ImGui_ImplDX9_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(g_pOldWindowProc, hWnd, uMsg, wParam, lParam);
	}
}