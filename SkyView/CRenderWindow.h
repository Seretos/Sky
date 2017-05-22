#pragma once
#if defined(_WIN32)
#ifdef CRENDERWINDOW_EXPORTS
#define CRENDERWINDOW_API __declspec(dllexport)
#else
#define CRENDERWINDOW_API __declspec(dllimport)
#endif
#else
#define CRENDERWINDOW_API
#endif
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

class CRenderWindow {
public:
	CRenderWindow();
	~CRenderWindow();

	virtual CRENDERWINDOW_API void init();
	virtual CRENDERWINDOW_API int render();
	virtual void draw();
protected:
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_FONT* font;
};