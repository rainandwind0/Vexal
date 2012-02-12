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
#include "OGLMain.hpp"
#include "VClasses.hpp"
#include <sstream>

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

	// Startup main OpenGL window thread
	if(!OGLMain())
		return GetLastVError();
	else // Log that we succeeded!
		f1("OGLMain succeeded!");

	// All okay!
	i("Vexal Online is shutting down!");
	f1("Terminating Program.");
	return V_SUCCESS;
}
