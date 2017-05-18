#pragma once
#include "INeuron.h"
#include <vector>

#ifdef CLAYER_EXPORTS
#define CLAYER_API __declspec(dllexport) 
#else
#define CLAYER_API __declspec(dllimport) 
#endif

class CLayer {
public:
	CLayer();
	~CLayer();

	CLAYER_API void addNeuron(INeuron* neuron);

	CLAYER_API std::vector<INeuron*>* getNeurons();
private:
	std::vector<INeuron*> neurons;
};