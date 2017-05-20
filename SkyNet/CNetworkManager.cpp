#include "stdafx.h"
#include "CNetworkManager.h"
#include "CSkyNetFactory.h"

CNetworkManager::CNetworkManager(INetwork* network) {
	this->network = network;
	this->inputLayer = NULL;
	this->outputLayer = NULL;
	this->hiddenLayers = std::vector<CLayer*>();
}

CNetworkManager::~CNetworkManager() {
	this->hiddenLayers.clear();
	this->inputLayer = NULL;
	this->outputLayer = NULL;
}

void CNetworkManager::setInputLayer(CLayer* inputLayer) {
	this->inputLayer = inputLayer;
}

CLayer* CNetworkManager::getInputLayer() {
	return this->inputLayer;
}

void CNetworkManager::setOutputLayer(CLayer* outputLayer) {
	this->outputLayer = outputLayer;
}

CLayer* CNetworkManager::getOutputLayer() {
	return this->outputLayer;
}

int CNetworkManager::addHiddenLayer(CLayer* layer) {
	this->hiddenLayers.push_back(layer);
	return this->hiddenLayers.size() - 1;
}

CLayer* CNetworkManager::getHiddenLayer(int index) {
	return this->hiddenLayers.at(index);
}

void CNetworkManager::autoConnectLayers() {
	CLayer* lastLayer = this->inputLayer;

	for (int i = 0; i < this->hiddenLayers.size(); i++) {
		CLayer* currentLayer = this->hiddenLayers.at(i);
		this->connectLayers(lastLayer, currentLayer);
		lastLayer = currentLayer;
	}

	this->connectLayers(lastLayer, this->outputLayer);
}

void CNetworkManager::connectLayers(CLayer* lastLayer, CLayer* currentLayer) {
	for (int x = 0; x < lastLayer->size(); x++) {
		for (int y = 0; y < currentLayer->size(); y++) {
			INeuron* source = lastLayer->getNeuron(x);
			INeuron* target = currentLayer->getNeuron(y);
			double f = (double)std::rand() / RAND_MAX;
			CSkyNetFactory::createSynapse(source, target, f);
		}
	}
}

void CNetworkManager::run() {
	this->network->request();
	this->network->response();
}

int CNetworkManager::getHiddenLayerSize() {
	return this->hiddenLayers.size();
}

INetwork* CNetworkManager::getNetwork() {
	return this->network;
}

INeuron* CNetworkManager::findNeuronBySaveId(int id) {
	for (int i = 0; i < this->network->size(); i++) {
		if (this->network->getNeuron(i)->getSaveId() == id) {
			return this->network->getNeuron(i);
		}
	}
	return NULL;
}