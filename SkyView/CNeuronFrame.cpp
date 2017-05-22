#include "stdafx.h"
#include "CNeuronFrame.h"
#include <allegro5/allegro_primitives.h>

CNeuronFrame::CNeuronFrame(INeuron* neuron, int x, int y) : CRenderFrame(x-5,y-5,10,10)
{
	this->neuron = neuron;
}

CNeuronFrame::~CNeuronFrame()
{
}

void CNeuronFrame::render(){
	al_draw_filled_circle(x, y, 10, al_map_rgb(0, 0, 0));
	al_draw_circle(x,y,10,al_map_rgb(255,255,255),2);
	double val = this->neuron->getValue();
	if (val < 0) {
		val = -val;
	}
	val += 3;
	if (val > 20) {
		val = 20;
	}

	if (this->neuron->getValue() > 0) {
		al_draw_filled_circle(x, y, val, al_map_rgb(0, 255, 0));
	}
	else if (this->neuron->getValue() < 0) {
		al_draw_filled_circle(x, y, val, al_map_rgb(255, 0, 0));
	}
}

INeuron* CNeuronFrame::getNeuron() {
	return this->neuron;
}

int CNeuronFrame::getX() {
	return this->x;
}
int CNeuronFrame::getY() {
	return this->y;
}