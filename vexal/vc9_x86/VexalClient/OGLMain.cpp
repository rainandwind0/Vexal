/*
 * OGLMain - handles the main OpenGL window/processing loop
 */

#include "OGLMain.hpp"
#include "defs.hpp"
#include "OGLBasic.hpp"
#include "VClasses.hpp"

#include "gl/glfw.h"

#include <Windows.h>

namespace vexal
{
	bool __stdcall OGLMain()
	{
		// Start main loop
		do
		{
			// Draw Bits
			vDrawVexals();

			// Swap the buffers
			glfwSwapBuffers();
		} // Escape key or window closed
		while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));


		// Return the all-okay!
		return V_SUCCESS;
	}
}