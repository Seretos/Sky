#pragma once
#include "CRenderFrame.h"
#include <SDL.h>
#include <SDL_ttf.h>

class CRenderWindow : public CRenderFrame {
public:
	CRenderWindow();
	~CRenderWindow();

	void render();
protected:
	SDL_Window *window;
	SDL_Renderer *renderer;
	TTF_Font *font;
	int fps;
	double scale;
	SDL_Rect worldView;
	SDL_Rect overlayView;
};