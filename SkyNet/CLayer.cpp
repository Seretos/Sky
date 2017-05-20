#include "stdafx.h"
#include "CLayer.h"

CLayer::CLayer(INetwork* network) {
	this->neurons = std::vector<INeuron*>();
	this->network = network;
}

CLayer::~CLayer() {
	this->neurons.clear();
}

int CLayer::addNeuron(INeuron* neuron) {
	this->neurons.push_back(neuron);
	this->network->addNeuron(neuron);
	return this->neurons.size() - 1;
}

INeuron* CLayer::getNeuron(int index) {
	return this->neurons.at(index);
}

int CLayer::size() {
	return this->neurons.size();
}