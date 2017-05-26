#include "stdafx.h"
#include "CRenderFrame.h"

CRenderFrame::CRenderFrame(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->frames = std::vector<CRenderFrame*>();
}
CRenderFrame::~CRenderFrame() {
	this->frames.clear();
}

void CRenderFrame::init() {

}
void CRenderFrame::render(double scale) {
	for (int i = 0; i < this->frames.size(); i++) {
		this->frames.at(i)->render(scale);
	}
}

int CRenderFrame::size() {
	return this->frames.size();
}
CRenderFrame* CRenderFrame::get(int index) {
	return this->frames.at(index);
}
void CRenderFrame::add(CRenderFrame* frame) {
	this->frames.push_back(frame);
}