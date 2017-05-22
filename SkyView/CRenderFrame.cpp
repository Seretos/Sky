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
    this->frames.erase(frame);
}
