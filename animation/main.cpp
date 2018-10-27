#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Rect.h"
#include "xmlparser.h"
#include "spritesheet.h"
using namespace std;

int main() {

	cout << "animation test" << endl;
	//setup window and install

	al_init();
	al_init_image_addon();
	al_install_keyboard();
	ALLEGRO_DISPLAY *screen;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;

	screen = al_create_display(800, 600);
	timer = al_create_timer(1.0 / 12.0);
	queue = al_create_event_queue();
	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(screen));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	//sprite setup;
	sprites pop = sprites("pop");

	int size = 0;
	size = pop.getRange(0);
	for (int i = 0; i < size; i++) {
		cout << pop.getBox(0, i).getx() << endl;
	}
	bool running = true;
	int animationframe = 0;
	while (running) {
		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {// eixt procedure
			running = false;
			cout << "ending" << endl;
		}

		else if (event.type == ALLEGRO_EVENT_TIMER) {
			rect current = pop.getBox(0, animationframe);
			ALLEGRO_BITMAP *image = pop.getFromRect(current);

			al_clear_to_color(al_map_rgb(255, 255, 255));
			al_draw_scaled_bitmap(image,0,0, current.getw(), current.geth(),0,0, current.getw()*4, current.geth()*4,0);
			al_flip_display();

			ALLEGRO_KEYBOARD_STATE  keys;
			al_get_keyboard_state(&keys);
			if (al_key_down(&keys, ALLEGRO_KEY_SPACE)) {
				animationframe += 1;
				animationframe = animationframe % size;
			}
		}
	}


	system("pause");
	return 0;
}