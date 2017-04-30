#pragma once
#include "allegro5/allegro.h"
#include "GameUtils2D.h"

// CORRETGIR CLASSES AMB NOVES CONST (NOMENCLATURA)

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
	const GameUtils2D::Vector2 PLAYER_SPEED = { 0.2f, 4.0f };
	const float PLAYER_JUMPSPEED = 20.5f;
	const float PLAYER_FALLING_MOV_FACTOR = 0.4f;
	const float PLAYER_JUMPING_MOV_FACTOR = 0.85f;

	// PLAYER_1

	const int PLAYERS_LENGT = 1;
	const char PLAYER_SPRITE[PLAYERS_LENGT][50] = { "assets/character/character_01_spriteSheet.png" };
	const char PLAYER_RIGHT[PLAYERS_LENGT] = { ALLEGRO_KEY_D };
	const int PLAYER_LEFT[PLAYERS_LENGT] = { ALLEGRO_KEY_A };
	const int PLAYER_UP[PLAYERS_LENGT] = { ALLEGRO_KEY_W };
	const int PLAYER_DOWN[PLAYERS_LENGT] = { ALLEGRO_KEY_S };
	const int PLAYER_JUMP[PLAYERS_LENGT] = { ALLEGRO_KEY_W };
	const int PLAYER_SHOT[PLAYERS_LENGT] = { ALLEGRO_KEY_SPACE };
	const float PLAYER_TOPSPEED_X[PLAYERS_LENGT] = { 6.0f };


	const int PLAYER_SOURCEPOSITION_X[PLAYERS_LENGT] = { SCREEN_WIDTH / 3 };

	// ARROW
	const char ARROW_SPRITE[45] = "assets/character/arrow_spriteSheet.png";
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


	char LEVEL_BACKGROUND[LEVELS_LENGHT][40] = { "assets/levels/level_01/background.png" };

	const int LEVEL_BACKGROUNDANIMS_LENGHT = 3;
	const char LEVEL_BACKGROUNDANIMS[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT][45] =
	{
		{
			"assets/levels/level_01/bgAnim_0.png",
			"assets/levels/level_01/bgAnim_1.png" ,
			"assets/levels/level_01/bgAnim_2.png"
		}
	};

	const GameUtils2D::Vector2 LEVEL_BACKGROUNDANIM_LENGHT[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] =
	{
		{
			{ 128, 128 },
			{ 512, 512 },
			{ 256, 256 }
		}
	};
	const int LEVEL_BACKGROUNDANIM_FRAMES[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 4, 4, 4 } };
	const int LEVEL_BACKGROUNDANIM_COLUMNS[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 2, 2, 2 } };
	const int LEVEL_BACKGROUNDANIM_DURATION[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 20, 20, 20 } };
	const GameUtils2D::Vector2 LEVEL_BACKGROUNDANIM_POSITION[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] =
	{
		{
			{10, 10},
			{SCREEN_WIDTH - 550, 50},
			{200, 200}
		}
	};

	const int LEVEL_BUBBLEMANAGERS_LENGHT[LEVELS_LENGHT] = { 1 };
	const int LEVEL_BUBBLEMANAGERS_CAT[LEVELS_LENGHT] = { 3 };
}