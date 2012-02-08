/*
 * OGLInit - All of the initial graphics handling
 */

#include "logger.h"
#include "GL/glfw.h"

namespace vexal
{
	
	int __stdcall OGLStartup()
	{
		// Attempt to start up GLFW
		if(!glfwInit())
		{
			e("Could not start up GLFW!");
			return 1;
		}

		// All is good
		return 0;
	}

}