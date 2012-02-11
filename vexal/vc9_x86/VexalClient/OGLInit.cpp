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
	/* Handle key strokes */
	void GLFWCALL handle_key_down(int key, int action)
	{
		if( action != GLFW_PRESS )
		{
			return;
		}

		switch(key) {
	default:
		break;
		}
	}

	bool __stdcall OGLStartup()
	{
		// Attempt to start up GLFW
		f1("Attempting to start up GLFW");
		if(!glfwInit())
		{
			e("Could not start up GLFW!");
			SetVError(V_ERR_OGL_GLFWINIT);
			return false;
		}

		// Create window hints
		f1("Setting window hints");
		glfwOpenWindowHint(GLFW_FSAA_SAMPLES, V_OGL_ANTIALIAS);
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3); // We want 4.0!
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
		glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Create the window
		f1("Creating main window");
		if(!glfwOpenWindow(V_OGL_WINDOW_W, V_OGL_WINDOW_H, 0,0,0,0,16,0, GLFW_WINDOW))
		{
			e("Could not create main window!");
			SetVError(V_ERR_OGL_WINDOW);
			glfwTerminate();
			return false;
		}

		// Attempt to start up Glew
		f1("Attempting to startup Glew");
		if(glewInit() != GLEW_OK)
		{
			// Error and return
			e("Could not instantiate Glew!");
			SetVError(V_ERR_OGL_GLEWINIT);
			return false;
		}

		// Set the window's title
		f1("Setting window title");
		glfwSetWindowTitle(V_WINDOW_TITLE);

		glfwSetKeyCallback( handle_key_down );
		glfwEnable(GLFW_KEY_REPEAT);

		glfwSwapInterval( 1 );

		// Clear the screen / set BG color
		f1("Clearing background");
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		// Lastly, setup basic sticky keys
		f1("Enabling sticky keys");
		glfwEnable(GLFW_STICKY_KEYS);

		
		
		// All is good
		return true;
	}

}