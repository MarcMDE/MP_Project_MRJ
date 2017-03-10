
#include <allegro5/allegro.h> // Allegro 5
#include <allegro5/allegro_font.h> // Incluim la llibreria que conte les utilitats corresponents a les Fonts (Add-on). El Add-on corresponent ha d'estar activat (Project->Properties->Allegro5->Add-ons)
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h> // L'utilitzem per "debugejar" per consola

void BasicAllegroExemple();
void BasicAllegroBouncingBitmapExample();
void MainTest();

int main()
{
	//BasicAllegroExemple();
	BasicAllegroBouncingBitmapExample();
	MainTest();
	
	return 0;
}

void MainTest()
{
	al_init();
	al_init_font_addon();
	al_init_image_addon();
	
	ALLEGRO_DISPLAY* mainDisplay = al_create_display(256, 128);
	ALLEGRO_FONT* defaultFont = al_create_builtin_font();


}

void BasicAllegroExemple()
{
	al_init(); // Inicialitzem utilitats basiques de Allegro 5
	al_init_font_addon(); // Inicialitzem les diferents utilitats del "Add-on"
	ALLEGRO_DISPLAY* display = al_create_display(800, 600); // Creem finestra
	ALLEGRO_FONT* font = al_create_builtin_font(); // Inicialitzem font
	al_clear_to_color(al_map_rgb(255, 255, 255)); // "Borrem" finestra
	al_draw_text(font, al_map_rgb(0, 0, 0), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!"); // Escribim text amb font cargada
	al_flip_display(); // back buffer <-> front buffer

	// Mostra finestra error, evitant l'us de la consola
	al_show_native_message_box(al_get_current_display(),
		"Window Title",
		"Content Title",
		"The error message here",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);

	al_rest(5.0); // "sleep"
	al_destroy_display(display); // "Destroys" and frees the display memory
}

void BasicAllegroBouncingBitmapExample()
{
	const float FPS = 60;
	const int SCREEN_W = 640;
	const int SCREEN_H = 480;
	const int BOUNCER_SIZE = 32;

		ALLEGRO_DISPLAY *display = NULL;
		ALLEGRO_EVENT_QUEUE *event_queue = NULL;
		ALLEGRO_TIMER *timer = NULL;
		ALLEGRO_BITMAP *bouncer = NULL;
		float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
		float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
		float bouncer_dx = -4.0, bouncer_dy = 4.0;
		bool redraw = true;

		al_init();
		timer = al_create_timer(1.0 / FPS);
		display = al_create_display(SCREEN_W, SCREEN_H);
		bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
		al_set_target_bitmap(bouncer);
		al_clear_to_color(al_map_rgb(255, 0, 255));
		al_set_target_bitmap(al_get_backbuffer(display));
		event_queue = al_create_event_queue();

		al_register_event_source(event_queue, al_get_display_event_source(display));

		al_register_event_source(event_queue, al_get_timer_event_source(timer));

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_flip_display();

		al_start_timer(timer);

		while (1)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER) {
				if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
					bouncer_dx = -bouncer_dx;
				}

				if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
					bouncer_dy = -bouncer_dy;
				}

				bouncer_x += bouncer_dx;
				bouncer_y += bouncer_dy;

				redraw = true;
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}

			if (redraw && al_is_event_queue_empty(event_queue)) {
				redraw = false;

				al_clear_to_color(al_map_rgb(0, 0, 0));

				al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

				al_flip_display();
			}
		}

		al_destroy_bitmap(bouncer);
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
}


/* Simple Allegro 5 tilemap example from allegro.cc:
*
* http://www.allegro.cc/forums/thread/606482
*
* Also see here for more info:
*
* http://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial
*
* Place fixed_font.tga and icon.tga from the Allegro 5 examples/data
* folder next to the .exe and there will be an FPS counter and an
* icon.
*
* Left mouse = Pan
* Right mouse = Rotozoom
* Esc = Quit
*/

