#pragma once
#include "INeuron.h"

#ifdef CTANHNEURON_EXPORTS
#define CTANHNEURON_API __declspec(dllexport) 
#else
#define CTANHNEURON_API __declspec(dllimport) 
#endif

class CTanhNeuron : public INeuron {
public:
	CTANHNEURON_API void setValue(double value);
	CTANHNEURON_API int getType();
};