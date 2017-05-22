#include "stdafx.h"
#include "CNetworkWindow.h"

CNetworkWindow::CNetworkWindow(CNetworkManager* manager) : CRenderWindow() {
	this->manager = manager;
	this->neurons = std::vector<CRenderNeuron*>();

	int x = 40;
	this->addLayerNeurons(this->manager->getInputLayer(), x);
	x += 120;
	for (int i = 0; i < this->manager->getHiddenLayerSize(); i++) {
		this->addLayerNeurons(this->manager->getHiddenLayer(i), x);
		x += 120;
	}
	this->addLayerNeurons(this->manager->getOutputLayer(), x);
}

void CNetworkWindow::addLayerNeurons(CLayer* layer, int x) {
	for (int i = 0; i < layer->size(); i++) {
		INeuron* neuron = layer->getNeuron(i);
		CRenderNeuron* renderNeuron = new CRenderNeuron(neuron, x, 40 + (i * 80));
		this->neurons.push_back(renderNeuron);
	}
}

CNetworkWindow::~CNetworkWindow() {

}

/*void CNetworkWindow::init() {
	CRenderWindow::init();

	CLayer* inputLayer = this->manager->getInputLayer();
	for (int i = 0; i < inputLayer->size(); i++) {
		INeuron* neuron = inputLayer->getNeuron(i);
		CRenderNeuron* renderNeuron = new CRenderNeuron(neuron,40,40);
		this->neurons.push_back(renderNeuron);
	}
}*/

void CNetworkWindow::draw() {
	for (int i = 0; i < this->neurons.size(); i++) {
		this->neurons.at(i)->render(this->font);
	}
}