#pragma once
#include "INeuron.h"

#ifdef INETWORK_EXPORTS
#define INETWORK_API __declspec(dllexport) 
#else
#define INETWORK_API __declspec(dllimport) 
#endif

class INetwork
{
public:
	virtual INETWORK_API int addNeuron(INeuron* neuron) = 0;
	virtual INETWORK_API INeuron* getNeuron(int index) = 0;

	virtual INETWORK_API void request() = 0;
	virtual INETWORK_API void response() = 0;

	virtual int size() = 0;
};