#include "Block.h"

Block::Block()
{
}


Block::Block(Vector2 position, Vector2 lenght,  float friction)
{
	body = Body(position, { 0, 0 }, lenght);
	this->friction = friction;
}

Block::~Block()
{
}

Vector2 Block::GetPosition() const
{
	return body.GetPosition();
}

float Block::GetFriction() const
{
	return friction;
}

void Block::Update()
{
	body.UpdateOnScreen();
}

void Block::DrawUpdate(Sprite sprite)
{
	body.Draw(sprite)
}

