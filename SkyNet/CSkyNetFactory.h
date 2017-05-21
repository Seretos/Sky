#pragma once

#include "INeuron.h"
#include "INetwork.h"
#include "CNetworkManager.h"
#include "CSimulationManager.h"
#include "CNetworkManagerFile.h"

#if defined(_WIN32)
#ifdef SKYNETFACTORY_EXPORTS
#define SKYNETFACTORY_API __declspec(dllexport)
#else
#define SKYNETFACTORY_API __declspec(dllimport)
#endif
#else
#define SKYNETFACTORY_API
#endif

class CSkyNetFactory
{
public:
	CSkyNetFactory();
	~CSkyNetFactory();

	static SKYNETFACTORY_API INetwork* createNetwork();
	static SKYNETFACTORY_API INeuron* createNeuron();
	static SKYNETFACTORY_API INeuron* createBinaerNeuron();
	static SKYNETFACTORY_API INeuron* createBiasNeuron();
	static SKYNETFACTORY_API INeuron* createLogisticNeuron();
	static SKYNETFACTORY_API INeuron* createTanhNeuron();

	static SKYNETFACTORY_API ISynapse* createSynapse(INeuron* source, INeuron* destination, double weight = 0.5);
	static SKYNETFACTORY_API ISynapse* createAssoziationSynapse(INeuron* source, INeuron* destination, double weight = 0.5);
	static SKYNETFACTORY_API CLayer* createLayer(INetwork* network);

	static SKYNETFACTORY_API CNetworkManager* createNetworkManager(INetwork* network);
	static SKYNETFACTORY_API CSimulationManager* createSimulationManager();
	static SKYNETFACTORY_API CNetworkManagerFile* createNetworkManagerFile();
};

