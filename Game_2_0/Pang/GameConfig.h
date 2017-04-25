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
	const int PLAYER_COLLIDER_WIDTH = 30;
	const int PLAYER_COLLIDER_HEIGHT = 110;

	// PLAYER_1
	const char PLAYER_1_SPRITE[30] = "assets/player/player.png";
	const int PLAYER_1_RIGHT = ALLEGRO_KEY_D;
	const int PLAYER_1_LEFT = ALLEGRO_KEY_A;
	const int PLAYER_1_UP = ALLEGRO_KEY_W;
	const int PLAYER_1_DOWN = ALLEGRO_KEY_S;
	const int PLAYER_1_JUMP = ALLEGRO_KEY_W;
	const int PLAYER_1_SHOT = ALLEGRO_KEY_SPACE;
	const int PLAYER_1_TOPSPEED_X = 6.0f;

	const GameUtils2D::Vector2 PLAYER_1_SPEED = { 0.2f, 4.0f };
	const float PLAYER_1_JUMPSPEED = 20.5f;
	const float PLAYER_1_FALLING_MOV_FACTOR = 0.4f;
	const float PLAYER_1_JUMPING_MOV_FACTOR = 0.85f;
	
	const int PLAYER_1_SOURCEPOSITION_X = SCREEN_WIDTH / 3;

	// ARROW
	const int ARROW_BODY_WIDTH = 16;
	const int ARROW_HEAD_WIDTH = 32;
	const int ARROW_HEAD_HEIGHT = 32;
	const float ARROW_SPEED = 12.0f;
	const int ARROW_BODY_MAX_LENGHT = SCREEN_HEIGHT - ARROW_HEAD_HEIGHT;
	const int ARROW_DURATION = 40;

	// BUBBLES
	const int BUBBLES_SEQUENCES_LENGHT = 2;
	const int BUBBLES_SEQUENCE_FRAMES = 4;
	const int BUBBLES_SEQUENCE_DURATION = 10;
	const int BUBBLES_MAX_HEIGT = 150;
	const float BUBBLES_GRAVITY_Y = 0.35f;

	const int BUBBLES_CATEGORIES_LENGHT = 5;
	const int BUBBLES_RADIUS[BUBBLES_CATEGORIES_LENGHT] = { 8, 16, 32, 64, 128 };
	const GameUtils2D::Vector2 BUBBLES_SPEED[BUBBLES_CATEGORIES_LENGHT] =
	{
		{ 5.5f, 21.f },
		{ 5.25f, 20.5f },
		{ 5.0f, 20.5f },
		{ 4.75f, 20.0f },
		{ 4.5f, 18.0f }
	};
	
	// LEVELS
	const int LEVELS_LENGHT = 1;

	//LEVEL_01
		// BACKGROUND
	const char LEVEL_01_BACKGROUND [45] = "assets/levels/level_01/background.png";
	const int LEVEL_01_BACKGROUNDANIMS_LENGHT = 2;
	const char LEVEL_01_BACKGROUNDANIMS_0 [45] = "assets/levels/level_01/bgAnim_0.png";
	const char LEVEL_01_BACKGROUNDANIMS_1 [45] = "assets/levels/level_01/bgAnim_1.png";
	const Vector2 LEVEL_01_BACKGROUNDANIMS_0_LENGHT = { 256, 256 };


		//BUBBLES
	const int LEVEL_01_BUBBLEMANAGERS_LENGHT = 1;
	const int LEVEL_01_BUBBLEMANAGERS_0_CAT = 3;

}