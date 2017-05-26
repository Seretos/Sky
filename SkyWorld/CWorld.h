#pragma once
#include <string>

#define WORLD_TILE_TYPE_WATER 0
#define WORLD_TILE_TYPE_GROUND 1
#define WORLD_TILE_SIZE 64

class CWorldTile {
public:
	CWorldTile(int x, int y,int type = WORLD_TILE_TYPE_WATER, int food = 0);
	~CWorldTile();

	int getFood();
	void setFood(int food);

	int getType();
private:
	int type;
	int food;
	int x;
	int y;
};

class CWorld {
public:
	CWorld();
	~CWorld();

	void import(std::string fileName);

	//CWorldTile* findTileByPosition(int x, int y);

	int sizeX();
	int sizeY();
	CWorldTile* get(int x, int y);
protected:
	CWorldTile*** tiles;
	int width;
	int height;
};