#pragma once
#include "GameUtils.h"
#include "AABB.h"

class Body
{
public:
	Body();
	~Body();
	void SetPosition(Vector2 position);
	Vector2 GetPosition() const;
	void SetRotation(float degrees);
	Vector2 GetRotation() const;
	void SetScale(float scale);
	Vector2 GetScale() const;
	void SetCollider(Vector2 offset, Vector2 lenght);
	void Update();
private:
	Transform transform;
	AABB collider;
};



