/*  __   __   ______     __  __     ______     __        
 * /\ \ / /  /\  ___\   /\_\_\_\   /\  __ \   /\ \       
 * \ \ \ /   \ \  __\   \/_/\_\/_  \ \  __ \  \ \ \____  
 *  \ \__|    \ \_____\   /\_\/\_\  \ \_\ \_\  \ \_____\ 
 *   \/_/      \/_____/   \/_/\/_/   \/_/\/_/   \/_____/ 
 *                                  ~ONLINE~
 *
 *
 *	To answer all of your "can I?" questions: No.
 *
 *  /legal
 *
 *
 *                          With love,
 *                              Qix
 */
#include <Windows.h>
#include <iostream>

#include "logger.hpp"
#include "vversion.hpp"
#include "OGLInit.hpp"
#include "verror.hpp"

#include "gl/glew.h"
#include "gl/glfw.h"

using namespace std;
using namespace vexal;

/*
 * The main window thread handle
 */
LPDWORD thMainWindow;
HANDLE hMainWindow;

/*
 * Thread callback for the main window
 */
DWORD tcbMainWindow(LPVOID lpdwThreadParam);

/*
 * Main entry point
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevious, LPSTR lpComString, int nShowCmd)
{
	// Generate logger instance (instantiate logging)
	VLogInit();

	// Log Title + Version
	i("Vexal Online "V_FULLVERSION);

	// Init OpenGL/Graphics
	if(!OGLStartup())
		return GetLastVError();
	else // Log that we succeeded
		f1("OGLStartup succeeded!");
	
	// Fork thread for window events
	hMainWindow = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tcbMainWindow, NULL, 0, thMainWindow);
	
	// Alloc statuc
	DWORD status;

	// Wait for all threads to return
	while(true)
	{
		// Main Window
		GetExitCodeThread(hMainWindow, &status);
		if(status != STILL_ACTIVE)
			break;

		// Sleep for a little bit
		Sleep(10);
	}

	// All okay!
	f1("Terminating Program");
	return V_SUCCESS;
}

DWORD tcbMainWindow(LPVOID lpdwThreadParam)
{
	// Begin window loop
	do
	{
		// Swap buffers
		glfwSwapBuffers();


	} // Escape key or window closed
	while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

	// Success!
	return V_SUCCESS;
}