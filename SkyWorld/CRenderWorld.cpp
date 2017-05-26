#include "stdafx.h"
#include "CRenderWorld.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

CRenderWorld::CRenderWorld(SDL_Renderer* renderer, CWorld* world) : CRenderFrame(renderer) {
	this->world = world;
}

void CRenderWorld::init() {
	SDL_Surface *waterSurface = IMG_Load("Ocean_SpriteSheet.png");
	SDL_Texture *waterTexture = SDL_CreateTextureFromSurface(this->renderer, waterSurface);
	SDL_Surface *sandSurface = IMG_Load("sand.png");
	SDL_Texture *sandTexture = SDL_CreateTextureFromSurface(this->renderer, sandSurface);
	SDL_FreeSurface(waterSurface);
	SDL_FreeSurface(sandSurface);

	this->tiles = new CRenderTile*[this->world->sizeX()*this->world->sizeY()];
	int tileIndex = 0;
	int startStep = 0;
	for (int x = 0; x < this->world->sizeX(); x++) {
		for (int y = 0; y < this->world->sizeY(); y++) {
			startStep = (y + x);
			CWorldTile* tile = this->world->get(x, y);
			CRenderTile* renderTile;
			if (tile->getType() == WORLD_TILE_TYPE_WATER) {
				renderTile = new CRenderTile(this->renderer, waterTexture, WORLD_TILE_SIZE, WORLD_TILE_SIZE,startStep);			
			}
			else {
				renderTile = new CRenderTile(this->renderer, sandTexture, WORLD_TILE_SIZE, WORLD_TILE_SIZE, 0);
			}
			SDL_Rect output;
			output.x = WORLD_TILE_SIZE*x;
			output.y = WORLD_TILE_SIZE*y;
			output.w = WORLD_TILE_SIZE;
			output.h = WORLD_TILE_SIZE;
			renderTile->setPosition(output);
			this->tiles[tileIndex] = renderTile;
			tileIndex++;
		}
	}
}

void CRenderWorld::render(double scale) {
	int index = 0;
	for (int x = 0; x < this->world->sizeX(); x++) {
		for (int y = 0; y < this->world->sizeY(); y++) {
			
			SDL_Rect rect = *this->tiles[index]->getPosition();
			rect.x = rect.x * scale;
			rect.y = rect.y * scale;
			rect.w = rect.w * scale;
			rect.h = rect.h * scale;
			this->tiles[index]->render(&rect);
			index++;
		}
	}
}