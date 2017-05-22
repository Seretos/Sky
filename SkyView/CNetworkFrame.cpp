#include "stdafx.h"
#include "CNetworkFrame.h"
#include <allegro5/allegro_primitives.h>

CNetworkFrame::CNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height) : CRenderFrame(x,y,width,height)
{
    this->manager = manager;
}

CNetworkFrame::~CNetworkFrame()
{
    //dtor
}

void CNetworkFrame::render(){
    al_draw_rectangle(x,y,width,height,al_map_rgb(255,255,255),2);
}
