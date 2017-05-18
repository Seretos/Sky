#pragma once

#include "INetwork.h"
#include "ISynapse.h"
#include "CSimpleNetworkBuilder.h"

#ifdef SKYNETFACTORY_EXPORTS
#define SKYNETFACTORY_API __declspec(dllexport) 
#else
#define SKYNETFACTORY_API __declspec(dllimport) 
#endif

class CSkyNetFactory
{
public:
	CSkyNetFactory();
	~CSkyNetFactory();

	static SKYNETFACTORY_API INetwork* createNetwork();
	static SKYNETFACTORY_API INeuron* createNeuron();
	static SKYNETFACTORY_API INeuron* createBinaerNeuron();

	static SKYNETFACTORY_API ISynapse* createSynapse(INeuron* source, INeuron* destination, double weight = 0.5);
	static SKYNETFACTORY_API CSimpleNetworkBuilder* createSimpleNetworkBuilder();
	static SKYNETFACTORY_API CLayer* createLayer();
};

