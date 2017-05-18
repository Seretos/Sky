#include "stdafx.h"
#include "CLayer.h"

CLayer::CLayer() {
	this->neurons = std::vector<INeuron*>();
}

CLayer::~CLayer() {
	this->neurons.clear();
}

void CLayer::addNeuron(INeuron* neuron) {
	this->neurons.push_back(neuron);
}

std::vector<INeuron*>* CLayer::getNeurons() {
	return &this->neurons;
}