#pragma once
#include "../SkyNet/INeuron.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>


class CRenderNeuron {
public:
	CRenderNeuron(INeuron* neuron, int x, int y);

	void render(ALLEGRO_FONT* font);
private:
	INeuron* neuron;
	int x;
	int y;
};