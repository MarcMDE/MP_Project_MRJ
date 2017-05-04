#pragma once

#include "GameObject.h"
#include "AABB.h"
#include "MultiAnimation2D.h"
#include "GameConfig.h"
#include "GameUtils2D.h"
#include "InputsManager.h"
#include "Bubble.h"
#include "Arrow.h"


using namespace GameConfig;
using namespace GameUtils2D;

class Player : public GameObject
{
private:
	int index;
	enum PlayerAnimations { RUNNING = 0, JUMPING, IDLE };
	Vector2 velocity;
	Vector2 direction;
	bool isGrounded;
	bool isJumping;
	bool isAlive;
	AABB collider;
	MultiAnimation2D animator;
	Orientation orientation;
	PlayerAnimations currentAnimation;
	Arrow arrow;

	void DefineCurrentAnimation(PlayerAnimations animation);
	void SetCurrentAnimation();

public:
	Player();
	Player(int index);
	~Player();
	
	void New(int index);
	void Update();
	void Draw();
	void CheckBubblesCollision(Bubble *b, int lenght);
	bool IsAlive();
	void SetAsAlive();
};

