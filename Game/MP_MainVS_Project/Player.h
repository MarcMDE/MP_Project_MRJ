#pragma once
#include "CharacterController.h"
#include "GameUtils.h"

class Player : public CharacterController
{
private:
	Sprite sprite;

public:
	Player();
	Player(Vector2 sourcePosition, Vector2 topSpeed, Vector2 speedIncrement, ALLEGRO_BITMAP * texture );
	~Player();
	void Update();
	void Draw();
};

