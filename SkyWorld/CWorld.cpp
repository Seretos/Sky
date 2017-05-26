#include "stdafx.h"
#include "CWorld.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

CWorld::CWorld() {
	this->width = 0;
	this->height = 0;
}

CWorld::~CWorld() {

}

void CWorld::import(std::string fileName) {
	SDL_Surface *mapSurface = IMG_Load(fileName.c_str());
	if (mapSurface == nullptr) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	}
	int bpp = mapSurface->format->BytesPerPixel;

	this->tiles = new CWorldTile**[mapSurface->w];

	this->width = mapSurface->w;
	this->height = mapSurface->h;

	for (int x = 0; x < mapSurface->w; x++) {
		this->tiles[x] = new CWorldTile*[mapSurface->h];
	}
	for (int x = 0; x < mapSurface->w; x++) {
		for (int y = 0; y < mapSurface->h; y++) {
			//Uint32 p = (Uint32)mapSurface->pixels + y * mapSurface->pitch + x * bpp;
			//int red = (p >> 16) & 0xff;
			//int green = (p >> 8) & 0xff;
			//int blue = p & 0xff;
			//int grey = (red + green + blue) / 3;
			//std::cout << red << ' ' << green << ' ' << blue << '\n';
			unsigned char* pixels = (unsigned char*)mapSurface->pixels;
			int grey = (pixels[4 * (y * mapSurface->w + x)] + pixels[4 * (y * mapSurface->w + x)+1] + pixels[4 * (y * mapSurface->w + x) + 2]) / 3;
			int type = WORLD_TILE_TYPE_WATER;
			int food = 0;
			//std::cout << grey << ' ';
			if (grey > 120) {
				type = WORLD_TILE_TYPE_GROUND;
				int food = 100;
//				std::cout << 1;
			}
			else {
//				std::cout << 0;
			}
			CWorldTile* tile = new CWorldTile(x*WORLD_TILE_SIZE,y*WORLD_TILE_SIZE,type,food);
			this->tiles[x][y] = tile;
		}
		//std::cout << '\n';
	}
}

int CWorld::sizeX() {
	return this->width;
}

int CWorld::sizeY() {
	return this->height;
}

CWorldTile* CWorld::get(int x, int y) {
	return this->tiles[x][y];
}

CWorldTile::CWorldTile(int x, int y, int type, int food) {
	this->x = x;
	this->y = y;
	this->type = type;
	this->food = food;
}

CWorldTile::~CWorldTile() {

}

int CWorldTile::getFood() {
	return this->food;
}

void CWorldTile::setFood(int food) {
	this->food = food;
}

int CWorldTile::getType() {
	return this->type;
}