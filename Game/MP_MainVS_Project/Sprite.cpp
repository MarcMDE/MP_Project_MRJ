#include "Sprite.h"
#include <stdio.h>

Sprite::Sprite()
{
}

Sprite::Sprite(Vector2 lenght, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);
	offset.x = 0;
	offset.y = lenght.y / 2;
}

Sprite::~Sprite()
{
}

void Sprite::LoadTexture(char * path)
{
	texture = al_load_bitmap(path);
	offset = { 0, 0 };
}

void Sprite::CreateFlatTexture(Vector2 lenght, ALLEGRO_COLOR color)
{
	texture = al_create_bitmap(lenght.x, lenght.y);
	al_set_target_bitmap(texture);
	al_clear_to_color(color);
	//al_clear_to_color(al_map_rgb(255, 0, 0));
}

void Sprite::Draw(Vector2 position)
{
	al_draw_bitmap(texture, position.x + offset.x, position.y + offset.y, 0);
}
