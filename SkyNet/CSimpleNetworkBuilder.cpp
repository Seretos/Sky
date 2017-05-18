#include "stdafx.h"
#include "CSimpleNetworkBuilder.h"
#include "CSkyNetFactory.h"
#include <iostream>
#include <time.h>

CSimpleNetworkBuilder::CSimpleNetworkBuilder() {
	this->network = NULL;
}

void CSimpleNetworkBuilder::build(int inputs, int outputs) {
	this->network = CSkyNetFactory::createNetwork();
	this->inputLayer = CSkyNetFactory::createLayer();
	this->outputLayer = CSkyNetFactory::createLayer();

	for (int i = 0; i < inputs; i++) {
		INeuron* neuron = CSkyNetFactory::createNeuron();
		this->network->addNeuron(neuron);
		this->inputLayer->addNeuron(neuron);
	}

	for (int i = 0; i < outputs; i++) {
		INeuron* neuron = CSkyNetFactory::createNeuron();
		this->network->addNeuron(neuron);
		this->outputLayer->addNeuron(neuron);
	}

	for (std::vector<INeuron*>::size_type i = 0; i != this->inputLayer->getNeurons()->size(); i++) {
		INeuron* input = this->inputLayer->getNeurons()->at(i);
		for (std::vector<INeuron*>::size_type y = 0; y != this->outputLayer->getNeurons()->size(); y++) {
			INeuron* output = this->outputLayer->getNeurons()->at(y);
			double f = (double)std::rand() / RAND_MAX;
			CSkyNetFactory::createSynapse(input, output, f);
		}
	}
}

void CSimpleNetworkBuilder::input(double* inputs) {
	for (int i = 0; i < this->inputLayer->getNeurons()->size(); i++) {
		this->inputLayer->getNeurons()->at(i)->setValue(*(inputs + i));
	}
}

double* CSimpleNetworkBuilder::output() {
	double* arr = new double[this->outputLayer->getNeurons()->size()];
	for (int i = 0; i < this->outputLayer->getNeurons()->size(); i++) {
		arr[i] = this->outputLayer->getNeurons()->at(i)->getValue();
	}
	return arr;
}

void CSimpleNetworkBuilder::run() {
	this->network->request();
	this->network->response();
}