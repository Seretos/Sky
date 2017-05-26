#pragma once

class CWorldTile {
public:
	CWorldTile(int x, int y, bool water);

	void render();
private:
	int x;
	int y;
	bool water;
};