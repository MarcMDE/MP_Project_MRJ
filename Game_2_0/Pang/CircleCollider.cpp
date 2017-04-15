#include "CircleCollider.h"



CircleCollider::CircleCollider()
{
}


CircleCollider::~CircleCollider()
{
}

void CircleCollider::New(Vector2 position, float radius)
{
	this->radius = radius;
	offset = { 0, 0 };
	UpdatePosition(position);
}

void CircleCollider::New(Vector2 position, Vector2 offset, float radius)
{
	this->offset = offset;
	this->radius = radius;
	UpdatePosition(position);
}

Vector2 CircleCollider::GetPosition()
{
	return position;
}

float CircleCollider::GetRadius()
{
	return radius;
}

void CircleCollider::EnlargeRadius(float d)
{
	radius += d;
}

void CircleCollider::SetRadius(float radius)
{
	this->radius = radius;
}

void CircleCollider::UpdatePosition(Vector2 position)
{
	this->position = position + offset;
}

bool CircleCollider::CheckCirclesCollision(CircleCollider b)
{
	// We can compare distances without sqrt
	return powf(fabs(b.GetPosition().x - position.x), 2) + powf(fabs(b.GetPosition().y - position.y), 2) <= powf(radius + b.GetRadius(), 2);
}

/*
bool CircleCollider::CheckCircleAABBCollision(AABB b)
{
	return b.CheckAABBCircleCollision(*this);
}
*/

void CircleCollider::DebugDraw()
{
	al_draw_circle(position.x, position.y, radius, { 255, 0, 0, 255 }, 1.0f);
}

