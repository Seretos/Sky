#include "stdafx.h"
#include "CRenderSprite.h"
#include <iostream>

CRenderSprite::CRenderSprite(SDL_Renderer* renderer,SDL_Texture *texture, int w, int h, int currentStep, int speed) {
	this->renderer = renderer;
	this->texture = texture;
	this->w = w;
	this->h = h;
	this->currentStep = currentStep;
	this->speed = speed;
	this->speedCount = 0;

	this->textureSize.x = 0;
	this->textureSize.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &this->textureSize.w, &this->textureSize.h);

	this->cols = this->textureSize.w / w;
	this->rows = this->textureSize.h / h;

	if (this->currentStep > (this->cols*this->rows)) {
		int remove = this->currentStep / (this->cols*this->rows);
		this->currentStep -= remove*(this->cols*this->rows);
	}
}

void CRenderSprite::render(SDL_Rect* output) {
	int currentRow = 0;
	if (this->currentStep > 0) {
		currentRow = this->currentStep / (this->rows*this->cols);
	}
	int currentCol = this->currentStep - (currentRow * this->cols);

	SDL_Rect source;
	source.x = currentCol * this->w;
	source.y = currentRow * this->h;
	source.w = this->w;
	source.h = this->h;

	//std::cout << source.x << ' ' << source.y << ' ' << source.w << ' ' << source.h << '\n';

	SDL_RenderCopy(this->renderer, this->texture, &source, output);
	//this->speedCount++;
	//if (this->speedCount > this->speed) {
		this->currentStep++;
		if (this->currentStep > (this->cols * this->rows) - 1) {
			this->currentStep = 0;
		}
		//this->speedCount = 0;
	//}
}