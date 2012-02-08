/*
 * verror - Handles the error stack (conveniance system)
 */

#include "verror.hpp"

namespace vexal
{

	// Define vError
	long vError = 0;

	void __stdcall SetVError(long err)
	{
		// Set the error
		vError = err;
	}

	long __stdcall GetLastVError()
	{
		// Return the result of GLVE(bool)
		return GetLastVError(true);
	}

	long __stdcall GetLastVError(bool clear)
	{
		// If we need to clear it (set it back to 0)
		if(clear)
		{
			// Make a clone
			long ve = vError;

			// Clear
			vError = 0;

			// Return
			return vError;
		}
		
		// Just return!
		return vError;
	}

}