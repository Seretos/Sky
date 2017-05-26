#pragma once
#include <vector>
#include <SDL.h>

class CRenderFrame {
public:
	CRenderFrame(SDL_Renderer* renderer);
	~CRenderFrame();

	virtual void init();
	virtual void render(double scale);

	int size();
	CRenderFrame* get(int index);
	void add(CRenderFrame* frame);
protected:
	SDL_Renderer* renderer;
	std::vector<CRenderFrame*> frames;
};