/*
 * VCLasses Header
 */
#ifndef VCLASSES_H__
#define VCLASSES_H__

#include "defs.hpp"

#include <vector>

namespace vexal
{
	typedef long vvlocation;

	struct voglfltdata
	{
		/**
		 * Pointer to the FIRST element array
		 */
		GLfloat* data;

		/**
		 * Number of points (x, y, z) in array
		 */
		unsigned int len;
		GLuint uint;
	};

	struct vblocation
	{
		union
		{
			char c;
			short s;
			long l;
		}x, y, z;
	};

	class vbit
	{
	public:
		/**
		 * Gets the voxel type at a specific position within the Bit
		 */
		char getVoxelType(char x, char y, char z);

		/**
		 * Sets the voxel type at a specific position within the Bit
		 */
		void setVoxelType(char type, char x, char y, char z);

		/**
		 * Unloads the Bit from memory
		 */
		void unload();

		/**
		 * Loads this chunk into the register
		 */
		void load();

		/**
		 * Gets the Bit location
		 */
		vblocation getLocation();

		/**
		 * Gets the specified long offset of a specific voxel in the Bit
		 */
		static long getVoxelOffset(char x, char y, char z);
		
		/**
		 * Returns the x,y,z position from a long offset in a Bit
		 */
		static void getVoxelPosition(long offset, char &x, char &y, char &z);

		/**
		 * Creates a vbit object at the specified location
		 */
		vbit(vblocation bloc);

		/**
		 * Cleans up the loaded bits and unloads any unnecessary bits from the stack
		 */
		static void recalcVectors();

		/**
		 * Recalculates a Bit's polys from the loaded data
		 */
		void calculatePolys();

		/**
		 * The raw voxel data
		 */
		unsigned char voxels[V_BITMEM_VTOTAL];

		voglfltdata glData;

		static std::vector<vbit*> bits;
	protected:
		vblocation offset;
		void _initGLCache();
	};
}

#endif