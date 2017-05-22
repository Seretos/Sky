#include "stdafx.h"
#include "CSkyViewFactory.h"
#include "CNetworkWindow.h"

CRenderWindow* CSkyViewFactory::createNetworkWindow(CNetworkManager* manager) {
	CNetworkWindow* window = new CNetworkWindow(manager);
	return (CRenderWindow*)window;
}