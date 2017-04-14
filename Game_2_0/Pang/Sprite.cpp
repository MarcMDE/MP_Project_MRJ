#include "Sprite.h"
#include <stdio.h>

void Sprite::CreateFlatTexture(Vector2 lenght, ALLEGRO_COLOR color)
{
	image = al_create_bitmap(lenght.x, lenght.y);
	al_set_target_bitmap(image);
	al_clear_to_color(color);
}

Sprite::Sprite()
{
	image = NULL;
	offset = { 0, 0 };
}

Sprite::Sprite(Vector2 lenght, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);

	// Sprites are drawed from the center by default
	offset.x = -lenght.x / 2;
	offset.y = -lenght.y / 2;
}

Sprite::Sprite(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);
	this->offset = offset;
}

Sprite::Sprite(ALLEGRO_BITMAP * image)
{
	this->image = image;
	// Sprites are drawed from the center by default
	offset.x = -al_get_bitmap_width(image) / 2;
	offset.y = -al_get_bitmap_height(image) / 2; 
}

Sprite::Sprite(ALLEGRO_BITMAP *image, Vector2 offset)
{
	this->image = image;
	this->offset = offset;
}

Sprite::~Sprite()
{
	al_destroy_bitmap(image);
}

void Sprite::New(Vector2 lenght, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);

	// Sprites are drawed from the center by default
	offset.x = -lenght.x / 2;
	offset.y = -lenght.y / 2;
}

void Sprite::New(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color)
{
	CreateFlatTexture(lenght, color);
	this->offset = offset;
}

void Sprite::New(ALLEGRO_BITMAP * image)
{
	this->image = image;
	// Sprites are drawed from the center by default
	offset.x = -al_get_bitmap_width(image) / 2;
	offset.y = -al_get_bitmap_height(image) / 2;
}

void Sprite::New(ALLEGRO_BITMAP * image, Vector2 offset)
{
	this->image = image;
	this->offset = offset;
}

int Sprite::GetWidth()
{
	return al_get_bitmap_width(image);
}

int Sprite::GetHeight()
{
	return al_get_bitmap_height(image);
}

void Sprite::Draw(Vector2 position)
{
	al_draw_bitmap(image, position.x + offset.x, position.y + offset.y, 0);
}

void Sprite::Draw(Vector2 position, bool hFlip)
{
	al_draw_bitmap(image, position.x + offset.x, position.y + offset.y, (int)hFlip);
}

void Sprite::Draw(Vector2 position, float rotation, float scale, bool hFlip)
{
	al_draw_scaled_rotated_bitmap(image, position.x + offset.x - al_get_bitmap_width(image) / 2, position.y + offset.y - al_get_bitmap_height(image) / 2,
		position.x + offset.x, position.y + offset.y, scale, scale, rotation, (int)hFlip);
}

void Sprite::DrawRegion(Vector2 position, Vector2 source, Vector2 length, bool hFlip)
{
	al_draw_bitmap_region(image, source.x, source.y, length.x, length.y, position.x + offset.x, position.y + offset.y, (int)hFlip);
}

