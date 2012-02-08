/*
 * config Header
 */
#ifndef CONFIG_H__
#define CONFIG_H__

#include "libconfig.h++"

#include <fstream>

using namespace libconfig;

namespace vexal
{
	class Config
	{
	public:
		/**
		 * Generates a singleton instance of the Config class
		 */
		static void GenInst();

		static char* GetString(const char* node);

	private:
		Config();
		~Config();

		std::ofstream hFile;
		Config config;

		static Config* inst;
	};
}

#endif