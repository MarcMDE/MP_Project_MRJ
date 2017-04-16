#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "GameConfig.h"
#include "Player.h"
#include "Background.h"

using namespace GameConfig;

class Pang
{
private:
	Player player;
	Background background;

	bool isPaused;
	Sprite pauseSprite;

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
};

