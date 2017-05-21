#pragma once
#include "INetwork.h"
#include <vector>

#if defined(_WIN32)
#ifdef CLAYER_EXPORTS
#define CLAYER_API __declspec(dllexport)
#else
#define CLAYER_API __declspec(dllimport)
#endif
#else
#define CLAYER_API
#endif

class CLayer {
public:
	CLayer(INetwork* network);
	~CLayer();

	CLAYER_API int addNeuron(INeuron* neuron);

	CLAYER_API INeuron* getNeuron(int index);
	CLAYER_API int size();
private:
	std::vector<INeuron*> neurons;
	INetwork* network;
};
