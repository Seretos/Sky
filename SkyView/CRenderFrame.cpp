#include "stdafx.h"
#include "CRenderFrame.h"

CRenderFrame::CRenderFrame(int x, int y, int width, int height){
    this->frames = std::vector<CRenderFrame*>();
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

CRenderFrame::~CRenderFrame(){
    this->frames.clear();
}

void CRenderFrame::add(CRenderFrame* frame){
    this->frames.push_back(frame);
}

void CRenderFrame::erase(CRenderFrame* frame){
    //this->frames.erase(std::remove(this->frames.begin(), vec.end(), frame));
}

void CRenderFrame::render(){
    for(int i=0;i<this->frames.size();i++){
        frames.at(i)->render();
    }
}
