/*
*
*	MP MAIN PROJECT - BASIC GAME STRUCTURE
*	JONATHAN PONCE, RAQUEL NAVARRO, MARC MONTAGUT
*
*/

#include <allegro5/allegro.h> // Allegro 5 (default)
#include <stdio.h> // L'utilitzem per "debugejar" per consola
#include <cstdio>
#include <allegro5/allegro_native_dialog.h> // Error Message dialog
#include "GameUtils.h"
#include "Game.h"

void Initialize();
void GameLoop();
void Destroyer();
void Error(const char *msg);

ALLEGRO_EVENT_QUEUE *eventQueue;
ALLEGRO_TIMER *fpsTimer;
ALLEGRO_DISPLAY *display;

Game game;

int main(int argc, char **argv)
{
	Initialize();
	printf("GAME_INITIALIZE_FINISHED\n");
	GameLoop();
	printf("GAME_LOOP_FINISHED\n");
	Destroyer();
	//printf("GAME_EXIT\n");
	
	return 0;
}

void Initialize()
{
	// Inicialitzem allegro
	if (!al_init())
	{
		Error("Allegro inicialitzation failed");
	}

	if (!al_init_image_addon())
	{
		Error("Allegro image addon incialitzation failed");
	}

	// Inicialitzem fpsTimer
	fpsTimer = al_create_timer(1.0f / 60);
	if (!fpsTimer)
	{
		Error("fpsTimer inicialitzation failed");
	}

	// Inicialitzem input teclat
	if (!al_install_keyboard())
	{
		Error("Keyboard inicialitzation failed");
	}

	// Inicialitzem display
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(640, 480);
	if (!display)
	{
		Error("Display inicialitzation failed");
	}

	// Inicialitzem eventQueue
	eventQueue = al_create_event_queue();
	if (!eventQueue)
	{
		Error("Event Queue inicialitzation failed");
	}

	// Registrem les diferents Events Sources(Inputs d'on poden procedir events)
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(fpsTimer));

	game.Initialize();

	al_set_target_bitmap(al_get_backbuffer(display));
}

void GameLoop()
{
	bool finish = false;
	bool draw = true; // draw ens diu quan hem de redibuixar el joc

	ALLEGRO_EVENT event;
	al_start_timer(fpsTimer); // Inicialitzem contador just abans de l'inici del main loop

	// Main game loop
	do
	{
		al_wait_for_event(eventQueue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			//printf("UPDATE\n");
			draw = true;
			game.Update();
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
				// game.SetKey();
			}
			
		}
		
		if (draw && al_is_event_queue_empty(eventQueue))
		{
			//printf("DRAW\n");
			draw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			game.Draw();
			al_flip_display();
		}
	} while (1);
}

void Destroyer()
{
	// Destroy dinamics structs

	al_destroy_event_queue(eventQueue);
	al_destroy_timer(fpsTimer);
	al_destroy_display(display);
}

void Error(const char *msg)
{
	// Mostra finestra error i surt del joc
	al_show_native_message_box(al_get_current_display(), "Error", "Error", msg, NULL, ALLEGRO_MESSAGEBOX_ERROR);
	exit(1);
}