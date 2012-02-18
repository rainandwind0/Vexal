/*
 * VContentServer - Handles the content serving (either from SP or MP) for the game
 */

#include "VContentServer.h"

namespace vexal
{
	VContentServer* VContentServer::inst;

	VContentServer VContentServer::get()
	{
		// Check
		if(!VContentServer::inst)
			inst = new VContentServer();

		// Return
		return *inst;
	}

}