#pragma once
#include <vector>

class CRenderFrame {
public:
	CRenderFrame(int x = 0, int y=0, int w = 0, int h = 0);
	~CRenderFrame();

	virtual void init();
	virtual void render();

	void add(CRenderFrame* frame);
	unsigned int size();
	CRenderFrame* get(unsigned int index);
protected:
	std::vector<CRenderFrame*> frames;
	int x;
	int y;
	int w;
	int h;
};