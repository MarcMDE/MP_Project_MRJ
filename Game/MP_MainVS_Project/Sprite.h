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
	~Sprite();
	void LoadTexture(char *path);
	void SetTexture(ALLEGRO_BITMAP *texture);
	void Draw(Vector2 position);
};

