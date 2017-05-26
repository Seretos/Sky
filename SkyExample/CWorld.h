#pragma once
#include <string>
#include <vector>
#include "CWorldTile.h"

class CWorld {
public:
	CWorld();
	~CWorld();

	void load(std::string fileName);

	void render();
protected:
	std::vector<std::vector<CWorldTile*>> tiles;
};