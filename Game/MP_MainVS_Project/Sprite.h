#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "GameUtils.h"

class Sprite
{
private:
	ALLEGRO_BITMAP *texture = NULL;
	Vector2 offset;
	void CreateFlatTexture(Vector2 lenght, ALLEGRO_COLOR color);

public:
	Sprite();
	Sprite(Vector2 lenght, ALLEGRO_COLOR color);
	Sprite(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color);
	Sprite(ALLEGRO_BITMAP *texture);
	Sprite(Vector2 offset, ALLEGRO_BITMAP * texture);
	Sprite(char * path);
	Sprite(Vector2 offset, char * path);
	~Sprite();
	void Draw(Vector2 position);
};

