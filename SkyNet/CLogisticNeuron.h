#pragma once
#include "INeuron.h"

#if defined(_WIN32)
#ifdef CLOGISTICNEURON_EXPORTS
#define CLOGISTICNEURON_API __declspec(dllexport)
#else
#define CLOGISTICNEURON_API __declspec(dllimport)
#endif
#else
#define CLOGISTICNEURON_API
#endif

class CLogisticNeuron : public INeuron {
public:
	CLOGISTICNEURON_API void setValue(double value);
	CLOGISTICNEURON_API int getType();
};
