#include "stdafx.h"
#include "CSynapseFrame.h"
#include <allegro5/allegro_primitives.h>

CSynapseFrame::CSynapseFrame(ISynapse* synapse, int startX, int startY, int endX, int endY) : CRenderFrame(startX,startY,endX,endY) {
	this->synapse = synapse;
}

CSynapseFrame::~CSynapseFrame() {

}

void CSynapseFrame::render() {
	if (synapse->getWeight() > 0) {
		al_draw_line(x, y, width, height, al_map_rgb_f(50, synapse->getWeight(), 50), 1 + synapse->getWeight());
	}
	else if (synapse->getWeight() < 0) {
		al_draw_line(x, y, width, height, al_map_rgb_f(-synapse->getWeight(), 50, 50), 1 + synapse->getWeight());
	}
}