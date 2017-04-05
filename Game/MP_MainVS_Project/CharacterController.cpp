#include "CharacterController.h"



void CharacterController::UpdateVelocity()
{
	velocity = velocity + speed * direction;
	//if (direction.x > 0 && )

}

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
	velocity = { 0, 0 };
	isJumping = false;
	isGrounded = false;
}



CharacterController::~CharacterController()
{
}
