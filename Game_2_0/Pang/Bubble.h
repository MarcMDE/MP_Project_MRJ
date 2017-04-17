#pragma once

#include "GameUtils2D.h"
#include "GameObject.h"
#include "CircleCollider.h"
#include "GameConfig.h"
#include "MultiAnimation2D.h"

using namespace GameUtils2D;
using namespace GameConfig;

enum Orientation { RIGHT = 0, LEFT };
enum BubbleAnimations {IDLE = 0, GROUND_COLLISION};

class Bubble : public GameObject
{
private: 
	CircleCollider collider;
	int category;
	MultiAnimation2D animator;
	Vector2 velocity;
	int directionX;
	Orientation orientation;
	BubbleAnimations currentAnimation;

	void Move();
	void DefineCurrentAnimation(BubbleAnimations animation);

public:
	Bubble();
	~Bubble();

	void New(Vector2 position, int category, MultiAnimation2D animator, int directionX);
	void Activate();
	void Deactivate();

	void Update();
	void Draw();
};

