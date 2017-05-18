#pragma once
#include "ISynapse.h"
#include <vector>

#ifdef INEURON_EXPORTS
#define INEURON_API __declspec(dllexport) 
#else
#define INEURON_API __declspec(dllimport) 
#endif

class INeuron {
public:

	INeuron();
	~INeuron();

	virtual INEURON_API void setValue(double value) = 0;
	INEURON_API double getValue();

	INEURON_API void request();
	INEURON_API void response();

	INEURON_API void setThreshold(double threshold);
	INEURON_API double getThreshold();

	void addOutputSynapse(ISynapse* synapse);
	void addInputSynapse(ISynapse* synapse);
protected:
	double threshold;
	double value;
	std::vector<ISynapse*> outputs;
	std::vector<ISynapse*> inputs;
};