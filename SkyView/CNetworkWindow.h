#pragma once
#include "CRenderWindow.h"
#include "../SkyNet/CNetworkManager.h"
#include <vector>
#include "CRenderNeuron.h"

#if defined(_WIN32)
#ifdef CNETWORKWINDOW_EXPORTS
#define CNETWORKWINDOW_API __declspec(dllexport)
#else
#define CNETWORKWINDOW_API __declspec(dllimport)
#endif
#else
#define CNETWORKWINDOW_API
#endif

class CNetworkWindow : CRenderWindow {
public:
	CNetworkWindow(CNetworkManager* manager);
	~CNetworkWindow();

	//CNETWORKWINDOW_API void init();

	void draw();
private:
	void addLayerNeurons(CLayer* layer, int x);

	CNetworkManager* manager;
	std::vector<CRenderNeuron*> neurons;
};