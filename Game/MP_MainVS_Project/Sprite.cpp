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

Sprite::Sprite(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);
	this->offset = offset;
}

Sprite::Sprite(ALLEGRO_BITMAP * texture)
{
	this->texture = texture;
	offset = { 0, 0 };
}

Sprite::Sprite(Vector2 offset, ALLEGRO_BITMAP * texture)
{
	this->texture = texture;
	this->offset = offset;
}

Sprite::Sprite(char * path)
{
	texture = al_load_bitmap(path);
	offset = { 0, 0 };
}

Sprite::Sprite(Vector2 offset, char * path)
{
	texture = al_load_bitmap(path);
	this->offset = offset;
}

Vector2 Sprite::GetLenght()
{
	return{ (float)al_get_bitmap_width(texture), (float)al_get_bitmap_height(texture) };
}

Sprite::~Sprite()
{
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
