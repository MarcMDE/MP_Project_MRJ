#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "Animation2D.h"
#include "GameConfig.h"

using namespace GameConfig;

class Pang
{
private:
	Animation2D test;

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
};

