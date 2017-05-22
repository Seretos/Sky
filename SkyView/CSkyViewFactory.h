#pragma once
#include "../SkyNet/CSkyNetFactory.h"
#include "CRenderWindow.h"

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
	static SKYVIEWFACTORY_API CRenderWindow* createRenderWindow();
};
