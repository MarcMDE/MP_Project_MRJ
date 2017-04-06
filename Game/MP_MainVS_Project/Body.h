#pragma once
#include "GameUtils.h"
#include "AABB.h"
#include "Sprite.h"
#include "GameObject.h"

class Body : public GameObject
{
private:
	AABB collider;

public:
	Body();
	Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght);
	Body(Vector2 position, Vector2 colliderOffset, Vector2 colliderLenght);
	Body(Vector2 position, float scale, Vector2 colliderOffset, Vector2 colliderLenght);
	~Body();
	void SetCollider(Vector2 offset, Vector2 lenght);
	void UpdatePosition(Vector2 displacement);
	void SetInstantPosition(Vector2 position);
	void Draw(Sprite sprite);
};



