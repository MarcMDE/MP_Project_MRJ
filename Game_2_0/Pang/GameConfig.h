#pragma once
#include "allegro5/allegro.h"
#include "GameUtils2D.h"

namespace GameConfig
{
	// GENERAL
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int FIXED_FRAMERATE = 60;
	const int GROUND_Y = SCREEN_HEIGHT;
	const float GRAVITY_Y = 1.0f;
	const float GROUND_FRICTION_X = 0.05f;

	const int PLAYER_WIDTH = 128;
	const int PLAYER_HEIGHT = 128;

	// PLAYER_1
	const int PLAYER_1_RIGHT = ALLEGRO_KEY_D;
	const int PLAYER_1_LEFT = ALLEGRO_KEY_A;
	const int PLAYER_1_UP = ALLEGRO_KEY_W;
	const int PLAYER_1_DOWN = ALLEGRO_KEY_S;
	const int PLAYER_1_JUMP = ALLEGRO_KEY_SPACE;
	const int PLAYER_1_SHOT = ALLEGRO_KEY_J;
	const int PLAYER_1_TOPSPEED_X = 6.0f;

	const GameUtils2D::Vector2 PLAYER_1_SPEED = { 0.1f, 4.0f };
	const float PLAYER_1_JUMPSPEED = 20.5f;
	const float PLAYER_1_FALLING_MOV_FACTOR = 0.4f;
	const float PLAYER_1_JUMPING_MOV_FACTOR = 0.85f;
	
	const int PLAYER_1_SOURCEPOSITION_X = SCREEN_WIDTH / 3;

	// BUBBLES
	const int BUBBLES_SEQUENCES_LENGHT = 2;
	const int BUBBLES_SEQUENCE_FRAMES = 4;
	const int BUBBLES_SEQUENCE_DURATION = 10;
	
	const int BUBBLES_CATEGORIES_LENGHT = 5;
	const int BUBBLES_RADIUS[BUBBLES_CATEGORIES_LENGHT] = { 8, 16, 32, 64, 128 };
	const GameUtils2D::Vector2 BUBBLES_SPEED[BUBBLES_CATEGORIES_LENGHT] =
	{
		{ 5.5f, 30.0f },
		{ 5.0f, 30.0f },
		{ 4.5f, 30.0f },
		{ 4.0f, 30.0f },
		{ 3.5f, 30.0f }
	};
	
	
}