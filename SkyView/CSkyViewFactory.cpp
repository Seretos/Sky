#include "stdafx.h"
#include "CSkyViewFactory.h"
#include "CNetworkFrame.h"
#include "CNeuronFrame.h"
#include "CSynapseFrame.h"
#include "CWorldTileFrame.h"

CRenderWindow* CSkyViewFactory::createRenderWindow(ALLEGRO_DISPLAY* display) {
    CRenderWindow* window = new CRenderWindow(display);
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

CRenderFrame* CSkyViewFactory::createWorldTileFrame(IWorldTile* tile, int x, int y, int type) {
	CWorldTileFrame* frame = new CWorldTileFrame(tile, x, y, type);
	return (CRenderFrame*)frame;
}