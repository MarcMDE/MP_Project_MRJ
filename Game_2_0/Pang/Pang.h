#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "GameConfig.h"

#include "Animation2D.h"
#include "AABB.h"
#include "CircleCollider.h"

using namespace GameConfig;

class Pang
{
private:
	Animation2D anim;
	AABB aBox;
	AABB bBox;
	CircleCollider aCirc;
	CircleCollider bCirc;
	

public:
	Pang();
	~Pang();

	void Initialize();
	void Update();
	void Draw();
};

