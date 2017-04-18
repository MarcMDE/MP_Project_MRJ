#pragma once

#include "GameUtils2D.h"
#include "GameObject.h"
#include "CircleCollider.h"
#include "GameConfig.h"
#include "MultiAnimation2D.h"

using namespace GameUtils2D;
using namespace GameConfig;

enum BubbleAnimations {BUBBLEANIM_IDLE = 0, BUBBLEANIM_GROUND_COLLISION};

class Bubble : public GameObject
{
private: 
	CircleCollider collider;
	int category;
	MultiAnimation2D animator;
	Vector2 velocity;
	int directionX;
	BubbleAnimations currentAnimation;

	void Move();
	void DefineCurrentAnimation(BubbleAnimations animation);

public:
	Bubble();
	~Bubble();

	void New(Vector2 position, int category, int directionX, ALLEGRO_BITMAP * spriteSheet);
	void Activate();
	void Deactivate();

	void Update();
	void Draw();
};

