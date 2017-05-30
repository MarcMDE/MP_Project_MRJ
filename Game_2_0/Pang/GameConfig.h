#pragma once

#include "allegro5/allegro.h"
#include "GameUtils2D.h"

#define DEBUG

namespace GameConfig
{
	// GENERAL
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int FIXED_FRAMERATE = 60;
	const int GROUND_Y = SCREEN_HEIGHT - 20;
	const float GRAVITY_Y = 1.0f;
	const float GROUND_FRICTION_X = 0.05f;
	const int MAX_ATTEMPTS = 0;

	const int PLAYER_WIDTH = 128;
	const int PLAYER_HEIGHT = 128;
	const int PLAYER_COLLIDER_WIDTH = 30;
	const int PLAYER_COLLIDER_HEIGHT = 110;
	const GameUtils2D::Vector2 PLAYER_SPEED = { 0.2f, 4.0f };
	const float PLAYER_JUMPSPEED = 20.5f;
	const float PLAYER_FALLING_MOV_FACTOR = 0.4f;
	const float PLAYER_JUMPING_MOV_FACTOR = 0.85f;

	const int KEY_CONFIRM = ALLEGRO_KEY_ENTER;
	const int KEY_ERASE = ALLEGRO_KEY_BACKSPACE;

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
	const char BUBBLES_SPRITE[BUBBLES_CATEGORIES_LENGHT][45] = 
	{
		{ "assets/bubbles/Bubble_SpriteSheet_0.png" },
		{ "assets/bubbles/Bubble_SpriteSheet_1.png" }, 
		{ "assets/bubbles/Bubble_SpriteSheet_2.png" }, 
		{ "assets/bubbles/Bubble_SpriteSheet_3.png" }, 
		{ "assets/bubbles/Bubble_SpriteSheet_4.png" } 
	};
	const int BUBBLES_RADIUS[BUBBLES_CATEGORIES_LENGHT] = { 8, 16, 32, 64, 128 };
	const GameUtils2D::Vector2 BUBBLES_SPEED[BUBBLES_CATEGORIES_LENGHT] =
	{
		{ 5.5f, 21.f },
		{ 5.25f, 20.5f },
		{ 5.0f, 20.5f },
		{ 4.75f, 19.5f },
		{ 4.5f, 18.0f}
	};

	// LEVELS
	enum PangLevels { LEVEL_01 = 0, LEVEL_02, LEVEL_03 };

	const int LEVELS_LENGHT = 1;

	const char LEVEL_BACKGROUND[LEVELS_LENGHT][40] = 
	{ 
		"assets/levels/level_01/background.png" 
		//"assets/levels/level_02/background.png" 
	};

	const int LEVEL_BACKGROUNDANIMS_LENGHT = 3;
	const char LEVEL_BACKGROUNDANIMS[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT][45] =
	{
		{
			"assets/levels/level_01/bgAnim_0.png",
			"assets/levels/level_01/bgAnim_1.png",
			"assets/levels/level_01/bgAnim_2.png"
		}/*,
		{
			"assets/levels/level_01/bgAnim_0.png",
			"assets/levels/level_01/bgAnim_1.png",
			"assets/levels/level_01/bgAnim_2.png"
		}*/
	};

	const GameUtils2D::Vector2 LEVEL_BACKGROUNDANIM_LENGHT[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] =
	{
		{
			// LEVEL 01
			{ 512, 512 },
			{ 512, 512 },
			{ 1280, 110 }
		}//,
		//{
		//	// LEVEL 02
		//	{ 512, 512 },
		//	{ 512, 512 },
		//	{ 1280, 110 }
		//}

	};

	const int LEVEL_BACKGROUNDANIM_FRAMES[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 4, 4, 1 }/*,{ 4, 4, 1 } */};
	const int LEVEL_BACKGROUNDANIM_COLUMNS[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 2, 2, 1 }/*,{ 2, 2, 1 }*/ };
	const int LEVEL_BACKGROUNDANIM_DURATION[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] = { { 60, 20, -1 }/*,{ 60, 20, -1 } */};
	const GameUtils2D::Vector2 LEVEL_BACKGROUNDANIM_POSITION[LEVELS_LENGHT][LEVEL_BACKGROUNDANIMS_LENGHT] =
	{
		{
			{250, GROUND_Y - 276}, // TREE
			{SCREEN_WIDTH - 175, 125}, // SUN
			{0 + 640, GROUND_Y - 50} // FENCE
		}//,
		//{
		//	{ 250, GROUND_Y - 276 }, // TREE
		//	{ SCREEN_WIDTH - 175, 125 }, // SUN
		//	{ 0 + 640, GROUND_Y - 50 } // FENCE
		//}
	};

	// TODO: Detectar colisio amb multiples Emitters!
	const int LEVEL_BUBBLEMANAGERS_LENGHT[LEVELS_LENGHT] = { 1/*, 1 */};
	const int LEVEL_BUBBLEMANAGERS_CAT[LEVELS_LENGHT][3] = { {3, 3, 3}/*, {4, 4, 4 } */};

	// PARTICLES
	enum Emitters{TEST = 0};
	const int EMITTERS_LENGHT = 1;
	const char PARTICLES_SPRITE[EMITTERS_LENGHT][45] = { "assets/particles/test_particle.png" };
	const int PARTICLES_LENGHT[EMITTERS_LENGHT] = { 30 };
	const float PARTICLES_MIN_SPEED[EMITTERS_LENGHT] = { -2.0f };
	const float PARTICLES_MAX_SPEED[EMITTERS_LENGHT] = { 2.0f };
	const int PARTICLES_MIN_DURATION[EMITTERS_LENGHT] = { 60 };
	const int PARTICLES_MAX_DURATION[EMITTERS_LENGHT] = { 90 };
	const float PARTICLES_GRAVITY = 0.05f;

	// POWERUPS
	enum PowerUps{HEALTH_UP = 0, EXPLOSIVE_DIARREA, PARALYSIS};
	const int POWERUPS_LENGHT = 3;
	const float POWERUPS_GRAVITY = 0.05f;
	const char POWERUPS_SPRITE[POWERUPS_LENGHT][45] = 
	{
		"assets/powerups/health_up.png", 
		"assets/powerups/explosive_diarrea.png", 
		"assets/powerups/paralysis.png"
	};
	const int POWERUPS_DURATION = 4 * FIXED_FRAMERATE;
	const int POWERUPS_SPAWNPROB = 30; // %
	const int POWERUPS_PARALYISIS_DURATION = 4 * FIXED_FRAMERATE;

	// UI
	enum Titles { LEVEL_COMPLETE = 0, GAME_OVER, GAME_COMPLETE, LEVEL };

	const char UI_PRESS_SPACE_MESSAGE[35] = "Press <SPACE> to START";
	const char UI_LEVEL_COMPLETE_MESSAGE[25] = "LEVEL COMPLETE!";
	const char UI_GAME_OVER_MESSAGE[20] = "GAME OVER!";
	const char UI_GAME_COMPLETE_MESSAGE[20] = "LEVEL COMPLETE";
	const char UI_LEVEL_MESSAGE[LEVELS_LENGHT][10] = { "LEVEL 1" };
	const char UI_ATTEMPTS_MESSAGE[15] = "ATTEMPTS: %i";

	const int UI_TIME_POSITION_Y = 75;
	const int UI_ATTEMPTS_POSITION_X = 65;
	const int UI_ATTEMPTS_POSITION_Y = SCREEN_HEIGHT - 60;
	const int UI_TITLES_POSITION_Y = 250;
	const int UI_MESSAGES_POSITION_Y = SCREEN_HEIGHT - 150;
	const int UI_TITLES_LENGHT = 4;

	const int UI_TITLES_DURATION = 2 * FIXED_FRAMERATE;

	const ALLEGRO_COLOR UI_TITLES_COLOR = al_map_rgb(255, 255, 255);
	const ALLEGRO_COLOR UI_MESSAGES_COLOR = al_map_rgb(255, 255, 255);

	// HIGHSCORE
	const int HS_NAME_LENGHT = 7;
	const int HS_LENGHT = 10;
	const char HS_FILENAME[30] = "assets/highscores.txt";
	const char HS_DEFAULT_NAME[HS_NAME_LENGHT] = "XXXXXX";
	const char HS_BG_SPRITE[40] = "assets/levels/hs_background.png";
	const char HS_ENTERNAME_SPRITE[40] = "assets/levels/hs_entername.png";
	const ALLEGRO_COLOR HS_FONT_COLOR = al_map_rgb(255, 255, 255);
	const int HS_BG_POSITION_X = SCREEN_WIDTH / 2;
	const int HS_BG_POSITION_Y = 350;
	const int HS_OFFSET_X = -85;
	const int HS_OFFSET_Y = -90;
	const int HS_SCORESPACE = 165;
	const int HS_LINESPACE = 32;
	const int HS_ENTERNAME_POSITION_X = SCREEN_WIDTH / 2;
	const int HS_ENTERNAME_POSITION_Y = SCREEN_HEIGHT / 2 - 150;
	const int HS_ENTERNAME_OFFSET_X = 40;
	const int HS_ENTERNAME_OFFSET_Y = 30;

	// AUDIO
	enum Musics {MAIN = 0};
	const char AUDIO_MUSIC[40] = { "assets/audio/music.ogg" };

}