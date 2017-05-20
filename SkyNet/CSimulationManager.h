#pragma once
#include <vector>
#include "CNetworkManager.h"

#ifdef CSIMULATIONMANAGER_EXPORTS
#define CSIMULATIONMANAGER_API __declspec(dllexport) 
#else
#define CSIMULATIONMANAGER_API __declspec(dllimport) 
#endif

class CSimulationManager {
public:
	CSimulationManager();
	~CSimulationManager();

	CSIMULATIONMANAGER_API int addNetwork(CNetworkManager* network);
	CSIMULATIONMANAGER_API void removeNetwork(CNetworkManager* network);

	CSIMULATIONMANAGER_API void run();
protected:
	std::vector<CNetworkManager*> networks;
};