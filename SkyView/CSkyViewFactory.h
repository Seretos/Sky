#pragma once
#include "../SkyNet/CSkyNetFactory.h"
#include "CRenderWindow.h"
#include "IWorldTile.h"

#if defined(_WIN32)
#ifdef SKYVIEWFACTORY_EXPORTS
#define SKYVIEWFACTORY_API __declspec(dllexport)
#else
#define SKYVIEWFACTORY_API __declspec(dllimport)
#endif
#else
#define SKYVIEWFACTORY_API
#endif

class CSkyViewFactory
{
public:
	static SKYVIEWFACTORY_API CRenderWindow* createRenderWindow(ALLEGRO_DISPLAY* display);
	static SKYVIEWFACTORY_API CRenderFrame* createNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height);

	static SKYVIEWFACTORY_API CRenderFrame* createWorldTileFrame(IWorldTile* tile, int x, int y, int type = 0);

	static SKYVIEWFACTORY_API CRenderFrame* createNeuronFrame(INeuron* neuron, int x, int y);
	static SKYVIEWFACTORY_API CRenderFrame* createSynapseFrame(ISynapse* synapse, int startX, int startY, int endX, int endY);
};
