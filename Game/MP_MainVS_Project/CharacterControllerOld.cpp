#include "CharacterControllerOld.h"



CharacterControllerOld::CharacterControllerOld()
{
}

CharacterControllerOld::CharacterControllerOld(Transform transform, Vector2 speed, Vector2 friction, Vector2 colliderOffset, Vector2 colliderLenght)
{
	dynamic = DynamicObject(transform, colliderOffset, colliderLenght, friction);
	this->speed = speed;
}


CharacterControllerOld::~CharacterControllerOld()
{
}

void CharacterControllerOld::Move()
{
	dynamic.AddForce(speed, { 1, 0 });
	dynamic.Update();
}

Vector2 CharacterControllerOld::GetPosition()
{
	return dynamic.GetPosition();
}
