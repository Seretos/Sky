#pragma once
#include "INeuron.h"

#ifdef CBIASNEURON_EXPORTS
#define CBIASNEURON_API __declspec(dllexport) 
#else
#define CBIASNEURON_API __declspec(dllimport) 
#endif

class CBiasNeuron : public INeuron {
public:
	CBIASNEURON_API void setValue(double value);
	CBIASNEURON_API double getValue();
	CBIASNEURON_API int getType();
};