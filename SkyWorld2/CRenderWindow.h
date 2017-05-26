#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "CRenderFrame.h"

class CRenderWindow: public CRenderFrame
{
public:
	CRenderWindow();
	~CRenderWindow();

	void init();

	void render();
protected:
	void changeTimer(int framesPerSecond);

	int fps;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *ttf_font;
	ALLEGRO_TRANSFORM viewTransform;
	ALLEGRO_TRANSFORM overlayTransform;
};