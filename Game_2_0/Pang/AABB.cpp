#include "AABB.h"



AABB::AABB()
{
	position = { 0, 0 };
	offset = { 0, 0 };
	lenght = { 0, 0 };
}


AABB::~AABB()
{
}

void AABB::New(Vector2 position, Vector2 lenght)
{
	this->lenght = lenght;
	offset = { 0, 0 };
	UpdatePosition(position);
}

void AABB::New(Vector2 position, Vector2 offset, Vector2 lenght)
{
	this->offset = offset;
	this->lenght = lenght;
	UpdatePosition(position);
}

Vector2 AABB::GetPosition()
{
	return position;
}

Vector2 AABB::GetLenght()
{
	return lenght;
}

void AABB::EnlargeLenght(Vector2 d)
{
	lenght += d;
}

void AABB::SetLenght(Vector2 lenght)
{
	this->lenght = lenght;
}

void AABB::UpdatePosition(Vector2 position)
{
	this->position = position + offset;
}

bool AABB::CheckAABBsCollision(AABB b)
{
	return (fabs(b.GetPosition().x - position.x) <= (lenght.x/2 + b.GetLenght().x/2) && 
		fabs(b.GetPosition().y - position.y) <= (lenght.y/2 + b.GetLenght().y/2));
}

bool AABB::CheckAABBCircleCollision(CircleCollider c)
{
	bool collision = false;
	Vector2 d;

	d.x = fabs(c.GetPosition().x - position.x);
	d.y = fabs(c.GetPosition().y - position.y);

	
	if ((d.x > lenght.x/2 + c.GetRadius()) || (d.y > lenght.y/2 + c.GetRadius()))
	{
		// Discard collision by AABB - AABB collision
		collision = false;
	}
	else if (d.x <= lenght.x/2 && d.y <= lenght.y/2)
	{
		// Check simple collision to avoid harder calculations
		collision = true;
	}
	
	
	else if (powf(d.x - lenght.x / 2, 2) + powf(d.y - lenght.y / 2, 2) <= powf(c.GetRadius(), 2))
	{
		// Check corner collision
		collision = true;
	}
	
	return collision;
}

void AABB::DebugDraw()
{
	al_draw_rectangle(position.x - lenght.x / 2, position.y - lenght.y / 2, position.x + lenght.x / 2, position.y + lenght.y / 2, { 0, 0, 255, 255 }, 1.0f);
}
