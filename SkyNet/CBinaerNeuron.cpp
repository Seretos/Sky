#include "stdafx.h"
#include "CBinaerNeuron.h"

void CBinaerNeuron::setValue(double value) {
	if (value >= this->threshold) {
		this->value = this->threshold;
	}
}