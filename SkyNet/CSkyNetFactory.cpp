#include "stdafx.h"
#include "CSkyNetFactory.h"
#include "CNetwork.h"
#include "CNeuron.h"
#include "CBinaerNeuron.h"
#include "CBiasNeuron.h"
#include "CLogisticNeuron.h"
#include "CTanhNeuron.h"
#include "CSynapse.h"
#include "INeuron.h"

CSkyNetFactory::CSkyNetFactory()
{
}


CSkyNetFactory::~CSkyNetFactory()
{
}

INetwork* CSkyNetFactory::createNetwork() {
	INetwork* net = new CNetwork();
	return net;
}

INeuron* CSkyNetFactory::createNeuron() {
	CNeuron* neuron = new CNeuron();
	return (INeuron*)neuron;
}

INeuron* CSkyNetFactory::createBinaerNeuron() {
	CBinaerNeuron* neuron = new CBinaerNeuron();
	neuron->setThreshold(1);
	return (INeuron*)neuron;
}

INeuron* CSkyNetFactory::createBiasNeuron() {
	CBiasNeuron* neuron = new CBiasNeuron();
	neuron->setThreshold(1);
	return (INeuron*)neuron;
}

INeuron* CSkyNetFactory::createLogisticNeuron() {
	CLogisticNeuron* neuron = new CLogisticNeuron();
	return (INeuron*)neuron;
}
INeuron* CSkyNetFactory::createTanhNeuron() {
	CTanhNeuron* neuron = new CTanhNeuron();
	return (INeuron*)neuron;
}

ISynapse* CSkyNetFactory::createSynapse(INeuron* source, INeuron* destination, double weight) {
	ISynapse* synapse = new CSynapse(source,destination,weight);

	source->addOutputSynapse(synapse);
	destination->addInputSynapse(synapse);

	return synapse;
}

CNetworkManager* CSkyNetFactory::createNetworkManager(INetwork* network) {
	CNetworkManager* manager = new CNetworkManager(network);
	return manager;
}

CLayer* CSkyNetFactory::createLayer(INetwork* network) {
	CLayer* layer = new CLayer(network);
	return layer;
}

CSimulationManager* CSkyNetFactory::createSimulationManager() {
	CSimulationManager* manager = new CSimulationManager();
	return manager;
}

CNetworkManagerFile* CSkyNetFactory::createNetworkManagerFile() {
	return new CNetworkManagerFile();
}