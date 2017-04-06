#pragma once
#include "GameUtils.h"

class Transform
{

private:
	Vector2 position;
	float scale;
	float rotation;

public:
	Transform(); 
	Transform(Vector2 p);
	~Transform();
	// Returns position (Vector2)
	Vector2 GetPosition() const;
	float GetScale() const;
	float GetRotation() const;
	void SetPosition(Vector2 v);
	void SetScale(float v);
	void SetRotation(float v);
	// Adds a displacement to the transforms position
	void Translate(Vector2 v);
	// Adds a scale to the transforms scale
	void ScaleUp(float v);
	// Adds a rotation to the transforms rotation
	void Rotate(float v);
};

