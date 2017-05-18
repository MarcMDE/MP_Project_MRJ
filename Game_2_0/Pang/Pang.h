#pragma once

#define DEBUG

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "GameConfig.h"
#include "Player.h"
#include "Background.h"
#include "BubbleManager.h"
#include "LevelsManager.h"

#include "PowerUp.h"
#include "ParticlesEmitter.h" // temp
//#include "Level.h" // temp
//#include "Bubble.h" // temp
//#include "MultiAnimation2D.h" // temp

using namespace GameConfig;

class Pang
{
private:
	Player player;
	LevelsManager levelManager;
	ParticlesEmitter pEmitter; // Temp
	PowerUp pU; // Temp

	bool isPaused;
	Sprite pauseSprite;

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
};

