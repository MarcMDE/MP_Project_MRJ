#include "CharacterController.h"



CharacterController::CharacterController()
{
}

CharacterController::CharacterController(Transform transform, Vector2 speed, Vector2 friction, Vector2 colliderOffset, Vector2 colliderLenght)
{
	dynamic = DynamicObject(transform, colliderOffset, colliderLenght, friction);
	this->speed = speed;
}


CharacterController::~CharacterController()
{
}

void CharacterController::Move()
{
	dynamic.AddForce(speed, { 1, 0 });
	dynamic.Update();
}

Vector2 CharacterController::GetPosition()
{
	return dynamic.GetPosition();
}
