#pragma once
#include "CharacterController.h"
#include "Sprite.h"

class Player
{
private:
	const Vector2 playerLenght = { 64, 128 };
	const Vector2 acceleration = { 1, 1 };
	const Vector2 maxSpeed = { 4.0f, 4.0f };
	const Vector2 colliderOffset = {playerLenght.x / 2, playerLenght.y / 2};
	CharacterController controller;
	// Animation anim
	Sprite sprite;

public:
	Player();
	Player(Transform transform, Vector2 friction);
	void Initialize(Transform transform, Vector2 friction);
	~Player();
	void Update();
	void Draw();
};

