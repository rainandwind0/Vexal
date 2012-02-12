/*
 * VCLasses Header
 */
#ifndef VCLASSES_H__
#define VCLASSES_H__

namespace vexal
{
	typedef long vvloc;

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
		void setVoxelType(char x, char y, char z);

		/**
		 * Unloads the Bit from memory
		 */
		void unload();

		/**
		 * Gets the Bit location
		 */
		vblocation getLocation();

		/**
		 * Gets the specified long offset of a specific voxel in the Bit
		 */
		long getVoxelOffset(char x, char y, char z);
		
		/**
		 * Returns the x,y,z position from a long offset in a Bit
		 */
		void getVoxelPosition(long offset, char &x, char &y, char &z);

		char voxels[16777216];
	protected:
		static vbit* bits = new vbit[25]; 
	};
}

#endif