#pragma once
#include "Body.h"

class Block
{
private:
	Body body;
	float friction;

public:
	Block();
	Block(Vector2 position, Vector2 lenght,  float friction);
	~Block();
	Vector2 GetPosition() const;
	float GetFriction() const;
	void Update();
	void DrawUpdate(Sprite sprite);
};

