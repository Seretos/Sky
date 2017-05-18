#include "stdafx.h"
#include "CSkyNetFactory.h"
#include "CNetwork.h"
#include "CNeuron.h"
#include "CBinaerNeuron.h"
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

ISynapse* CSkyNetFactory::createSynapse(INeuron* source, INeuron* destination, double weight) {
	ISynapse* synapse = new CSynapse(source,destination,weight);

	source->addOutputSynapse(synapse);
	destination->addInputSynapse(synapse);

	return synapse;
}

CSimpleNetworkBuilder* CSkyNetFactory::createSimpleNetworkBuilder() {
	CSimpleNetworkBuilder* builder = new CSimpleNetworkBuilder();
	return builder;
}

CLayer* CSkyNetFactory::createLayer() {
	CLayer* layer = new CLayer();
	return layer;
}