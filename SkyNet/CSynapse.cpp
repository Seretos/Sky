#include "stdafx.h"
#include "CSynapse.h"

CSynapse::CSynapse(INeuron* source, INeuron* destination, double weight) {
	this->source = source;
	this->destination = destination;
	this->weight = weight;
}

double CSynapse::getWeight() {
	return this->weight;
}

void CSynapse::setWeight(double weight) {
	this->weight = weight;
}

void CSynapse::setValue(double value) {
	this->value = value * this->weight;
}

double CSynapse::getValue() {
	double val = this->value;
	this->value = 0.0f;
	return val;
}