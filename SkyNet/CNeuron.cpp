#include "stdafx.h"
#include "CNeuron.h"



void CNeuron::setValue(double value) {
	if (this->threshold == NULL || value >= this->threshold) {
		this->value = value;
	}
	else {
		this->value = 0;
	}
}

int CNeuron::getType() {
	return 1;
}