#include "stdafx.h"
#include "CNetworkManagerFile.h"
#include "CSkyNetFactory.h"
#include "CBiasNeuron.h"
#include <sstream>

CNetworkManager* CNetworkManagerFile::loadNetwork(std::string fileName) {
	INetwork* network = CSkyNetFactory::createNetwork();
	CNetworkManager* manager = CSkyNetFactory::createNetworkManager(network);

	std::ifstream infile(fileName);

	std::string line;
	int mode = 0;
	while (std::getline(infile, line)) {
		std::vector<std::string> columns = this->parseLine(line);
		if (columns.size() == 0) {
			break;
		}
		mode = this->lineMode(columns[0], mode, manager);

		if ((mode == 1 || mode == 2 || mode == 3) && columns[0].compare("neuron") == 0) {
			INeuron* neuron = this->createTypeNeuron(columns[1],columns[2], columns[3]);
			if (mode == 1) {
				manager->getInputLayer()->addNeuron(neuron);
			}
			else if (mode == 2) {
				manager->getHiddenLayer(manager->getHiddenLayerSize() - 1)->addNeuron(neuron);
			}
			else if (mode == 3) {
				manager->getOutputLayer()->addNeuron(neuron);
			}
		}
		else if (mode == 4 && columns[0].compare("synapse") == 0) {
			ISynapse* synapse = this->createTypeSynapse(manager, columns[1],columns[2],columns[3],columns[4]);
		}
	}
	return manager;
}

ISynapse* CNetworkManagerFile::createTypeSynapse(CNetworkManager* manager, std::string type, std::string source, std::string target, std::string weight) {
	INeuron* sourceNeuron = manager->findNeuronBySaveId(::atoi(source.c_str()));
	INeuron* targetNeuron = manager->findNeuronBySaveId(::atoi(target.c_str()));

	ISynapse* synapse = CSkyNetFactory::createSynapse(sourceNeuron,targetNeuron,::atof(weight.c_str()));
	return synapse;
}

INeuron* CNetworkManagerFile::createTypeNeuron(std::string saveId, std::string type, std::string threshold) {
	INeuron* neuron;
	if (type.compare("2") == 0) {
		neuron = CSkyNetFactory::createBinaerNeuron();
	}
	else if (type.compare("3") == 0) {
		neuron = CSkyNetFactory::createBiasNeuron();
	}
	else if (type.compare("4") == 0) {
		neuron = CSkyNetFactory::createLogisticNeuron();
	}
	else if (type.compare("5") == 0) {
		neuron = CSkyNetFactory::createTanhNeuron();
	}
	else {
		neuron = CSkyNetFactory::createNeuron();
	}
	neuron->setThreshold(::atof(threshold.c_str()));
	neuron->setSaveId(::atoi(saveId.c_str()));
	return neuron;
}

int CNetworkManagerFile::lineMode(std::string column, int currentMode, CNetworkManager* manager) {
	if (column.compare("inputs") == 0) {
		currentMode = 1;
		CLayer* layer = CSkyNetFactory::createLayer(manager->getNetwork());
		manager->setInputLayer(layer);
	}
	else if (column.compare("hidden") == 0) {
		currentMode = 2;
		CLayer* layer = CSkyNetFactory::createLayer(manager->getNetwork());
		manager->addHiddenLayer(layer);
	}
	else if (column.compare("outputs") == 0) {
		currentMode = 3;
		CLayer* layer = CSkyNetFactory::createLayer(manager->getNetwork());
		manager->setOutputLayer(layer);
	}
	else if (column.compare("synapses") == 0) {
		currentMode = 4;
	}
	return currentMode;
}

std::vector<std::string> CNetworkManagerFile::parseLine(std::string line) {
	std::istringstream f(line);
	std::string column;
	std::vector<std::string> columns;
	while (std::getline(f, column, ':')) {
		columns.push_back(column);
	}
	return columns;
}

void CNetworkManagerFile::saveNetwork(CNetworkManager* network, std::string fileName) {
	std::string content;
	std::ofstream file;
	file.open(fileName);
	file << "inputs:\n";
	int index = this->saveNeurons(&file,network->getInputLayer());
	for (int i = 0; i < network->getHiddenLayerSize(); i++) {
		file << "hidden:" << i << ":\n";
		index = this->saveNeurons(&file, network->getHiddenLayer(i),index);
	}
	file << "outputs:\n";
	this->saveNeurons(&file, network->getOutputLayer(),index);

	file << "synapses:\n";
	this->saveSynapses(&file, network->getInputLayer());
	for (int i = 0; i < network->getHiddenLayerSize(); i++) {
		this->saveSynapses(&file, network->getHiddenLayer(i));
	}
	this->saveSynapses(&file, network->getOutputLayer());
	file.close();
}

int CNetworkManagerFile::saveNeurons(std::ofstream* fileStream,CLayer* layer, int index) {
	for (int i = 0; i < layer->size(); i++) {
		INeuron* neuron = layer->getNeuron(i);
		neuron->setSaveId(index + i);
		*fileStream << "neuron:" << neuron->getSaveId() << ':' << neuron->getType() << ':' << neuron->getThreshold() << '\n';
	}
	return index + layer->size();
}

void CNetworkManagerFile::saveSynapses(std::ofstream* fileStream, CLayer* layer) {
	for (int i = 0; i < layer->size(); i++) {
		INeuron* neuron = layer->getNeuron(i);
		for (int x = 0; x < neuron->getOutputSynapseSize(); x++) {
			ISynapse* synapse = neuron->getOutputSynapse(x);
			*fileStream << "synapse:" << synapse->getType() << ":" << synapse->getSourceNeuron()->getSaveId() << ":" << synapse->getTargetNeuron()->getSaveId() << ":" << synapse->getWeight() << "\n";
		}
	}
}