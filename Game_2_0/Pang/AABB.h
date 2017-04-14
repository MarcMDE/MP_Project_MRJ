#pragma once

#include "GameUtils2D.h"
#include <math.h>
#include "CircleCollider.h"

using namespace GameUtils2D;

class AABB
{
private:
	Vector2 position;
	Vector2 offset;
	Vector2 lenght;

public:
	AABB();
	~AABB();

	void New(Vector2 position, Vector2 lenght);
	void New(Vector2 position, Vector2 offset, Vector2 lenght);

	Vector2 GetPosition();
	Vector2 GetLenght();
	void EnlargeLenght(Vector2 d);
	void SetLenght(Vector2 lenght);
	void UpdatePosition(Vector2 position);
	bool CheckAABBsCollision(AABB b);
	bool CheckAABBCircleCollision(CircleCollider c);
};

