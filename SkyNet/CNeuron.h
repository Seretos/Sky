#pragma once
#include "INeuron.h"

#ifdef CNEURON_EXPORTS
#define CNEURON_API __declspec(dllexport) 
#else
#define CNEURON_API __declspec(dllimport) 
#endif

class CNeuron : public INeuron {
public:
	CNEURON_API void setValue(double value);
	CNEURON_API int getType();
};