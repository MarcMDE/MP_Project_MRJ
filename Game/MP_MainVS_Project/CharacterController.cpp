#include "CharacterController.h"



CharacterController::CharacterController()
{
}

CharacterController::CharacterController(Transform transform,Vector2 maxSpeed, Vector2 acceleration, Vector2 friction, Vector2 colliderOffset, Vector2 colliderLenght)
{
	dynamic = DynamicObject(transform, maxSpeed, colliderOffset, colliderLenght, friction);
	this->acceleration = acceleration;
	std::cout << acceleration.x;
}


CharacterController::~CharacterController()
{
}

void CharacterController::Move()
{
	dynamic.AddForce(acceleration, { 1, 0 });
	dynamic.Update();
}

Vector2 CharacterController::GetPosition()
{
	return dynamic.GetPosition();
}
