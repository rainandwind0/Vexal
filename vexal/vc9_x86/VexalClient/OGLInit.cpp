/*
 * OGLInit - All of the initial graphics handling
 */

#include "logger.hpp"
#include "verror.hpp"
#include "GL/glew.h"
#include "GL/glfw.h"

namespace vexal
{
	
	bool __stdcall OGLStartup()
	{
		// Attempt to start up GLFW
		if(!glfwInit())
		{
			e("Could not start up GLFW!");
			SetVError(V_ERR_OGL_GLFWINIT);
			return false;
		}

		// Attempt to start up Glew
		if(!glewInit())
		{
			e("Could not instantiate Glew!");
			SetVError(V_ERR_OGL_GLEWINIT);
			return false;
		}

		// All is good
		return true;
	}

}