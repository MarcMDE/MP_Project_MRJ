#pragma once
#include "GameUtils.h"
#include "Body.h"


class DynamicObject
{
private:
	Body body;
	Vector2 velocity;
	Vector2 direction;
	Vector2 friction;
	Vector2 speed;
	Vector2 maxSpeed;
	bool grounded;
	bool active;

	void UpdateVelocity();

public:
	DynamicObject();
	DynamicObject(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght, Vector2 friction);
	~DynamicObject();
	void SetDirection(Vector2 direction);
	void AddForce(Vector2 force, Vector2 direction);
	void Update();
	void SetAsGrounded();
	void SetAsActive(bool active);
	Vector2 GetPosition();
};

