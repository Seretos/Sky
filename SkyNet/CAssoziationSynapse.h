#pragma once
#include "INeuron.h"

#if defined(_WIN32)
#ifdef CASSOZIATIONSYNAPSE_EXPORTS
#define CASSOZIATIONSYNAPSE_API __declspec(dllexport)
#else
#define CASSOZIATIONSYNAPSE_API __declspec(dllimport)
#endif
#else
#define CASSOZIATIONSYNAPSE_API
#endif

class CAssoziationSynapse : public ISynapse {
public:
	CAssoziationSynapse(INeuron* source, INeuron* destination, double weight);

	CASSOZIATIONSYNAPSE_API void setValue(double value);

	int getType();
};
