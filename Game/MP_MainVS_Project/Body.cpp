#include "Body.h"

Body::Body()
{
}

Body::Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght)
{
	this->transform = transform;
	collider = AABB(transform.position, colliderOffset, colliderLenght);
}

Body::~Body()
{
}

Vector2 Body::GetPosition() const
{
	return transform.position;
}

void Body::SetRotation(float degrees)
{
	transform.rotation = degrees;
}

float Body::GetRotation() const
{
	return transform.rotation;
}

void Body::SetScale(float scale)
{
	transform.scale = scale;
}

float Body::GetScale() const
{
	return transform.scale;
}

void Body::SetCollider(Vector2 offset, Vector2 lenght)
{
	collider = AABB(transform.position, offset, lenght);
}

void Body::SetPosition(Vector2 position)
{
	transform.position = position;
	collider.UpdatePosition(transform.position);
}

void Body::UpdatePosition(Vector2 displacement)
{
	transform.position.x += displacement.x;
	transform.position.y += displacement.y;
	collider.UpdatePosition(transform.position);
}

