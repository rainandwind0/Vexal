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
		// TEST BIT
		vblocation loc = {0, 0, 0};
		vbit* testbit = new vbit(loc);


		GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};

		testbit->glData.data = &g_vertex_buffer_data[0];
		testbit->glData.len = 3;
		testbit->calculatePolys();

		testbit->load();


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