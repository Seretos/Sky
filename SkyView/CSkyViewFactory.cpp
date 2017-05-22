#include "stdafx.h"
#include "CSkyViewFactory.h"
#include "CNetworkFrame.h"
#include "CNeuronFrame.h"
#include "CSynapseFrame.h"

CRenderWindow* CSkyViewFactory::createRenderWindow(int width, int height) {
    CRenderWindow* window = new CRenderWindow(width,height);
	return window;
}

CRenderFrame* CSkyViewFactory::createNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height){
    CNetworkFrame* frame = new CNetworkFrame(manager,x,y,width,height);
    return (CRenderFrame*)frame;
}

CRenderFrame* CSkyViewFactory::createNeuronFrame(INeuron* neuron, int x, int y) {
	CNeuronFrame* frame = new CNeuronFrame(neuron, x, y);
	return (CRenderFrame*)frame;
}

CRenderFrame* CSkyViewFactory::createSynapseFrame(ISynapse* synapse, int startX, int startY, int endX, int endY) {
	CSynapseFrame* frame = new CSynapseFrame(synapse, startX, startY, endX, endY);
	return (CRenderFrame*)frame;
}