#include "AABB.h"

AABB::AABB()
{
}


AABB::~AABB()
{
}

Vector2 AABB::GetPosition() const
{
	return position;
}

Vector2 AABB::GetLenght() const
{
	return lenght;
}

bool AABB::AABBCollide(AABB b)
{
	return (fabsf(b.GetPosition().x - position.x) <= b.GetLenght().x / 2 + lenght.x / 2 && 
		fabsf(b.GetPosition().y - position.y) <= b.GetLenght().y / 2 + lenght.y / 2);
}

void AABB::UpdatePosition(Vector2 position)
{
	this->position.x = position.x + offset.x;
	this->position.y = position.y + offset.y;
}
