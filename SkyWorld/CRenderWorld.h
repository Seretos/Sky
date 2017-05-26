#pragma once
#include "CRenderFrame.h"
#include "CWorld.h"
#include "CRenderTile.h"

class CRenderWorld: public CRenderFrame {
public:
	CRenderWorld(SDL_Renderer* renderer, CWorld* world);

	void init();
	void render(double scale);
protected:
	CWorld* world;
	CRenderTile** tiles;
};