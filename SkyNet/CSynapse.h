#pragma once
#include "ISynapse.h"
#include "INeuron.h"

#ifdef CSYNAPSE_EXPORTS
#define CSYNAPSE_API __declspec(dllexport) 
#else
#define CSYNAPSE_API __declspec(dllimport) 
#endif

class CSynapse: public ISynapse {
public:
	CSynapse(INeuron* source, INeuron* destination, double weight);

	CSYNAPSE_API double getWeight();
	CSYNAPSE_API void setWeight(double weight);

	CSYNAPSE_API void setValue(double value);
	CSYNAPSE_API double getValue();
private:
	INeuron* source;
	INeuron* destination;
	double weight;
	double value;
};