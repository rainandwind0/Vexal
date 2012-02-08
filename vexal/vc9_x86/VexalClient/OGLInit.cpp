/*
 * OGLInit - All of the initial graphics handling
 */

#include "defs.hpp"
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

		// Create window hints
		glfwOpenWindowHint(GLFW_FSAA_SAMPLES, V_OGL_ANTIALIAS);
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 4); // We want 4.0!
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 0);
		glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Create the window
		if(!glfwOpenWindow(V_OGL_WINDOW_W, V_OGL_WINDOW_H, 0, 0, 0 ,0, 32, 0, GLFW_WINDOW))
		{
			e("Could not create main window!");
			SetVError(V_ERR_OGL_WINDOW);
			return false;
		}

		// Attempt to start up Glew
		if(!glewInit())
		{
			// Error and return
			e("Could not instantiate Glew!");
			SetVError(V_ERR_OGL_GLEWINIT);
			return false;
		}

		// All is good
		return true;
	}

}