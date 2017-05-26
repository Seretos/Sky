// SkyWorld.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "CWorld.h"
#include <iostream>
//#include "CWindow.h"
#include "CRenderWindow.h"
#include "CRenderWorld.h"

class MyExample : public CRenderWindow {
public:
	void init() {
		CWorld* world = new CWorld();
		world->import("testmap2.png");

		CRenderWorld* renderWorld = new CRenderWorld(this->renderer, world);
		renderWorld->init();
		this->add(renderWorld);
	}
};

int main(int argc, char* args[])
{
	MyExample* example = new MyExample();
	example->init();
	example->render();
	//CWorld* world = new CWorld();
	//world->import("testmap2.png");
	//CWorldTile* tile = world->get(100, 100);
	//int test;
	//std::cin >> test;
	//CWindow* win = new CWindow();
	//win->init();
	//win->render();
	/*if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init failed!\n";
	}

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 2048, 1024, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	std::string imagePath = "SDL_Example_Tux.png";
	SDL_Surface *bmp = IMG_Load("SDL_Example_Tux.png");
	if (bmp == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	for (int i = 0; i < 3; ++i) {
		//First clear the renderer
		SDL_RenderClear(ren);
		//Draw the texture
		SDL_RenderCopy(ren, tex, NULL, NULL);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
		SDL_Delay(1000);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();*/
	return 0;
}