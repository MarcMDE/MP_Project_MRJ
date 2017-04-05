#pragma once
#include "GameUtils.h"

class CharacterController
{
private:
	Vector2 friction;
	Vector2 speed;
	Vector2 topSpeed;
	Vector2 speedIncrement;
	Vector2 direction;
	bool isJumping;
	bool isGrounded;
	Vector2 velocity;

public:
	CharacterController();
	~CharacterController();
};

