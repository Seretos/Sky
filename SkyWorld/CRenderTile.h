#pragma once
#include "CRenderSprite.h"
#include <SDL.h>

class CRenderTile : public CRenderSprite {
public:
	CRenderTile(SDL_Renderer* renderer, SDL_Texture *texture, int w, int h, int currentStep);

	void setPosition(SDL_Rect position);
	SDL_Rect* getPosition();
protected:
	SDL_Rect position;
};