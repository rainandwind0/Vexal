/*
 * Logger - handles logging/output functions
 */

#include "logger.hpp"
#include "console.hpp"
#include "defs.hpp"

#include <Windows.h>
#include <iostream>
#include <fstream>

#if V_LOG > 0

namespace vexal
{
	// Define static instance
	#if V_LOG != 2

	Log* Log::inst;

	void Log::_VLogInit()
	{
		// Create instance if needed
		if(!Log::inst)
			Log::inst = new Log();
	}
	#endif

	void Log::msgInd(const char* tag, const char* msg)
	{
		// Check log level
		#if V_LOG == 3
			std::cout << tag << msg << std::endl;
		#elif V_LOG == 2
			OutputDebugString(tag);
			OutputDebugString(msg);
			OutputDebugString("\n");
		#elif V_LOG == 1
			(*(inst->flLog)) << tag << msg << std::endl;
		#endif
	}

	#if V_LOG != 2
	Log::Log()
	{
		// Check log type
		#if V_LOG == 3
			vexal::VAttachConsole();
		#elif V_LOG == 1
			flLog = new std::ofstream("vexal.log", std::ios::out | std::ios::trunc);
		#endif
	}
	#endif

	#if V_LOG == 1
	Log::~Log()
	{
		// Close log if needed
		if(flLog->is_open())
		{
			// Close handle
			flLog->close();

			// Delete reference
			delete flLog;
		}
	}
	#endif
}

#endif