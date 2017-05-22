#include "CNeuronFrame.h"

CNeuronFrame::CNeuronFrame()
{
    //ctor
}

CNeuronFrame::~CNeuronFrame()
{
    //dtor
}

void CNetworkFrame::render(){
    al_draw_rectangle(x,y,width,height,al_map_rgb(255,255,255),2);
}
