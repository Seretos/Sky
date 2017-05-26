#pragma once
#include <SDL.h>

class CRenderSprite {
public:
	CRenderSprite(SDL_Renderer* renderer,SDL_Texture *texture, int w, int h, int currentStep =0, int speed=10);

	void render(SDL_Rect* output);
private:
	int steps;
	int currentStep;
	int w;
	int h;
	int cols;
	int rows;
	int speed;
	int speedCount;
	SDL_Texture* texture;
	SDL_Rect textureSize;
	SDL_Renderer* renderer;
};