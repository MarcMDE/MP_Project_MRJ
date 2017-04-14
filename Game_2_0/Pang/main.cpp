/*
*
*	MP MAIN PROJECT - BASIC GAME STRUCTURE
*	JONATHAN PONCE, RAQUEL NAVARRO, MARC MONTAGUT
*
*/

#include <allegro5/allegro.h> // Allegro 5 (default)
#include <stdio.h> // L'utilitzem per "debugejar" per consola
#include <allegro5/allegro_native_dialog.h> // Error Message dialog
#include <allegro5/allegro_image.h> // Image addon ("Draw")
#include <allegro5/allegro_primitives.h> // Debugging
#include "GameConfig.h"
#include "Pang.h"

void Initialize();
void GameLoop();
void Destroyer();
void Error(char *msg);

ALLEGRO_EVENT_QUEUE *eventQueue;
ALLEGRO_TIMER *fpsTimer;
ALLEGRO_DISPLAY *display;

bool finish = false;
bool draw = true;
ALLEGRO_EVENT event;

Pang pang;

int main()
{
	printf("GAME_INITIALIZE\n");
	Initialize();
	printf("GAME_UPDATE\n");
	GameLoop();
	printf("GAME_DESTROYER\n");
	Destroyer();

	return 0;
}

void Initialize()
{
	if (!al_init())
	{
		Error("Allegro initialitzation failed");
	}

	if (!al_init_image_addon())
	{
		Error("Allegro image addon initialitzation failed");
	}

	if (!al_init_primitives_addon())
	{
		Error("Allegro primitives addon initialitzation failed");
	}

	// Set FPS timer
	fpsTimer = al_create_timer(1.0f / GameConfig::FIXED_FRAMERATE);
	if (!fpsTimer)
	{
		Error("fpsTimer initialitzation failed");
	}

	if (!al_install_keyboard())
	{
		Error("Keyboard initialitzation failed");
	}

	// Set display
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
	if (!display)
	{
		Error("Display initialitzation failed");
	}

	// Set eventQueue
	eventQueue = al_create_event_queue();
	if (!eventQueue)
	{
		Error("Event Queue initialitzation failed");
	}

	// Registrem les diferents Events Sources(Inputs d'on poden procedir events)
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(fpsTimer));

	pang.Initialize();

	al_set_target_bitmap(al_get_backbuffer(display));
}

void GameLoop()
{
	al_start_timer(fpsTimer); // Inicialitzem contador just abans de l'inici del main loop

	// Main game loop
	do
	{
		al_wait_for_event(eventQueue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			// UPDATE
			pang.Update();

			draw = true;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				// EXIT GAME
				finish = true;
			}
			else
			{
				// Other keys pressed
			}
		}

		//if (draw && al_is_event_queue_empty(eventQueue))
		if (draw)
		{
			// DRAW
			draw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			// GAME DRAW
			pang.Draw();

			al_flip_display();
		}
	} while (!finish);
}

void Destroyer()
{
	// Destroy dinamics structs

	al_destroy_event_queue(eventQueue);
	al_destroy_timer(fpsTimer);
	al_destroy_display(display);
	//pang.~Pang();
}

void Error(char *msg)
{
	// Mostra finestra error i surt del joc
	al_show_native_message_box(al_get_current_display(), "Error", "Error", msg, NULL, ALLEGRO_MESSAGEBOX_ERROR);
	exit(1);
}
