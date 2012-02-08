/*
 * Logger - handles logging/output functions
 */

#include "logger.h"
#include "console.h"
#include "defs.h"

#include <Windows.h>
#include <iostream>
#include <fstream>

#if V_LOG > 0

namespace vexal
{
	// Define static members
	Log* Log::inst;

	void Log::_VLogInit(int level)
	{
		// Create instance if needed
		if(!Log::inst)
			Log::inst = new Log(level);
	}

	void Log::msgInd(const char* tag, const char* msg, int level)
	{
		// Switch level
		switch(level)
		{
		case 3: // Output to console
			std::cout << tag << msg << std::endl;
			break;
		case 2: // Output to debugger
			OutputDebugString(tag);
			OutputDebugString(msg);
			OutputDebugString("\n");
			break;
		case 1: // Output to log file
			(*(inst->flLog)) << tag << msg << std::endl;
			break;
		}
	}

	Log::Log(int type)
	{
		// Store level
		lv = type;

		// Check log type
		switch(type)
		{
		case 3: // Console Output (Attach Console)
			vexal::VAttachConsole();
			break;
		case 1: // File logging (Create log file)
			flLog = new std::ofstream("vexal.log", std::ios::out | std::ios::trunc);
			break;
		}
	}

	Log::~Log()
	{
		// Close log if needed
		if(lv > 0 && flLog->is_open())
		{
			// Close handle
			flLog->close();

			// Delete reference
			delete flLog;
		}
	}
}

#endif