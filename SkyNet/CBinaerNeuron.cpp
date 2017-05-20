#include "stdafx.h"
#include "CBinaerNeuron.h"

void CBinaerNeuron::setValue(double value) {
	if (value >= this->threshold) {
		this->value = this->threshold;
	}
	else {
		this->value = 0;
	}
}

int CBinaerNeuron::getType() {
	return 2;
}