/*
 * Console - allocates a console and redirects stdi/o/e to it
 */
#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "defs.h"

namespace vexal
{
	

	void __stdcall VAttachConsole()
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		freopen("CON", "w", stdout);

		// Begin old code

		/*CONSOLE_SCREEN_BUFFER_INFO conInfo;
		HANDLE hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		// Allocate a console
		AllocConsole();

		// Set the screen buffer
		GetConsoleScreenBufferInfo(hStdHandle, &conInfo);
		conInfo.dwSize.Y = V_CONSOLE_SCROLLBACK;
		SetConsoleScreenBufferSize(hStdHandle, conInfo.dwSize);

		// Redirect STDOUT to console
		int hConHandle = _open_osfhandle((long)hStdHandle, _O_TEXT);
		FILE* fp = _fdopen(hConHandle, "w");
		*stdout = *fp;
		setvbuf(stdout, NULL, _IONBF, 0);

		// Redirect STDIN to console
		hStdHandle = GetStdHandle(STD_INPUT_HANDLE);
		hConHandle = _open_osfhandle((long)hStdHandle, _O_TEXT);
		fp = _fdopen(hConHandle, "r");
		*stdin = *fp;
		setvbuf(stdin, NULL, _IONBF, 0);

		// Redirect STDERR to console
		hStdHandle = GetStdHandle(STD_ERROR_HANDLE);
		hConHandle = _open_osfhandle((long)hStdHandle, _O_TEXT);
		fp = _fdopen(hConHandle, "w");
		*stderr = *fp;
		setvbuf(stderr, NULL, _IONBF, 0);

		// Sync with IO (cin, cout, etc)
		std::ios::sync_with_stdio();*/
	}



}