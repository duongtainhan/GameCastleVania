#pragma once
#include<map>
using namespace std;

#define GLOBALS_D(name) GameConfiguration::GetConfiguration(name)
#define GLOBALS_S(name) GameConfiguration::GetConfigurationString(name)

class GameConfiguration
{
	static map<const char*, double>* globalsConfigurationDouble;
	static map<const char*, const char*>* globalsConfigurationString;
public:

	static double GetConfiguration(const char* key);
	static const char* GetConfigurationString(const char* key);
	GameConfiguration();
	~GameConfiguration();
};
