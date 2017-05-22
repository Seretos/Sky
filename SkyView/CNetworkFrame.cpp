#include "stdafx.h"
#include "CNetworkFrame.h"

CNetworkFrame::CNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height) : CRenderFrame(x,y,width,height)
{
    this->manager = manager;
}

CNetworkFrame::~CNetworkFrame()
{
    //dtor
}
