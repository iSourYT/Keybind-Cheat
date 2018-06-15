

#pragma once

#include "Interfaces.h"
#include "Vector2D.h"

void Quad();

enum FontRenderFlag_t
{
	FONT_LEFT = 0,
	FONT_RIGHT = 1,
	FONT_CENTER = 2
};

namespace Render
{
	void Initialise();

	// Normal Drawing functions
	void Clear(int x, int y, int w, int h, Color color);
	void Outline(int x, int y, int w, int h, Color color);
	void Line(int x, int y, int x2, int y2, Color color);
	void Rect2(int x, int y, int w, int h, int r, int g, int b, int a);
	void Line2(int x, int y, int x2, int y2, Color color, DWORD font, const char * text);
	void Line3(Vector2D start_pos, Vector2D end_pos, Color col);
	void DrawFilledCircle(Vector2D center, Color color, float radius, float points);
	void DrawTexturedPoly(int n, Vertex_t * vertice, Color col);
	void DrawCircle(float x, float y, float r, float segments, Color color);
	void PolyLine(int *x, int *y, int count, Color color);
	void Polygon(int count, Vertex_t* Vertexs, Color color);
	void PolygonOutline(int count, Vertex_t* Vertexs, Color color, Color colorLine);
	void PolyLine(int count, Vertex_t* Vertexs, Color colorLine);

	void DrawLine(int x0, int y0, int x1, int y1, Color col);
	void DrawString2(DWORD font, int x, int y, Color color, DWORD alignment, const char * msg, ...);
	void DrawLinePH(int x0, int y0, int x1, int y1);
	void DrawRect(int x, int y, int w, int h, Color col);

	void DrawOutlinedRect(int x, int y, int w, int h, Color col);

	void DrawRectRainbow(int x, int y, int width, int height, float flSpeed, float & flRainbow);

	void DrawOutlinedCircle(int x, int y, int r, Color col);

	void textW(bool center, int font, int x, int y, Color c, wchar_t * pszString);

	void textW(bool center, int font, int x, int y, int x2, int y2, Color c, wchar_t * pszString);



	void drawString(int font, bool bCenter, int x, int y, Color c, const char * fmt, ...);

	// Gradient Functions
	void GradientV(int x, int y, int w, int h, Color c1, Color c2);
	void GradientH(int x, int y, int w, int h, Color c1, Color c2);

	// Text functions
	namespace Fonts
	{
		extern DWORD Default;
		extern DWORD Menu;
		extern DWORD MenuBold;
		extern DWORD ESP;
		extern DWORD ICON;
		extern DWORD IconFont;
		extern DWORD WaterMark;
		extern DWORD WaterMark2;
		extern DWORD MenuText;
		extern DWORD Watermark;
		extern DWORD MenuTAB;
		extern DWORD MenuSymbols;
	};

	void Text(int x, int y, Color color, DWORD font, const char* text);
	void Textf(int x, int y, Color color, DWORD font, const char* fmt, ...);
	void Text(int x, int y, Color color, DWORD font, const wchar_t* text);
	void Text2(int x, int y, int x2, int y2, Color color, DWORD font, const wchar_t * text, const char * fmt, ...);
	void Text2(int x, int y, int x2, int y2, Color color, DWORD font, const wchar_t * text);
	RECT GetTextSize(DWORD font, const char* text);

	// Other rendering functions
	bool WorldToScreen(Vector &in, Vector &out);
	void OutlineCircle(int x, int y, int r, int seg, Color color);
	bool WorldToScreen2(Vector & in, Vector & out);
	RECT GetViewport();
	//RECT GetViewport2();
};

