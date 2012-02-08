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
	#define VLogInit() vexal::Log::_VLogInit(V_LOG)

	/**
	 * Logs an info message
	 */
	#define i(a) vexal::Log::msgInd("[INFO] ", a, V_LOG)

	/**
	 * Logs a warning message
	 */
	#define w(a) vexal::Log::msgInd("[WARNING] ", a, V_LOG)

	/**
	 * Logs an error message
	 */
	#define e(a) vexal::Log::msgInd("[ERROR] ", a, V_LOG)

	/**
	 * Logs a fine-level message
	 */
	#define f1(a) vexal::Log::msgInd("[FINE] ", a, V_LOG)

	/**
	 * Logs a finer-level message
	 */
	#define f2(a) vexal::Log::msgInd("[FINER] ", a, V_LOG)

	/**
	 * Logs a finest-level message
	 */
	#define f3(a) vexal::Log::msgInd("[FINEST] ", a, V_LOG)

	/**
	 * Logs a config message
	 */
	#define cfg(a) vexal::Log::msgInd("[CONFIG] ", a, V_LOG)

namespace vexal
{
	// Main logger class
	class Log
	{
	public:
		static void _VLogInit(int level);
		static void msgInd(const char* tag, const char* msg, int level);
	private:
		Log(int v);
		~Log();

		static Log* inst;

		std::ofstream* flLog;
		int lv;
	};

}

#endif
#endif