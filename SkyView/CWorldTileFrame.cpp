#include "stdafx.h"
#include "CWorldTileFrame.h"
#include <allegro5/allegro_primitives.h>

CWorldTileFrame::CWorldTileFrame(IWorldTile* tile, int x, int y, int type) : CRenderFrame(x,y,10,10) {
	this->tile = tile;
	this->type = type;
}

CWorldTileFrame::~CWorldTileFrame() {

}

void CWorldTileFrame::render() {
	if (this->type == 0) {
		al_draw_filled_rectangle(this->x, this->y, this->x + this->width, this->y + this->height, al_map_rgb(255, 255, 0));
		if (this->tile->getFoodValue() > 0) {
			int foodVal = this->tile->getFoodValue();
			if (foodVal > 10) {
				foodVal = 10;
			}
			al_draw_filled_rectangle(this->x, this->y, this->x + this->width, this->y + foodVal, al_map_rgb(0, 100, 0));
		}
	}
	else if (this->type == 1) {
		al_draw_filled_rectangle(this->x, this->y, this->x + this->width, this->y + this->height, al_map_rgb(0, 0, 255));
	}
}