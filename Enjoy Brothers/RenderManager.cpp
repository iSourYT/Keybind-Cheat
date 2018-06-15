

#pragma once

#include "RenderManager.h"
#include <math.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define M_PI			3.14159265358979323846

// Font Instances
namespace Render
{
	// Text functions
	namespace Fonts
	{
		DWORD Default;
		DWORD Menu;
		DWORD MenuBold;
		DWORD ESP;
		DWORD ICON;
		DWORD IconFont;
		DWORD WaterMark;
		DWORD WaterMark2;
		DWORD MenuText;
		DWORD Watermark;
		DWORD MenuTAB;
		DWORD BOMBLBY;
		DWORD MenuSymbols;
	};
};

// We don't use these anywhere else, no reason for them to be
// available anywhere else
enum EFontFlags
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800,
};

// Initialises the rendering system, setting up fonts etc
void Render::Initialise()
{
	Fonts::Default = 0x1D; // MainMenu Font from vgui_spew_fonts 
	Fonts::Menu = Interfaces::Surface->FontCreate();
	Fonts::MenuBold = Interfaces::Surface->FontCreate();
	Fonts::ESP = Interfaces::Surface->FontCreate();
	Fonts::ICON = Interfaces::Surface->FontCreate();
	Fonts::IconFont = Interfaces::Surface->FontCreate();
	Fonts::MenuText = Interfaces::Surface->FontCreate();
	Fonts::MenuTAB = Interfaces::Surface->FontCreate();
	Fonts::BOMBLBY = Interfaces::Surface->FontCreate();
	Fonts::Watermark = Interfaces::Surface->FontCreate();
	Fonts::WaterMark2 = Interfaces::Surface->FontCreate();
	Fonts::WaterMark = Interfaces::Surface->FontCreate();
	Fonts::MenuSymbols = Interfaces::Surface->FontCreate();

	const char* main_font = "Tahoma";

	Interfaces::Surface->SetFontGlyphSet(Fonts::BOMBLBY, "Tahoma", 35, 800, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::Menu, "Verdana Bold", 13, 500, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::MenuBold, "Verdana Bold", 12, 500, 0, 0, FONTFLAG_OUTLINE | FONTFLAG_DROPSHADOW | FONTFLAG_ANTIALIAS);
	// Interfaces::Surface->SetFontGlyphSet(Fonts::Menu, "Visitor TT2 BRK", 14, 500, 0, 0, FONTFLAG_ANTIALIAS);
	// Interfaces::Surface->SetFontGlyphSet(Fonts::MenuBold, "Visitor TT2 BRK", 14, 550, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::ESP, "Andale Mono", 12, 1000, 0, 0, FONTFLAG_DROPSHADOW | FONTFLAG_OUTLINE);
	Interfaces::Surface->SetFontGlyphSet(Fonts::ICON, "Tahoma", 35, 800, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::MenuText, "Verdana Bold", 14, 500, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::MenuTAB, "Impact", 40, 500, 0, 0, FONTFLAG_ANTIALIAS | FONTFLAG_DROPSHADOW);
	Interfaces::Surface->SetFontGlyphSet(Fonts::Watermark, "impact", 28, 600, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::IconFont, "undefeated", 10, 500, 0, 0, FONTFLAG_ANTIALIAS | FONTFLAG_DROPSHADOW | FONTFLAG_OUTLINE);
	Interfaces::Surface->SetFontGlyphSet(Fonts::WaterMark2, "Impact", 32, 500, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::WaterMark, "Impact", 32, 500, 0, 0, FONTFLAG_ANTIALIAS);
	Interfaces::Surface->SetFontGlyphSet(Fonts::MenuSymbols, main_font, 16, 500, 0, 0, FONTFLAG_ANTIALIAS);

	//Utilities::Log("Render System Ready");
}

struct Position
{
public:

	int		x;
	int		y;
};

// ---------------------------------------------------------
// Usage: FilledCircle{Position{_x, _y}, 10f}
// ---------------------------------------------------------
struct FilledCircle
{
public:

	Position     pos;
	float		 radius;
};



RECT Render::GetViewport()
{
	RECT Viewport = { 0, 0, 0, 0 };
	int w, h;
	Interfaces::Engine->GetScreenSize(w, h);
	Viewport.right = w; Viewport.bottom = h;
	return Viewport;
}

//RECT Render::GetViewport2()
//{
//	RECT Viewport = { 0, 0, 0, 0 };
//	int w, h;
//	Interfaces::Engine->GetScreenSize2(w, h);
//	Viewport.right = w; Viewport.bottom = h;
//	return Viewport;
//}

void Render::DrawRect(int x, int y, int w, int h, Color col)
{
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawFilledRect(x, y, x + w, y + h);
}
void Render::DrawLine(int x0, int y0, int x1, int y1, Color col)
{
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawLine(x0, y0, x1, y1);
}

void Render::DrawString2(DWORD font, int x, int y, Color color, DWORD alignment, const char* msg, ...)
{
	va_list va_alist;
	char buf[1024];
	va_start(va_alist, msg);
	_vsnprintf(buf, sizeof(buf), msg, va_alist);
	va_end(va_alist);
	wchar_t wbuf[1024];
	MultiByteToWideChar(CP_UTF8, 0, buf, 256, wbuf, 256);

	int r = 255, g = 255, b = 255, a = 255;
	color.GetColor(r, g, b, a);

	int width, height;
	Interfaces::Surface->GetTextSize(font, wbuf, width, height);

	if (alignment & FONT_RIGHT)
		x -= width;
	if (alignment & FONT_CENTER)
		x -= width / 2;

	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetTextColor(r, g, b, a);
	Interfaces::Surface->DrawSetTextPos(x, y - height / 2);
	Interfaces::Surface->DrawPrintText(wbuf, wcslen(wbuf));
}

void Render::Clear(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, x + w, y + h);
}

void Render::Outline(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawOutlinedRect(x, y, x + w, y + h);
}

void Render::Line(int x, int y, int x2, int y2, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawLine(x, y, x2, y2);
}


void Render::DrawOutlinedRect(int x, int y, int w, int h, Color col)
{
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawOutlinedRect(x, y, x + w, y + h);
}

void Render::DrawRectRainbow(int x, int y, int width, int height, float flSpeed, float &flRainbow)
{
	Color colColor(0, 0, 0);

	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;

	for (int i = 0; i < width; i++)
	{
		float hue = (1.f / (float)width) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;

		Color colRainbow = colColor.FromHSB(hue, 1.f, 1.f);
		Render::DrawRect(x + i, y, 1, height, colRainbow);
	}
}

void Render::Rect2(int x, int y, int w, int h, int r, int g, int b, int a)
{
	Color color = Color(r, g, b, a);
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, x + w, y + h);
}

void Render::Line2(int x, int y, int x2, int y2, Color color, DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);

	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawPrintText(wcstring, wcslen(wcstring));
	Interfaces::Surface->DrawLine(x, y, x2, y2);
}



void Render::Line3(Vector2D start_pos, Vector2D end_pos, Color col)
{
	Render::Line(start_pos.x, start_pos.y, end_pos.x, end_pos.y, col);
}

void Render::DrawCircle(float x, float y, float r, float segments, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r, segments);
}

void Render::PolyLine(int *x, int *y, int count, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawPolyLine(x, y, count);
}

bool Render::WorldToScreen(Vector &in, Vector &out)
{
	const matrix3x4& worldToScreen = Interfaces::Engine->WorldToScreenMatrix(); //Gracb the world to screen matrix from CEngineClient::WorldToScreenMatrix

	float w = worldToScreen[3][0] * in[0] + worldToScreen[3][1] * in[1] + worldToScreen[3][2] * in[2] + worldToScreen[3][3]; //Calculate the angle in compareson to the player's camera.
	out.z = 0; //Screen doesn't have a 3rd dimension.

	if (w > 0.001) //If the object is within view.
	{
		RECT ScreenSize = GetViewport();
		float fl1DBw = 1 / w; //Divide 1 by the angle.
		out.x = (ScreenSize.right / 2) + (0.5f * ((worldToScreen[0][0] * in[0] + worldToScreen[0][1] * in[1] + worldToScreen[0][2] * in[2] + worldToScreen[0][3]) * fl1DBw) * ScreenSize.right + 0.5f); //Get the X dimension and push it in to the Vector.
		out.y = (ScreenSize.bottom / 2) - (0.5f * ((worldToScreen[1][0] * in[0] + worldToScreen[1][1] * in[1] + worldToScreen[1][2] * in[2] + worldToScreen[1][3]) * fl1DBw) * ScreenSize.bottom + 0.5f); //Get the Y dimension and push it in to the Vector.
		return true;
	}

	return false;
}


void Render::OutlineCircle(int x, int y, int r, int seg, Color color)
{
	Interfaces::Surface->DrawSetColor(0, 0, 0, 255);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r - 1, seg);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r + 1, seg);
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r, seg);
}

/*bool Render::WorldToScreen2(Vector &in, Vector &out)
{
	const matrix3x4& worldToScreen = Interfaces::Engine->WorldToScreenMatrix(); //Gracb the world to screen matrix from CEngineClient::WorldToScreenMatrix

	float w = worldToScreen[3][0] * in[0] + worldToScreen[3][1] * in[1] + worldToScreen[3][2] * in[2] + worldToScreen[3][3]; //Calculate the angle in compareson to the player's camera.
	out.z = 0; //Screen doesn't have a 3rd dimension.

	if (w > 0.001) //If the object is within view.
	{
		RECT ScreenSize = GetViewport2();
		float fl1DBw = 1 / w; //Divide 1 by the angle.
		out.x = (ScreenSize.right / 2) + (0.5f * ((worldToScreen[0][0] * in[0] + worldToScreen[0][1] * in[1] + worldToScreen[0][2] * in[2] + worldToScreen[0][3]) * fl1DBw) * ScreenSize.right + 0.5f); //Get the X dimension and push it in to the Vector.
		out.y = (ScreenSize.bottom / 2) - (0.5f * ((worldToScreen[1][0] * in[0] + worldToScreen[1][1] * in[1] + worldToScreen[1][2] * in[2] + worldToScreen[1][3]) * fl1DBw) * ScreenSize.bottom + 0.5f); //Get the Y dimension and push it in to the Vector.
		return true;
	}

	return false;
} */

void Render::Text(int x, int y, Color color, DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);

	Interfaces::Surface->DrawSetTextFont(font);

	Interfaces::Surface->DrawSetTextColor(color);
	Interfaces::Surface->DrawSetTextPos(x, y);
	Interfaces::Surface->DrawPrintText(wcstring, wcslen(wcstring));
	return;
}

void Render::Text(int x, int y, Color color, DWORD font, const wchar_t* text)
{
	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetTextColor(color);
	Interfaces::Surface->DrawSetTextPos(x, y);
	Interfaces::Surface->DrawPrintText(text, wcslen(text));
}


void Render::Textf(int x, int y, Color color, DWORD font, const char* fmt, ...)
{
	if (!fmt) return; //if the passed string is null return
	if (strlen(fmt) < 2) return;

	//Set up va_list and buffer to hold the params 
	va_list va_alist;
	char logBuf[256] = { 0 };

	//Do sprintf with the parameters
	va_start(va_alist, fmt);
	_vsnprintf_s(logBuf + strlen(logBuf), 256 - strlen(logBuf), sizeof(logBuf) - strlen(logBuf), fmt, va_alist);
	va_end(va_alist);

	Text(x, y, color, font, logBuf);
}

void Render::DrawFilledCircle(Vector2D center, Color color, float radius, float points) {
	std::vector<Vertex_t> vertices;
	float step = (float)M_PI * 2.0f / points;

	for (float a = 0; a < (M_PI * 2.0f); a += step)
		vertices.push_back(Vertex_t(Vector2D(radius * cosf(a) + center.x, radius * sinf(a) + center.y)));

	DrawTexturedPoly((int)points, vertices.data(), color);
}

RECT Render::GetTextSize(DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);

	RECT rect; int x, y;
	Interfaces::Surface->GetTextSize(font, wcstring, x, y);
	rect.left = x; rect.bottom = y;
	rect.right = x;
	return rect;
}


void Render::GradientV(int x, int y, int w, int h, Color c1, Color c2)
{
	Clear(x, y, w, h, c1);
	BYTE first = c2.r();
	BYTE second = c2.g();
	BYTE third = c2.b();
	for (int i = 0; i < h; i++)
	{
		float fi = i, fh = h;
		float a = fi / fh;
		DWORD ia = a * 255;
		Clear(x, y + i, w, 1, Color(first, second, third, ia));
	}
}

void Render::GradientH(int x, int y, int w, int h, Color c1, Color c2)
{
	Clear(x, y, w, h, c1);
	BYTE first = c2.r();
	BYTE second = c2.g();
	BYTE third = c2.b();
	for (int i = 0; i < w; i++)
	{
		float fi = i, fw = w;
		float a = fi / fw;
		DWORD ia = a * 255;
		Clear(x + i, y, 1, h, Color(first, second, third, ia));
	}
}

void Render::Polygon(int count, Vertex_t* Vertexs, Color color)
{
	static int Texture = Interfaces::Surface->CreateNewTextureID(true); //need to make a texture with procedural true
	unsigned char buffer[4] = { 255, 255, 255, 255 };//{ color.r(), color.g(), color.b(), color.a() };

	Interfaces::Surface->DrawSetTextureRGBA(Texture, buffer, 1, 1); //Texture, char array of texture, width, height
	Interfaces::Surface->DrawSetColor(color); // keep this full color and opacity use the RGBA @top to set values.
	Interfaces::Surface->DrawSetTexture(Texture); // bind texture

	Interfaces::Surface->DrawTexturedPolygon(count, Vertexs);
}

void Render::DrawTexturedPoly(int n, Vertex_t* vertice, Color col) {
	static int texture_id = Interfaces::Surface->CreateNewTextureID(true);
	static unsigned char buf[4] = { 255, 255, 255, 255 };
	Interfaces::Surface->DrawSetTextureRGBA(texture_id, buf, 1, 1);
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawSetTexture(texture_id);
	Interfaces::Surface->DrawTexturedPolygon(n, vertice);
}

void Render::PolygonOutline(int count, Vertex_t* Vertexs, Color color, Color colorLine)
{
	static int x[128];
	static int y[128];

	Render::Polygon(count, Vertexs, color);

	for (int i = 0; i < count; i++)
	{
		x[i] = Vertexs[i].m_Position.x;
		y[i] = Vertexs[i].m_Position.y;
	}

	Render::PolyLine(x, y, count, colorLine);
}

/*void Render::DrawFilledCircle(Vector2D center, Color color, float radius, float points) {
	std::vector<Vertex_t> vertices;
	float step = (float)M_PI * 2.0f / points;

	for (float a = 0; a < (M_PI * 2.0f); a += step)
		vertices.push_back(Vertex_t(Vector2D(radius * cosf(a) + center.x, radius * sinf(a) + center.y)));

	DrawTexturedPoly((int)points, vertices.data(), color);
}*/

void Render::PolyLine(int count, Vertex_t* Vertexs, Color colorLine)
{
	static int x[128];
	static int y[128];

	for (int i = 0; i < count; i++)
	{
		x[i] = Vertexs[i].m_Position.x;
		y[i] = Vertexs[i].m_Position.y;
	}

	Render::PolyLine(x, y, count, colorLine);
}

//void Render::DrawOutlinedRect(int x, int y, int w, int h, Color col)
//{
//	Interfaces::Surface->DrawSetColor(col);
//	Interfaces::Surface->DrawOutlinedRect(x, y, x + w, y + h);
//}

void Render::DrawOutlinedCircle(int x, int y, int r, Color col)
{
	Interfaces::Surface->DrawSetColor(col);
	Interfaces::Surface->DrawOutlinedCircle(x, y, r, 1);
}

void Render::textW(bool center, int font, int x, int y, Color c, wchar_t *pszString)
{
	if (center)
	{
		int wide, tall;
		Interfaces::Surface->GetTextSize(font, pszString, wide, tall);
		x -= wide / 2;
		y -= tall / 2;
	}
	Interfaces::Surface->DrawSetTextColor(c);
	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetTextPos(x, y);
	Interfaces::Surface->DrawPrintText(pszString, (int)wcslen(pszString));
}

void Render::drawString(int font, bool bCenter, int x, int y, Color c, const char *fmt, ...)
{
	wchar_t *pszStringWide = reinterpret_cast< wchar_t* >(malloc((strlen(fmt) + 1) * sizeof(wchar_t)));

	mbstowcs(pszStringWide, fmt, (strlen(fmt) + 1) * sizeof(wchar_t));

	textW(bCenter, font, x, y, c, pszStringWide);

	free(pszStringWide);
}