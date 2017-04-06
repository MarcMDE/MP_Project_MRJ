#pragma once
#include "CharacterController.h"
#include "GameUtils.h"

class Player
{
private:
	Sprite sprite;
	CharacterController controller;

public:
	Player();
	Player(Vector2 sourcePosition, Vector2 topSpeed, Vector2 speedIncrement, ALLEGRO_BITMAP * texture );
	~Player();
	void Update();
	void Draw();
	Vector2 GetPos() const;
};

