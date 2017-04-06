#pragma once
#include "GameUtils.h"
#include "Body.h"

class CharacterController
{
private:
	
	Body body;
	Vector2 friction;
	Vector2 speed;
	Vector2 topSpeed;
	Vector2 speedIncrement;
	Vector2 direction;
	Vector2 auxVelocity;
	Vector2 finalVelocity;
	bool updateSpeed;
	bool isJumping;
	bool isGrounded;

	void Move();
	void Jump();

public:
	CharacterController();
	CharacterController(Vector2 position, Vector2 topSpeed, Vector2 speedIncrement, Vector2 colliderOffset, Vector2 colliderLenght);
 	~CharacterController();
	void Update();
	void Draw(Sprite sprite);
	Vector2 GetPos() const;
};

