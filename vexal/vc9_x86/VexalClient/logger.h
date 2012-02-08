/*
 * Logger header
 */
#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>

#include "defs.h"

// Log macros (Helps cut down on overhead
//     when we don't need logging)
#if V_LOG == 0
	#define VLogInit()
	#define i(a) 
#else
	/**
	 * Initializes the logging instance
	 */
	#define VLogInit() vexal::Log::_VLogInit(V_LOG)

	/**
	 * Logs an info message
	 */
	#define i(a) vexal::Log::li(a, V_LOG)

namespace vexal
{
	// Main logger class
	class Log
	{
	public:
		static void _VLogInit(int level);
		static void li(const char * msg, int level);
	private:
		Log(int v);
		~Log();

		static Log* inst;

		void _msgInd(const char* tag, const char* msg, int level);
		std::ofstream* flLog;
		int lv;
	};

}

#endif
#endif