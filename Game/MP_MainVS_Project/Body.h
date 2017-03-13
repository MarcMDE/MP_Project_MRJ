#pragma once
#include "GameUtils.h"
#include "AABB.h"

class Body
{
public:
	Body();
	Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght);
	~Body();
	Vector2 GetPosition() const;
	void SetRotation(float degrees);
	float GetRotation() const;
	void SetScale(float scale);
	float GetScale() const;
	void SetCollider(Vector2 offset, Vector2 lenght);
	void SetPosition(Vector2 position);
	void UpdatePosition(Vector2 displacement);

private:
	Transform transform;
	AABB collider;
};



