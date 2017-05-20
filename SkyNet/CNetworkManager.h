#pragma once
#include "INetwork.h"
#include "CLayer.h"
#include <vector>

#ifdef CNETWORKMANAGER_EXPORTS
#define CNETWORKMANAGER_API __declspec(dllexport) 
#else
#define CNETWORKMANAGER_API __declspec(dllimport) 
#endif

class CNetworkManager {
public:
	CNetworkManager(INetwork* network);
	~CNetworkManager();

	CNETWORKMANAGER_API void setInputLayer(CLayer* layer);
	CNETWORKMANAGER_API CLayer* getInputLayer();

	CNETWORKMANAGER_API int addHiddenLayer(CLayer* layer);
	CNETWORKMANAGER_API CLayer* getHiddenLayer(int index);
	CNETWORKMANAGER_API int getHiddenLayerSize();

	CNETWORKMANAGER_API void setOutputLayer(CLayer* layer);
	CNETWORKMANAGER_API CLayer* getOutputLayer();

	CNETWORKMANAGER_API void autoConnectLayers();

	CNETWORKMANAGER_API void run();

	INetwork* getNetwork();

	INeuron* findNeuronBySaveId(int id);
protected:
	void connectLayers(CLayer* lastLayer, CLayer* currentLayer);
	INetwork* network;
	CLayer* inputLayer;
	std::vector<CLayer*> hiddenLayers;
	CLayer* outputLayer;
};