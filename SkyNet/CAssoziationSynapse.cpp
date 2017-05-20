#include "stdafx.h"
#include "CAssoziationSynapse.h"

int CAssoziationSynapse::getType() {
	return 2;
}

void CAssoziationSynapse::setValue(double value) {
	this->value = value * this->weight;
	//todo: recalculate weight
}

CAssoziationSynapse::CAssoziationSynapse(INeuron* source, INeuron* destination, double weight) : ISynapse(source, destination, weight) {

}