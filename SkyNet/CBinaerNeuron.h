#pragma once
#include "INeuron.h"

#ifdef CBINAERNEURON_EXPORTS
#define CBINAERNEURON_API __declspec(dllexport) 
#else
#define CBINAERNEURON_API __declspec(dllimport) 
#endif

class CBinaerNeuron : public INeuron {
public:
	CBINAERNEURON_API void setValue(double value);
	CBINAERNEURON_API int getType();
};