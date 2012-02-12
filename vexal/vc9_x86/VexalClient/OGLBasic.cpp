/*
 * OGLBasic - basic drawing functions 
 */

#include <vector>

#include "OGLBasic.hpp"
#include "VClasses.hpp"
#include "logger.hpp"

#include "gl/glew.h"
#include "gl/glfw.h"

using namespace std;

namespace vexal
{

	void __stdcall vDrawVexals()
	{
		// Iterate through vbits vector
		for(vector<vbit*>::iterator i = vbit::bits.begin(); i < vbit::bits.end(); i++)
		{
			voglfltdata d = (*i)->glData;

			// Test for 0 val (empty buffers)
			if(d.len < 1)
				continue;

			f3("Starting draw");

			// 1rst attribute buffer : vertices
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, d.uint);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
				);

			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, d.len); // Starting from vertex 0; 3 vertices total -> 1 triangle

			glDisableVertexAttribArray(0);
		}
	}

}