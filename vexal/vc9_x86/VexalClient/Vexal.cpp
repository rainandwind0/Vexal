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

#include "logger.h"
#include "vversion.h"
#include "OGLInit.h"

using namespace std;
using namespace vexal;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevious, LPSTR lpComString, int nShowCmd)
{
	// Generate logger instance (instantiate logging)
	VLogInit();

	// Log Title + Version
	i("Vexal Online "V_FULLVERSION);
	
	// Init OpenGL/Graphics
	if(OGLStartup() > 0)
		return 1;
	else
		f1("OGLStartup succeeded!");
	
	// All okay!
	f1("Terminating Program");
	return 0;
}