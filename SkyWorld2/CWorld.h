#pragma once
#include <vector>

#define TILE_TYPE_WATER 0
#define TILE_TYPE_LAND 1

class CWorldTile {
public:
	CWorldTile(int type = TILE_TYPE_WATER);
	~CWorldTile();

	int getType();
	int getFood();
	void setFood(int food);
protected:
	int type;
	int food;
};

class CWorld {
public:
	CWorld();
	~CWorld();

	void loadMap(std::string fileName);

	int sizeX();
	int sizeY();
	CWorldTile* get(int x,int y);
private:
	CWorldTile*** tiles;
	int width;
	int height;
};