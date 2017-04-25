#pragma once

#include "Sprite.h"
#include "GameUtils2D.h"
#include "GameConfig.h"
#include "GameObject.h"
#include "AABB.h"
#include "Bubble.h"

using namespace GameUtils2D;
using namespace GameConfig;

class Arrow : public GameObject
{
private:
	float lenghtY;
	int counter;
	Sprite sprite;
	AABB collider;

	void Reset();

public:
	Arrow();
	~Arrow();

	void New(ALLEGRO_BITMAP *image);
	void Update();
	void CheckBubblesCollision(Bubble * b, int lenght);
	void Draw();
	void Shot(Vector2 position);

};

