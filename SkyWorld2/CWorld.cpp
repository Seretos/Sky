#include "stdafx.h"
#include "CWorld.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

CWorldTile::CWorldTile(int type) {
	this->type = type;
}

CWorldTile::~CWorldTile() {

}

int CWorldTile::getType() {
	return this->type;
}

int CWorldTile::getFood() {
	return this->food;
}

void CWorldTile::setFood(int food) {
	this->food = food;
}

CWorld::CWorld() {
}

CWorld::~CWorld() {
}

void CWorld::loadMap(std::string fileName) {
	ALLEGRO_BITMAP *image = al_load_bitmap(fileName.c_str());
	this->width = al_get_bitmap_width(image);
	this->height = al_get_bitmap_height(image);

	this->tiles = new CWorldTile**[this->width];

	for (int x = 0; x < this->width; x++) {
		this->tiles[x] = new CWorldTile*[this->height];
		for (int y = 0; y < al_get_bitmap_height(image); y++) {
			ALLEGRO_COLOR color = al_get_pixel(image, x, y);
			float val = (color.r + color.g + color.b) / 3;
			int type = TILE_TYPE_LAND;
			if (val < 0.5) {
				type = TILE_TYPE_WATER;
			}
			CWorldTile* tile = new CWorldTile(type);
			this->tiles[x][y] = tile;
		}
	}
}

int CWorld::sizeX() {
	return this->width;
}

int CWorld::sizeY() {
	return this->height;
}

CWorldTile* CWorld::get(int x,int y) {
	return this->tiles[x][y];
}