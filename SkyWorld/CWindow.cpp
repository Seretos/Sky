#include "stdafx.h"
#include "CWindow.h"
#include <iostream>
#include <string>
#include <chrono>

CWindow::CWindow() {
	this->fps = 60;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init failed!\n";
	}
	TTF_Init();

	this->window = SDL_CreateWindow("Hello World!", 100, 100, 2048, 1024, SDL_WINDOW_SHOWN);
	if (this->window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->renderer == nullptr) {
		SDL_DestroyWindow(this->window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 4000;
	rect.h = 4000;
	SDL_RenderSetViewport(this->renderer, &rect);

	this->font = TTF_OpenFont("times.ttf", 30);
	if (this->font == nullptr) {
		std::cout << "TTF_OpenFont Error: " << SDL_GetError() << std::endl;
	}
}

CWindow::~CWindow() {
	TTF_CloseFont(font);
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void CWindow::render() {
	SDL_Event e;
	bool quit = false;
	bool redraw = true;

	std::chrono::system_clock::time_point lastFrame = std::chrono::system_clock::now();

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_COMMA:
					this->fps = this->fps / 2;
					break;
				case SDLK_PERIOD:
					this->fps = this->fps * 2;
					break;
				}
//				quit = true;
			}
			//if (e.type == SDL_MOUSEBUTTONDOWN) {
			//	quit = true;
			//}
		}

		std::chrono::system_clock::time_point currentFrame = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> work_time = currentFrame - lastFrame;

		if (work_time.count() >= 1000/this->fps) {
			redraw = true;
		}

		if (redraw) {
			SDL_Color color = { 255, 255, 0, 255 };
			std::string str = std::to_string((int)(1000/work_time.count()));
			SDL_Surface *surf = TTF_RenderText_Blended(font, str.c_str(), color);
			SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, surf);
			SDL_FreeSurface(surf);

			SDL_RenderClear(this->renderer);

			//this->world->render();

			SDL_Rect dst;
			dst.x = 0;
			dst.y = 0;
			//Query the texture to get its width and height to use
			SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
			SDL_RenderCopy(this->renderer, texture, NULL, &dst);

			SDL_RenderPresent(this->renderer);
			redraw = false;
			lastFrame = std::chrono::system_clock::now();
		}
	}
}

void CWindow::init() {
//	this->world = new CRenderWorld();

//	this->world->init(this->renderer);
}