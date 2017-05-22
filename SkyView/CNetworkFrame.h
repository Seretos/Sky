#pragma once
#if defined(_WIN32)
#ifdef CNETWORKFRAME_EXPORTS
#define CNETWORKFRAME_API __declspec(dllexport)
#else
#define CNETWORKFRAME_API __declspec(dllimport)
#endif
#else
#define CNETWORKFRAME_API
#endif
#include "../SkyNet/CNetworkManager.h"
#include "CRenderFrame.h"

class CNetworkFrame : public CRenderFrame
{
    public:
        CNetworkFrame(CNetworkManager* manager, int x, int y, int width, int height);
        ~CNetworkFrame();

        virtual CNETWORKFRAME_API void render();
    protected:
        CNetworkManager* manager;
    private:
};
