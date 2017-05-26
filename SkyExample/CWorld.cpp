#include "CWorld.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

CWorld::CWorld() {

}

CWorld::~CWorld() {

}

void CWorld::load(std::string fileName) {
	this->tiles = std::vector<std::vector<CWorldTile*>>();
	ALLEGRO_BITMAP *image = al_load_bitmap("testmap.png");
	for (int x = 0; x < al_get_bitmap_width(image); x++) {
		std::vector<CWorldTile*> currentTiles = std::vector<CWorldTile*>();
		for (int y = 0; y < al_get_bitmap_height(image); y++) {
			ALLEGRO_COLOR color = al_get_pixel(image, x, y);
			float val = (color.r + color.g + color.b) / 3;
			bool water = false;
			if (val < 0.5) {
				water = true;
			}
			CWorldTile* tile = new CWorldTile(x*20,y*20,water);
			currentTiles.push_back(tile);
		}
		this->tiles.push_back(currentTiles);
	}
}
void CWorld::render() {
	for (int x = 0; x < this->tiles.size(); x++) {
		for (int y = 0; y < this->tiles.at(x).size(); y++) {
			this->tiles.at(x).at(y)->render();
		}
	}
}