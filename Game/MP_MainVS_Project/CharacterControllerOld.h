#pragma once
#include "DynamicObject.h"

class CharacterControllerOld
{
private:
	DynamicObject dynamic;
	Vector2 speed;

public:
	CharacterControllerOld();
	CharacterControllerOld(Transform transform, Vector2 speed, Vector2 friction, Vector2 colliderOffset, Vector2 colliderLenght);
	~CharacterControllerOld();
	//void Jump(); // Jump Logic Class??
	//void Move(char inputKey);
	void Move();
	//void Update();
	Vector2 GetPosition();
};

