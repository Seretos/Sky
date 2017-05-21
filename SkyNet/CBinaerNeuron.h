#pragma once
#include "INeuron.h"

#if defined(_WIN32)
#ifdef CBINAERNEURON_EXPORTS
#define CBINAERNEURON_API __declspec(dllexport)
#else
#define CBINAERNEURON_API __declspec(dllimport)
#endif
#else
#define CBINAERNEURON_API
#endif

class CBinaerNeuron : public INeuron {
public:
	CBINAERNEURON_API void setValue(double value);
	CBINAERNEURON_API int getType();
};
