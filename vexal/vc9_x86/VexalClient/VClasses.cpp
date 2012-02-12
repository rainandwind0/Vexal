/*
 * VClasses - Contains basic Vexal classes
 */

#include "VClasses.hpp"
#include "defs.hpp"
#include "logger.hpp"

#include <vector>
#include <iostream>

namespace vexal
{
	std::vector<vbit*> vbit::bits;

	vbit::vbit(vblocation bloc)
	{
		// Store the location
		offset = bloc;

		// Setup basic values
		glData.len = 0;
	}

	vblocation vbit::getLocation()
	{
		// Return
		return offset;
	}

	long vbit::getVoxelOffset(char x, char y, char z)
	{
		// Give them the long
		long ret;
		ret = x;
		ret = ret << 8;
		ret += y;
		ret = ret << 8;
		ret += z;
		return ret;
	}

	void vbit::getVoxelPosition(long offset, char &x, char &y, char &z)
	{
		// Find x
		x = (offset & 0xFF0000) >> 16;

		// Find y
		y = (offset & 0xFF00) >> 8;

		// Find z
		z = (offset & 0xFF);
	}

	char vbit::getVoxelType(char x, char y, char z)
	{
		// Return 
		return voxels[getVoxelOffset(x, y, z)];
	}

	void vbit::setVoxelType(char type, char x, char y, char z)
	{
		// Set
		voxels[getVoxelOffset(x, y, z)] = type;
	}

	void vbit::unload()
	{
		// Find n
		char n = -1;
		for(int i = 0; i < V_BITMEM_TOTAL; i++)
			if(bits[i] = this)
				n = i;

		// If not loaded
		if(n < 0)
			return;

		// Unload
		bits.erase(bits.begin() + n);
	}

	void vbit::load()
	{
		// Check size
		if(bits.size() >= V_BITMEM_TOTAL)
			recalcVectors();


		// Add
		bits.push_back(this);
	}

	void vbit::calculatePolys()
	{
		// Re-init cache
		_initGLCache();
	}

	void vbit::_initGLCache()
	{
		const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};


		glGenBuffers(1, &glData.uint);

		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, glData.uint);

		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		/*// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &glData.uint);

		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, glData.uint);

		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(glData.data), glData.data, GL_STATIC_DRAW);*/
	}

	void vbit::recalcVectors()
	{
		// For right now, nothing can be done because
		// this requires a position for reloading bits
		// For now, error out!
		e("CANNOT RECALC VECTORS! NOT IMPLEMENTED!");
		//exit(1);
	}
}