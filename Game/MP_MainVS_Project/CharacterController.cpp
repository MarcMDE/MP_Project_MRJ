#include "CharacterController.h"

CharacterController::CharacterController()
{
}

CharacterController::CharacterController(Vector2 position, Vector2 topSpeed, Vector2 speedIncrement, Vector2 colliderOffset, Vector2 colliderLenght)
{
	Body(position, colliderOffset, colliderLenght);
	friction = { 0, 0 };
	speed = { 0, 0 };
	this->topSpeed = topSpeed;
	this->speedIncrement = speedIncrement;
	direction = { 0, 0 };
	auxVelocity = { 0, 0 };
	finalVelocity = { 0, 0 };
	updateVelocity = true;
	isJumping = false;
	isGrounded = false;
}

void CharacterController::Update()
{
}

void CharacterController::Move()
{
	isGrounded = false;
	updateVelocity = false;

	// Input needed
	char key;

	switch (key)
	{
		case 'a':
		case 'A':
			if (direction.x != -1)
			{
				direction.x = -1;
				speed.x = 0;
			}
			else
			{
				updateVelocity = true;
			}
		break;

		case 'd':
		case 'D':
			if (direction.x != 1)
			{
				direction.x = 1;
				speed.x = 0;
			}
			else
			{
				updateVelocity = true;
			}

		default: updateVelocity = false;
	}

	if (speed.x > topSpeed.x) speed.x = topSpeed.x;

	auxVelocity += speed;
	auxVelocity -= friction;

	if (auxVelocity.x < 0) auxVelocity.x = 0;

	finalVelocity = auxVelocity * direction;
}

void CharacterController::Jump()
{

}



CharacterController::~CharacterController()
{
}
