/*
 * config - Handles configuration from the config file
 */

#include <iostream>
#include <fstream>

#include "config.hpp"
#include "libconfig.h++"
#include "defs.hpp"
#include "logger.hpp"
#include "verror.hpp"

using namespace std;

namespace vexal
{	
	// Declare
	Config* Config::inst;

	void Config::GenInst()
	{
		// Create instance if we haven't already
		if(!inst)
			inst = new Config();
	}

	Config::Config()
	{
		// Create config and attempt to load config
		config = new libconfig::Config();

		// Touch file (ooOOH!)
		touch();

		try
		{
			// Try to read config file
			config->readFile("vexal.cfg");
		}
		catch(...)
		{
			// Echo that there was an error
			e("Could not read config file!");
			SetVError(V_ERR_CFG_UNKNOWNERR);
			return;
		}
	
		config->getRoot().add("testentry", libconfig::Setting::TypeString) = "This is a test!";

		config->writeFile("vexal.cfg");
	}

	void Config::touch()
	{
		// Open
		std::ofstream f("vexal.cfg", std::ios::ate | std::ios::app | std::ios::out);
		
		// Close
		f.close();
	}
}