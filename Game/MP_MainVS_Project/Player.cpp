#include "Player.h"
#include <stdio.h>

Player::Player()
{

}

Player::Player(Vector2 sourcePosition, Vector2 topSpeed, Vector2 speedIncrement, ALLEGRO_BITMAP * texture)
{
	sprite = Sprite({ -(float)al_get_bitmap_width(texture) / 2, -(float)al_get_bitmap_height(texture) }, texture);
	controller = CharacterController(sourcePosition, topSpeed, speedIncrement, {0, -sprite.GetLenght().y/2}, sprite.GetLenght());
}

Player::~Player()
{
}

void Player::Update(char key, bool isKeyDown)
{
	controller.Update(key, isKeyDown);
}

void Player::Draw()
{
	controller.Draw(sprite);
}

Vector2 Player::GetPos() const
{
	return controller.GetPos();
}
