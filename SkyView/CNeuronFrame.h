#pragma once
#if defined(_WIN32)
#ifdef CNEURONFRAME_EXPORTS
#define CNEURONFRAME_API __declspec(dllexport)
#else
#define CNEURONFRAME_API __declspec(dllimport)
#endif
#else
#define CNEURONFRAME_API
#endif
#include "../SkyNet/INeuron.h"
#include "CRenderFrame.h"

class CNeuronFrame : public CRenderFrame
{
    public:
        CNeuronFrame(INeuron* neuron, int x, int y);
        ~CNeuronFrame();

        virtual CNEURONFRAME_API void render();

		virtual int getX();
		virtual int getY();

		INeuron* getNeuron();
    protected:
		INeuron* neuron;
    private:
};
