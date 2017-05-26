#include "stdafx.h"
#include "CRenderTile.h"

CRenderTile::CRenderTile(SDL_Renderer* renderer, SDL_Texture *texture, int w, int h, int currentStep): CRenderSprite(renderer,texture,w,h, currentStep) {

}

void CRenderTile::setPosition(SDL_Rect position) {
	this->position = position;
}

SDL_Rect* CRenderTile::getPosition() {
	return &this->position;
}