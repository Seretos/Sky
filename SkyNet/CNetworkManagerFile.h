#pragma once
#include "CNetworkManager.h"
#include <string>
#include <iostream>
#include <fstream>

#if defined(_WIN32)
#ifdef CNETWORKMANAGERFILE_EXPORTS
#define CNETWORKMANAGERFILE_API __declspec(dllexport)
#else
#define CNETWORKMANAGERFILE_API __declspec(dllimport)
#endif
#else
#define CNETWORKMANAGERFILE_API
#endif

class CNetworkManagerFile {
public:
	CNETWORKMANAGERFILE_API CNetworkManager* loadNetwork(std::string fileName);
	CNETWORKMANAGERFILE_API void saveNetwork(CNetworkManager* network, std::string fileName);
private:
	int saveNeurons(std::ofstream* fileStream, CLayer* layer, int index=0);
	void saveSynapses(std::ofstream* fileStream, CLayer* layer);

	std::vector<std::string> parseLine(std::string line);

	int lineMode(std::string column, int currentMode, CNetworkManager* manager);
	INeuron* createTypeNeuron(std::string saveId,std::string type, std::string threshold);
	ISynapse* createTypeSynapse(CNetworkManager* manager, std::string type, std::string source, std::string target, std::string weight);
};
