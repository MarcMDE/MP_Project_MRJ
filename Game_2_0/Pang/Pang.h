#pragma once

#define DEBUG

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "GameConfig.h"
#include "Player.h"
#include "Background.h"
#include "BubbleManager.h"
#include "LevelsManager.h"
#include "HighscoresManager.h"
#include "PowerUpsManager.h"
//#include "PowerUp.h" // temp
#include "ParticlesEmitter.h" // temp
#include "AudioManager.h"
//#include "Level.h" // temp
//#include "Bubble.h" // temp
//#include "MultiAnimation2D.h" // temp

using namespace GameConfig;

class Pang
{
private:
	Player player;
	LevelsManager levelManager;
	HighscoresManager m_highscores;
	ParticlesEmitter pEmitter; // Temp
	PowerUp pU; // Temp

	bool m_setNewHighscore;
	bool m_isPaused;
	Sprite pauseSprite;

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
	void Save();
};

