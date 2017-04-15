#pragma once

#include "GameObject.h"
#include "AABB.h"
//#include "Sprite.h" // Temp
#include "MultiAnimation2D.h"
#include "GameConfig.h"
#include "GameUtils2D.h"
#include "InputsManager.h"

enum PlayerAnimations { RUNNING = 0, JUMPING, IDLE };
enum PlayerOrientation { RIGHT = 0, LEFT};

using namespace GameConfig;
using namespace GameUtils2D;

class Player : public GameObject
{
private:
	Vector2 velocity;
	Vector2 speed;
	Vector2 topSpeed;
	Vector2 direction;
	bool isGrounded;
	bool isJumping;
	float fallingMovementFactor;
	float jumpingMovementFactor;
	AABB collider;
	MultiAnimation2D animator;
	PlayerOrientation orientation;
	PlayerAnimations currentAnimation;

	void DefineCurrentAnimation(PlayerAnimations animation);
	void SetCurrentAnimation();

public:
	Player();
	~Player();

	void New();
	void Update();
	void Draw();
};

