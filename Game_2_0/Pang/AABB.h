#ifndef AABB_H
#define AABB_H


#include "GameUtils2D.h"
#include <math.h>
#include "CircleCollider.h"

#include "allegro5/allegro_primitives.h" // Debug

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
	void SetOffset(Vector2 offset);
	void UpdatePosition(Vector2 position);
	bool CheckAABBsCollision(AABB b);
	bool CheckAABBCircleCollision(CircleCollider c);

	void DebugDraw();
};

#endif // !AABB_H