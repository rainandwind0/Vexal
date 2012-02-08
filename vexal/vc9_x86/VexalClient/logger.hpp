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
	#define e(a)
	#define w(a)
	#define f1(a)
	#define f2(a)
	#define f3(a)
	#define cfg(a)
#else
	/**
	 * Initializes the logging instance
	 */
	#if V_LOG !=2
		#define VLogInit() vexal::Log::_VLogInit()
	#else
		#define VLogInit()
	#endif
	/**
	 * Logs an info message
	 */
	#define i(a) vexal::Log::msgInd("[INFO] ", a)

	/**
	 * Logs a warning message
	 */
	#define w(a) vexal::Log::msgInd("[WARNING] ", a)

	/**
	 * Logs an error message
	 */
	#define e(a) vexal::Log::msgInd("[ERROR] ", a)

	/**
	 * Logs a fine-level message
	 */
	#define f1(a) vexal::Log::msgInd("[FINE] ", a)

	/**
	 * Logs a finer-level message
	 */
	#define f2(a) vexal::Log::msgInd("[FINER] ", a)

	/**
	 * Logs a finest-level message
	 */
	#define f3(a) vexal::Log::msgInd("[FINEST] ", a)

	/**
	 * Logs a config message
	 */
	#define cfg(a) vexal::Log::msgInd("[CONFIG] ", a)

namespace vexal
{
	// Main logger class
	class Log
	{
	public:
#if V_LOG != 2
		static void _VLogInit();
#endif
		static void msgInd(const char* tag, const char* msg);
	private:
#if V_LOG != 2
		Log();
		static Log* inst;
#endif

#if V_LOG == 1
		~Log();
		std::ofstream* flLog;
#endif
	};

}

#endif
#endif