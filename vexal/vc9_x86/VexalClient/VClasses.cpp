/*
 * VClasses - Contains basic Vexal classes
 */

#include "VClasses.hpp"
#include "defs.hpp"
#include "logger.hpp"

#include <vector>

namespace vexal
{
	std::vector<vbit*> vbit::bits(V_BITMEM_TOTAL);

	vbit::vbit(vblocation bloc)
	{
		// Store the location
		offset = bloc;
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

	void vbit::recalcVectors()
	{
		// For right now, nothing can be done because
		// this requires a position for reloading bits
		// For now, error out!
		e("CANNOT RECALC VECTORS! NOT IMPLEMENTED!");
		exit(1);
	}
}