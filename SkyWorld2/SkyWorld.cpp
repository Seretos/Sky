// SkyWorld.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
//#include "CRenderWindow.h"
#include "CWorld.h"
//#include "CRenderWorld.h"

int main()
{
	//al_init();
	//al_init_primitives_addon();
	//al_init_image_addon();
	//al_init_font_addon();
	//al_init_ttf_addon();

	//this->timer = al_create_timer(1.0 / 60);
	//ALLEGRO_DISPLAY* display = al_create_display(2048, 1024);
	//this->event_queue = al_create_event_queue();
	//al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_flip_display();
	//al_draw_filled_rectangle(10, 10, 100, 100, al_map_rgb(255, 255, 0));
	//al_flip_display();
	//al_rest(3.0);
	//CRenderWindow* window = new CRenderWindow();

	//window->init();

	CWorld* world = new CWorld();
	world->loadMap("testmap.png");

	//CRenderWorld* renderWorld = new CRenderWorld(world);

	//window->add((CRenderFrame*)renderWorld);

	//window->render();
    return 0;
}

