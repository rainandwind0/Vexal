/*
 * config Header
 */
#ifndef CONFIG_H__
#define CONFIG_H__

#include "libconfig.h++"

#include <fstream>


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
		static char* GetString(const char* node, const char* def);
		
		static int GetInt(const char* node);
		static int GetInt(const char* node, int def);

		static int GetBool(const char* node);
		static int GetBool(const char* node, bool def);

	private:
		Config();
		~Config();

		void touch();

		std::ofstream hFile;
		libconfig::Config* config;

		static Config* inst;
	};
}

#endif