#pragma once
#if defined(_WIN32)
#ifdef CWORLDTILE_EXPORTS
#define CWORLDTILE_API __declspec(dllexport)
#else
#define CWORLDTILE_API __declspec(dllimport)
#endif
#else
#define CWORLDTILE_API
#endif
#include "CRenderFrame.h"
#include "IWorldTile.h"

class CWorldTileFrame: public CRenderFrame {
public:
	CWorldTileFrame(IWorldTile* tile, int x, int y, int type = 0);
	~CWorldTileFrame();

	virtual CWORLDTILE_API void render();
protected:
	IWorldTile* tile;
	int type;
};