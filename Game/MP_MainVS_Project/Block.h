#pragma once
#include "Body.h"
#include "Sprite.h"

typedef enum BlockTypes {ICE_BLOCK, STONE_BLOCK};

class Block
{
private:
	Body body;
	Sprite sprite;
	BlockTypes type;
	bool active;

public:
	Block();
	Block(Vector2 position, Vector2 lenght, BlockTypes type, ALLEGRO_BITMAP *texture);
	~Block();
	//AABB GetAABB();
	Vector2 GetPosition();
};

