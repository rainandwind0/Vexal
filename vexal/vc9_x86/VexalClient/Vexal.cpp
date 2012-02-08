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

#include "gl/glfw.h"
#include "glm/glm.hpp"
#include "logger.h"
#include "defs.h"

using namespace glm;
using namespace vexal;
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevious, LPSTR lpComString, int nShowCmd)
{
	// Generate logger instance (instantiate logging)
	VLogInit();

	// Test log
	for(int i = 0; i < 100; i++)
		i("Hello, linux!");

	Sleep(5000);

	// All okay!
	return 0;
}