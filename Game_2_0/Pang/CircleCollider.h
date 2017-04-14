#pragma once

#include "GameUtils2D.h"
#include <math.h>
#include "AABB.h"

#include "allegro5/allegro_primitives.h" // Debug

using namespace GameUtils2D;

class CircleCollider
{
private:
	Vector2 position;
	Vector2 offset;
	float radius;

public:
	CircleCollider();
	~CircleCollider();

	void New(Vector2 position, float radius);
	void New(Vector2 position, Vector2 offset, float radius);

	Vector2 GetPosition();
	float GetRadius();
	void EnlargeRadius(float d);
	void SetRadius(float radius);
	void UpdatePosition(Vector2 position);
	bool CheckCirclesCollision(CircleCollider b);
	bool CheckCircleAABBCollision(AABB b);

	void DebugDraw();
};

