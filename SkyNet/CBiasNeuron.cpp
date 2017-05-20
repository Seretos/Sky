#include "stdafx.h"
#include "CBiasNeuron.h"

void CBiasNeuron::setValue(double value) {

}

double CBiasNeuron::getValue() {
	return this->threshold;
}

int CBiasNeuron::getType() {
	return 3;
}