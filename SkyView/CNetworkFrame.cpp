#include "stdafx.h"
#include "CNetworkFrame.h"
#include <allegro5/allegro_primitives.h>
#include "CSkyViewFactory.h"

CNetworkFrame::CNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height) : CRenderFrame(x,y,width,height)
{
	this->neurons = std::vector<CNeuronFrame*>();
	this->synapses = std::vector<CSynapseFrame*>();
    this->manager = manager;

	int lCount = this->manager->getHiddenLayerSize() + 1;
	int padding = ((width-30) / lCount);

	int posX = x + 20;
	this->createRenderLayer(this->manager->getInputLayer(),posX);
	posX += padding;
	for (int i = 0; i < this->manager->getHiddenLayerSize(); i++) {
		this->createRenderLayer(this->manager->getHiddenLayer(i), posX);
		posX += padding;
	}
	this->createRenderLayer(this->manager->getOutputLayer(), posX);


	this->createRenderSynapseLayer(this->manager->getInputLayer());
	for (int i = 0; i < this->manager->getHiddenLayerSize(); i++) {
		this->createRenderSynapseLayer(this->manager->getHiddenLayer(i));
		std::cout << "loading network " << (100 / this->manager->getHiddenLayerSize()) * (i+1) << '\n';
	}

	//CRenderFrame* frame = CSkyViewFactory::createSynapseFrame(this->manager->getInputLayer()->getNeuron(0)->getOutputSynapse(0), 10, 10, 100, 100);
	//this->frames.push_back(frame);
	//this->frames.assign(this->synapses.begin(), this->synapses.end());
	//this->frames.assign(this->neurons.begin(),this->neurons.end());
}

void CNetworkFrame::createRenderSynapseLayer(CLayer* layer) {
	for (int i = 0; i < layer->size(); i++) {
		INeuron* neuron = layer->getNeuron(i);
		for (int y = 0; y < neuron->getOutputSynapseSize(); y++) {
			ISynapse* synapse = neuron->getOutputSynapse(y);

			CNeuronFrame* input = this->findNeuronFrame(neuron);
			CNeuronFrame* output = this->findNeuronFrame(synapse->getTargetNeuron());

			CSynapseFrame* frame = (CSynapseFrame*)CSkyViewFactory::createSynapseFrame(synapse, input->getX(), input->getY(), output->getX(), output->getY());

			this->synapses.push_back(frame);
		}
	}
}

CNeuronFrame* CNetworkFrame::findNeuronFrame(INeuron* neuron) {
	for (int i = 0; i < this->neurons.size(); i++) {
		if (this->neurons.at(i)->getNeuron() == neuron) {
			return this->neurons.at(i);
		}
	}
	return NULL;
}

CNetworkFrame::~CNetworkFrame()
{
    //dtor
}

void CNetworkFrame::render(){
    al_draw_rectangle(x,y, x + width,y + height,al_map_rgb(255,255,255),2);
	
	for (int i = 0; i<this->synapses.size(); i++) {
		this->synapses.at(i)->render();
	}

	for (int i = 0; i<this->neurons.size(); i++) {
		this->neurons.at(i)->render();
	}
}

void CNetworkFrame::createRenderLayer(CLayer* layer, int startX) {
	int startY = y;

	int paddingTop = (this->height-(layer->size() * 25))/2;

	startY += paddingTop + 10;
	for (int i = 0; i < layer->size(); i++) {
		INeuron* neuron = layer->getNeuron(i);
		CNeuronFrame* neuronFrame = (CNeuronFrame*)CSkyViewFactory::createNeuronFrame(neuron, startX, startY);
		startY += 25;
		this->neurons.push_back(neuronFrame);
	}
}