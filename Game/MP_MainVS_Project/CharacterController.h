#pragma once
#include "DynamicObject.h"

class CharacterController
{
private:
	DynamicObject dynamic;
	Vector2 speed;

public:
	CharacterController();
	CharacterController(Transform transform, Vector2 speed, Vector2 friction, Vector2 colliderOffset, Vector2 colliderLenght);
	~CharacterController();
	//void Jump(); // Jump Logic Class??
	//void Move(char inputKey);
	void Move();
	//void Update();
	Vector2 GetPosition();
};

