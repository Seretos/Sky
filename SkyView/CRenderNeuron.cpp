#include "stdafx.h"
#include "CRenderNeuron.h"
#include <sstream>

CRenderNeuron::CRenderNeuron(INeuron* neuron, int x, int y) {
	this->neuron = neuron;
	this->x = x;
	this->y = y;
}

void CRenderNeuron::render(ALLEGRO_FONT* font) {
	al_draw_filled_circle(x, y, 30, al_map_rgb(255, 255, 255));
	double r=0, g=0, b=0;
	if (this->neuron->getValue() < 0) {
		r = -this->neuron->getValue();
	}
	else if (this->neuron->getValue() > 0) {
		b = this->neuron->getValue();
	}
	al_draw_filled_circle(x, y, 28, al_map_rgb_f(r,g,b));

	std::ostringstream strs;
	strs << this->neuron->getValue();
	std::string str = strs.str();

	al_draw_text(font, al_map_rgb(255, 255, 255), x,y, ALLEGRO_ALIGN_CENTER, str.c_str());
}