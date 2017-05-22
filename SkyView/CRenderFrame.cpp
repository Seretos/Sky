#include "stdafx.h"
#include "CRenderFrame.h"

CRenderFrame::CRenderFrame(){
    this->frames = std::vector<CRenderFrame*>();
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
