#include "stdafx.h"
#include "CTanhNeuron.h"
#include <cmath>

void CTanhNeuron::setValue(double value) {
	if (value >= this->threshold) {
		this->value = tanh(value);
	}
	else {
		this->value = 0;
	}
}

int CTanhNeuron::getType() {
	return 5;
}
