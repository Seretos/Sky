#pragma once
#include "INeuron.h"

#if defined(_WIN32)
#ifdef CSYNAPSE_EXPORTS
#define CSYNAPSE_API __declspec(dllexport)
#else
#define CSYNAPSE_API __declspec(dllimport)
#endif
#else
#define CSYNAPSE_API
#endif

class CSynapse: public ISynapse {
public:
	CSynapse(INeuron* source, INeuron* destination, double weight);

	int getType();
};
