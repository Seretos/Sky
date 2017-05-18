#include "stdafx.h"
#include "INeuron.h"

INeuron::INeuron() {
	this->threshold = NULL;
	this->value = 0.0f;
	this->inputs = std::vector<ISynapse*>();
	this->outputs = std::vector<ISynapse*>();
}

INeuron::~INeuron() {
	this->inputs.clear();
	this->outputs.clear();
}

double INeuron::getValue() {
	return this->value;
}

void INeuron::request() {
	for (std::vector<ISynapse*>::size_type i = 0; i != this->outputs.size(); i++) {
		this->outputs.at(i)->setValue(this->value);
	}
	this->setValue(0.0f);
}

void INeuron::response() {
	double input = 0.0f;
	for (std::vector<ISynapse*>::size_type i = 0; i != this->inputs.size(); i++) {
		input += this->inputs.at(i)->getValue();
	}
	this->setValue(input);
}

void INeuron::addInputSynapse(ISynapse* synapse) {
	this->inputs.push_back(synapse);
}

void INeuron::addOutputSynapse(ISynapse* synapse) {
	this->outputs.push_back(synapse);
}

void INeuron::setThreshold(double threshold) {
	this->threshold = threshold;
}

double INeuron::getThreshold() {
	return this->threshold;
}