#include "stdafx.h"
#include "CRenderFrame.h"

CRenderFrame::CRenderFrame(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->frames = std::vector<CRenderFrame*>();
}

CRenderFrame::~CRenderFrame() {
	this->frames.clear();
}

void CRenderFrame::init() {

}

void CRenderFrame::render() {
	for (int i = 0; i < this->frames.size(); i++) {
		this->frames.at(i)->render();
	}
}

unsigned int CRenderFrame::size() {
	return this->frames.size();
}

void CRenderFrame::add(CRenderFrame* frame) {
	this->frames.push_back(frame);
}

CRenderFrame* CRenderFrame::get(unsigned int index) {
	return this->frames.at(index);
}