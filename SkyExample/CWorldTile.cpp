#include "stdafx.h"
#include "CWorldTile.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>

CWorldTile::CWorldTile(int x, int y, bool water) {
	this->x = x;
	this->y = y;
	this->water = water;
}

void CWorldTile::render() {
	if (this->water) {
		al_draw_filled_rectangle(this->x, this->y, this->x + 20, this->y + 20, al_map_rgb(0, 0, 255));
	}
	else {
		al_draw_filled_rectangle(this->x, this->y, this->x + 20, this->y + 20, al_map_rgb(255, 255, 0));
	}
}