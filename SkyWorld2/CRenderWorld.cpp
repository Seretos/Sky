#include "stdafx.h"
#include "CRenderWorld.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

CRenderWorld::CRenderWorld(CWorld* world) : CRenderFrame() {
	this->world = world;
}

CRenderWorld::~CRenderWorld() {

}

void CRenderWorld::init() {

}

void CRenderWorld::render() {
	for (int x = 0; x < this->world->sizeX(); x++) {
		for (int y = 0; y < this->world->sizeY(); y++) {
			CWorldTile* tile = this->world->get(x, y);
			if (tile->getType() == TILE_TYPE_WATER) {
				al_draw_filled_rectangle(x*10, y*10, (x*10)+10, (y*10)+10, al_map_rgb(0, 0, 255));
			}
			else {
				al_draw_filled_rectangle(x * 10, y * 10, (x * 10) + 10, (y * 10) + 10, al_map_rgb(255, 255, 0));
			}
		}
	}
}