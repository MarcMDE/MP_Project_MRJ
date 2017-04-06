#pragma once
#include "GameUtils.h"
#include <math.h>

class AABB
{
private: 
	Vector2 position;
	Vector2 offset;
	Vector2 lenght;
	bool isActive;

public:
	AABB();
	AABB(Vector2 position, Vector2 offset, Vector2 lenght);
	~AABB();
	Vector2 GetPosition() const;
	Vector2 GetLenght() const;
	bool AABBCollide(AABB b);
	void UpdatePosition(Vector2 position);
	void SetActive(bool active);
	bool IsActive();

};

 