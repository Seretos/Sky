#include "stdafx.h"
#include "CNeuron.h"



void CNeuron::setValue(double value) {
	if (this->threshold == NULL || value >= this->threshold) {
		this->value = value;
	}
}