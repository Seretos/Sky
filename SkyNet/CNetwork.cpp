#include "stdafx.h"
#include "CNetwork.h"

CNetwork::CNetwork() {
	this->neurons = std::vector<INeuron*>();
}

CNetwork::~CNetwork() {
	this->neurons.clear();
}

int CNetwork::addNeuron(INeuron* neuron) {
	this->neurons.push_back(neuron);
	return this->neurons.size() - 1;
}

INeuron* CNetwork::getNeuron(int index) {
	return this->neurons.at(index);
}

void CNetwork::request() {
	for (std::vector<INeuron*>::size_type i = 0; i != this->neurons.size(); i++) {
		this->neurons.at(i)->request();
	}
}

void CNetwork::response() {
	for (std::vector<INeuron*>::size_type i = 0; i != this->neurons.size(); i++) {
		this->neurons.at(i)->response();
	}
}

int CNetwork::size() {
	return this->neurons.size();
}