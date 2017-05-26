#pragma once
#include "CRenderFrame.h"
#include "CWorld.h"

class CRenderWorld : public CRenderFrame {
public:
	CRenderWorld(CWorld* world);
	~CRenderWorld();

	void init();

	void render();
private:
	CWorld* world;
};