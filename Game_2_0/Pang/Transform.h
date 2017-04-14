#pragma once
#include "GameUtils2D.h"

using namespace GameUtils2D;

class Transform
{
private:
	Vector2 position;
	float rotation;
	float scale;

public:
	Transform();
	Transform(Vector2 p, float r, float s);
	~Transform();

	void SetPosition(Vector2 p);
	void SetRotation(float r);
	void SetScale(float s);
	Vector2 GetPosition();
	float GetRotation();
	float GetScale();
	void Translate(Vector2 d);
	void Rotate(float d);
	void Scalate(float d);
};

