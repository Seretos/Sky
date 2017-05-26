#include "stdafx.h"
#include "CRenderWindow.h"
#include <allegro5/allegro_image.h>

CRenderWindow::CRenderWindow(ALLEGRO_DISPLAY* display) : CRenderFrame(0,0,0,0) {
	this->event_queue = NULL;
	this->display = display;
	this->font = NULL;
}

CRenderWindow::~CRenderWindow() {
	al_destroy_display(this->display);
	al_destroy_event_queue(this->event_queue);
}

void CRenderWindow::init() {
//	al_init();
//	al_init_primitives_addon();
//	al_init_image_addon();
	
//	this->event_queue = al_create_event_queue();
//	this->font = al_create_builtin_font();

//	al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
}

void CRenderWindow::render() {
	CRenderFrame::render();

    al_flip_display();
}
