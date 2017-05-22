#include "stdafx.h"
#include "CSkyViewFactory.h"
#include "CNetworkFrame.h"

CRenderWindow* CSkyViewFactory::createRenderWindow(int width, int height) {
    CRenderWindow* window = new CRenderWindow(width,height);
	return window;
}

CRenderFrame* CSkyViewFactory::createNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height){
    CNetworkFrame* frame = new CNetworkFrame(manager,x,y,width,height);
    return (CRenderFrame*)frame;
}
