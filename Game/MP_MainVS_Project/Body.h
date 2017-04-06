#ifndef BODY_H
#define BODY_H

#include "GameUtils.h"
#include "AABB.h"
#include "Sprite.h"
#include "Transform.h"

class Body 
{
private:
	AABB collider;
	Transform transform;

public:
	Body();
	Body(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght);
	Body(Vector2 pos, Vector2 colliderOffset, Vector2 colliderLenght);
	Body(Vector2 pos, float scale, Vector2 colliderOffset, Vector2 colliderLenght);
	~Body();
	void SetCollider(Vector2 offset, Vector2 lenght);
	void UpdatePosition(Vector2 displacement);
	void SetInstantPosition(Vector2 position);
	void Draw(Sprite sprite);
	Transform GetTransform() const;
	Vector2 GetPos() const;
};

#endif