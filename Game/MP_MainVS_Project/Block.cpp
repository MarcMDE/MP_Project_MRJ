#include "Block.h"



Block::Block(Vector2 position, Vector2 lenght, BlockTypes type, ALLEGRO_BITMAP *texture)
{
	body = Body({ position, 0, 0 }, { 0, 0 }, lenght);
	sprite = Sprite(lenght, al_map_rgb(0, 255, 0));
	sprite.SetTexture(texture);
	this->type = type;
	active = true;
}

Block::~Block()
{
}

Vector2 Block::GetPosition()
{
	return body.GetPosition();
}


