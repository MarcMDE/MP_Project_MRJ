#include "Player.h"



Player::Player()
{
}

Player::Player(Vector2 sourcePosition, Vector2 topSpeed, Vector2 speedIncrement, ALLEGRO_BITMAP * texture)
{
	sprite = Sprite({ -al_get_bitmap_width(texture) / 2, -al_get_bitmap_height(texture) }, texture);
	CharacterController(sourcePosition, topSpeed, speedIncrement, {0, -sprite.GetLenght().y/2}, sprite.GetLenght());
}

Player::~Player()
{
}

void Player::Update()
{
	Update();
}

void Player::Draw()
{
	CharacterController::Draw(sprite);
}
