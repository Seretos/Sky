#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "CRenderWorld.h"

class CWindow {
public:
	CWindow();
	~CWindow();

	void init();
	void render();
protected:
	SDL_Window *window;
	SDL_Renderer *renderer;
	TTF_Font *font;
	int fps;
	CRenderWorld* world;
};