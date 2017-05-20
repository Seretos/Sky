#pragma once
#include "INeuron.h"

#ifdef CLOGISTICNEURON_EXPORTS
#define CLOGISTICNEURON_API __declspec(dllexport) 
#else
#define CLOGISTICNEURON_API __declspec(dllimport) 
#endif

class CLogisticNeuron : public INeuron {
public:
	CLOGISTICNEURON_API void setValue(double value);
	CLOGISTICNEURON_API int getType();
};