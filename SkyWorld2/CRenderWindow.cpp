#include "stdafx.h"
#include "CRenderWindow.h"
#include <iostream>

CRenderWindow::CRenderWindow() : CRenderFrame() {
	this->display = NULL;
	this->event_queue = NULL;
	this->timer = NULL;
	this->ttf_font = NULL;
	this->fps = 60;
	this->w = 2048;
	this->h = 1024;
}

CRenderWindow::~CRenderWindow() {
	al_destroy_timer(this->timer);
	al_destroy_display(this->display);
	al_destroy_event_queue(this->event_queue);
}

void CRenderWindow::init() {
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	this->display = al_create_display(this->w, this->h);
	this->event_queue = al_create_event_queue();
	this->ttf_font = al_load_ttf_font("times.ttf", 16, 0);

	al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_identity_transform(&this->viewTransform);
	al_copy_transform(&this->overlayTransform, &this->viewTransform);
}

void CRenderWindow::render() {
	bool redraw = false;

	this->changeTimer(this->fps);
	double old_time = al_get_time();

	int x = 0;

	bool mouseMovePressed = false;
	bool hideRender = false;

	while (1) {
		ALLEGRO_EVENT e;
		al_wait_for_event(event_queue, &e);

		if (e.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (e.keyboard.keycode) {
			case ALLEGRO_KEY_COMMA:
				this->fps = this->fps / 2;
				this->changeTimer(this->fps);
				break;
			case ALLEGRO_KEY_FULLSTOP:
				this->fps = this->fps * 2;
				this->changeTimer(this->fps);
				break;
			case ALLEGRO_KEY_F10:
				hideRender = !hideRender;
				break;
			}
		}
		else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			mouseMovePressed = true;
		}
		else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouseMovePressed = false;
		}
		else if (e.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (e.mouse.dz == -1) {
				al_scale_transform(&this->viewTransform, 0.75, 0.75);
			}
			else if (e.mouse.dz == 1) {
				al_scale_transform(&this->viewTransform, 1.5, 1.5);
			}
			if (mouseMovePressed) {
				al_translate_transform(&this->viewTransform, e.mouse.dx, e.mouse.dy);
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			double new_time = al_get_time();
			double delta = new_time - old_time;
			int fps = 1 / delta;
			old_time = new_time;

			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			
			if (!hideRender) {
				al_use_transform(&this->viewTransform);

				CRenderFrame::render();

				al_use_transform(&this->overlayTransform);
			}
			al_draw_textf(ttf_font, al_map_rgb(255, 255, 0), 16, 32, 0, "FPS: %d", fps);
			al_flip_display();
			x++;
		}
	}
}

void CRenderWindow::changeTimer(int framesPerSecond) {
	al_destroy_timer(this->timer);
	this->timer = al_create_timer(1.0 / framesPerSecond);
	al_start_timer(this->timer);
	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
}