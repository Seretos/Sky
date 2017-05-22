#include "stdafx.h"
#include "CRenderWindow.h"

CRenderWindow::CRenderWindow() : CRenderFrame() {
	this->event_queue = NULL;
	this->display = NULL;
	this->font = NULL;
}

CRenderWindow::~CRenderWindow() {
	al_destroy_display(this->display);
	al_destroy_event_queue(this->event_queue);
}

void CRenderWindow::init() {
	al_init();
	al_init_primitives_addon();

	this->display = al_create_display(1024, 768);
	this->event_queue = al_create_event_queue();
	this->font = al_create_builtin_font();

	al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
}

void CRenderWindow::render() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

    CRenderFrame::render();

    al_flip_display();
}
