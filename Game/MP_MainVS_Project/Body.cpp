#include "Body.h"
#include <stdio.h>

Body::Body()
{
}

Body::Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght)
{
	this->transform = transform;
	collider = AABB(transform.GetPosition(), colliderOffset, colliderLenght);
}

Body::Body(Vector2 position, Vector2 colliderOffset, Vector2 colliderLenght)
{
	transform = Transform(position);
	collider = AABB(position, colliderOffset, colliderLenght);
}

Body::Body(Vector2 position, float scale, Vector2 colliderOffset, Vector2 colliderLenght)
{
	transform = Transform(position);
	transform.SetScale(scale);
	collider = AABB(position, colliderOffset, colliderLenght);
}

Body::~Body()
{
}

void Body::SetCollider(Vector2 offset, Vector2 lenght)
{
	collider = AABB(transform.GetPosition(), offset, lenght);
}

void Body::UpdatePosition(Vector2 displacement)
{
	transform.Translate(displacement);
	collider.UpdatePosition(transform.GetPosition());
}

void Body::SetInstantPosition(Vector2 position)
{
	transform.SetPosition(position);
	collider.UpdatePosition(position);
}

void Body::Draw(Sprite sprite)
{
	sprite.Draw(transform.GetPosition());	
}

Transform Body::GetTransform() const
{
	return transform;
}

Vector2 Body::GetPos() const
{
	return transform.GetPosition();
}

