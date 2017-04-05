#include "Body.h"

Body::Body()
{
}

Body::Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght)
{
	SetPosition(transform.GetPosition());
	SetRotation(transform.GetRotation());
	SetScale(transform.GetScale());

	collider = AABB(transform.GetPosition(), colliderOffset, colliderLenght);
}

Body::Body(Vector2 position, Vector2 colliderOffset, Vector2 colliderLenght)
{
	Transform(position);
	collider = AABB(position, colliderOffset, colliderLenght);
}

Body::Body(Vector2 position, float scale, Vector2 colliderOffset, Vector2 colliderLenght)
{
	Transform(position);
	SetScale(scale);
	collider = AABB(position, colliderOffset, colliderLenght);
}

Body::~Body()
{
}

void Body::SetCollider(Vector2 offset, Vector2 lenght)
{
	collider = AABB(GetPosition(), offset, lenght);
}

void Body::UpdatePosition(Vector2 displacement)
{
	Translate(displacement);
	collider.UpdatePosition(GetPosition());
}

void Body::SetInstantPosition(Vector2 position)
{
	SetPosition(position);
	collider.UpdatePosition(position);
}

void Body::Draw(Sprite sprite)
{
	if (OnScreen)
	{
		sprite.Draw(GetPosition());
	}
}

