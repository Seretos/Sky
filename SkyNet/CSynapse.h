#pragma once
#include "ISynapse.h"
#include "INeuron.h"

class CSynapse: public ISynapse {
public:
	CSynapse(INeuron* source, INeuron* destination, double weight);

	double getWeight();
	void setWeight(double weight);

	void setValue(double value);
	double getValue();
private:
	INeuron* source;
	INeuron* destination;
	double weight;
	double value;
};