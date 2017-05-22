#pragma once
#if defined(_WIN32)
#ifdef CRENDERFRAME_EXPORTS
#define CRENDERFRAME_API __declspec(dllexport)
#else
#define CRENDERFRAME_API __declspec(dllimport)
#endif
#else
#define CRENDERFRAME_API
#endif
#include <vector>

class CRenderFrame
{
    public:
        CRenderFrame();
        ~CRenderFrame();

        virtual CRENDERFRAME_API void render();

        CRENDERFRAME_API void add(CRenderFrame* frame);
        CRENDERFRAME_API void erase(CRenderFrame* frame);
    protected:
        std::vector<CRenderFrame*> frames;
};