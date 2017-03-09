#pragma once
#include "GameUtils.h"
#include "Body.h"
class DynamicObject
{
private:
	Body body;
	Vector2 velocity;
	Vector2 friction;
	Vector2 force;
	Vector2 maxSpeed;
	
public:
	DynamicObject();
	~DynamicObject();
	void AddForce(Vector2 force);
};

