#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "GameConfig.h"
#include "Player.h"
#include "Background.h"
#include "Bubble.h" // temp
#include "MultiAnimation2D.h" // temp

using namespace GameConfig;

class Pang
{
private:
	Player player;
	Background background;


	Bubble b; // temp
	ALLEGRO_BITMAP *bI; // temp

	bool isPaused;
	Sprite pauseSprite;

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
};

