// SkyExample.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include "../SkyNet/CSkyNetFactory.h"
#include "../SkyView/CSkyViewFactory.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "CWorld.h"

void loadWorld(std::string file, CRenderWindow* window) {
	ALLEGRO_BITMAP  *image = NULL;
	image = al_load_bitmap(file.c_str());
	al_draw_bitmap(image, 200, 200, 0);
}

int main() {
	/*al_init();
	al_init_primitives_addon();
	al_init_image_addon();

	ALLEGRO_DISPLAY* display = al_create_display(2048, 1024);

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	//	this->font = al_create_builtin_font();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	CWorld* world = new CWorld();*/

	//ALLEGRO_BITMAP  *image = NULL;
	//image = al_load_bitmap("testmap.png");
	//al_draw_bitmap(image, 200, 200, 0);
	//al_flip_display();
	//CRenderWindow* window = CSkyViewFactory::createRenderWindow(display);
	//INeuron* neuron = CSkyNetFactory::createNeuron();
	//CRenderFrame* frame = CSkyViewFactory::createNeuronFrame(neuron, 10, 10);
	
	//window->init();
	//window->add(frame);

	//loadWorld("testmap.png",window);
	/*
	world->load("testmap.png");

	std::cout << "loaded\n";
	while (1) {
		al_clear_to_color(al_map_rgb(0, 0, 0)); 
		world->render();
		al_flip_display();
		//al_clear_to_color(al_map_rgb(0, 0, 0));
		//window->render();
		//world->render();
		//al_flip_display();
	}*/

	al_init();
	al_init_primitives_addon();
	//al_init_image_addon();
	//al_init_font_addon();
	//al_init_ttf_addon();

	//this->timer = al_create_timer(1.0 / 60);
	ALLEGRO_DISPLAY* display = al_create_display(2048, 1024);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	//	this->font = al_create_builtin_font();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	//this->event_queue = al_create_event_queue();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_flip_display();
	al_draw_filled_rectangle(10, 10, 100, 100, al_map_rgb(255, 255, 0));
	al_flip_display();
	al_rest(3.0);
	return 0;
}