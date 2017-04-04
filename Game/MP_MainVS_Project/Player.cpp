#include "Player.h"
#include <stdio.h>


Player::Player()
{
}

Player::Player(Transform transform, Vector2 friction)
{
	controller = CharacterController(transform, speed, friction, colliderOffset, playerLenght);
	sprite = Sprite(playerLenght, { 255, 0, 0 });
}

void Player::Initialize(Transform transform, Vector2 friction)
{
	controller = CharacterController(transform, speed, friction, colliderOffset, playerLenght);
	sprite = Sprite(playerLenght, al_map_rgb(255, 0, 0));
}


Player::~Player()
{
}

void Player::Update()
{
	controller.Move();
	printf("PlayerPosition: %f\n", controller.GetPosition().x);
}

void Player::Draw()
{
	sprite.Draw(controller.GetPosition());
}
