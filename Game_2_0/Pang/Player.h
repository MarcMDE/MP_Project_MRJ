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
	enum PlayerAnimations { RUNNING = 0, JUMPING, IDLE };
	Vector2 velocity;
	Vector2 speed;
	Vector2 topSpeed;
	Vector2 direction;
	bool isGrounded;
	bool isJumping;
	bool isAlive;
	float fallingMovementFactor;
	float jumpingMovementFactor;
	AABB collider;
	MultiAnimation2D animator;
	Orientation orientation;
	PlayerAnimations currentAnimation;
	Arrow arrow;

	void DefineCurrentAnimation(PlayerAnimations animation);
	void SetCurrentAnimation();

public:
	Player();
	~Player();
	
	void New();
	void Update();
	void Draw();
	void CheckBubblesCollision(Bubble *b, int lenght);
	bool IsAlive();
};

