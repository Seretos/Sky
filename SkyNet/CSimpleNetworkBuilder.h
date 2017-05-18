#pragma once

#ifdef CSIMPLENETWORKBUILDER_EXPORTS
#define CSIMPLENETWORKBUILDER_API __declspec(dllexport) 
#else
#define CSIMPLENETWORKBUILDER_API __declspec(dllimport) 
#endif

#include "INetwork.h"
#include "CLayer.h"
#include <vector>

class CSimpleNetworkBuilder {
public:
	CSimpleNetworkBuilder();

	CSIMPLENETWORKBUILDER_API void build(int inputs, int outputs);

	CSIMPLENETWORKBUILDER_API void input(double* inputs);
	CSIMPLENETWORKBUILDER_API double* output();

	CSIMPLENETWORKBUILDER_API void run();
private:
	INetwork* network;
	CLayer* inputLayer;
	CLayer* outputLayer;
};