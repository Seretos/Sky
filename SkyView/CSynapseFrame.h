#pragma once
#pragma once
#if defined(_WIN32)
#ifdef CSYNAPSEFRAME_EXPORTS
#define CSYNAPSEFRAME_API __declspec(dllexport)
#else
#define CSYNAPSEFRAME_API __declspec(dllimport)
#endif
#else
#define CSYNAPSEFRAME_API
#endif
#include "../SkyNet/INeuron.h"
#include "CRenderFrame.h"

class CSynapseFrame : public CRenderFrame {
public: 
	CSynapseFrame(ISynapse* synapse,int startX, int startY, int endX, int endY);
	~CSynapseFrame();

	virtual CSYNAPSEFRAME_API void render();
protected:
	ISynapse* synapse;
};