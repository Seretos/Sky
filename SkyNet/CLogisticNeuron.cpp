#include "stdafx.h"
#include "CLogisticNeuron.h"
#include <cmath>

void CLogisticNeuron::setValue(double value) {
	if (value >= this->threshold) {
		this->value = 1/(1+exp(-value));
	}
	else {
		this->value = 0;
	}
}

int CLogisticNeuron::getType() {
	return 4;
}
