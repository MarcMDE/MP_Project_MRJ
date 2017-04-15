#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "GameUtils2D.h"

using namespace GameUtils2D;

class Sprite
{
private:

	ALLEGRO_BITMAP *image;
	Vector2 offset;

	void CreateFlatTexture(Vector2 lenght, ALLEGRO_COLOR color);

public:

	Sprite();
	// Creates flat texture
	Sprite(Vector2 lenght, ALLEGRO_COLOR color);
	// Creates flat texture with offset
	Sprite(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color);
	// Sets texture
	Sprite(ALLEGRO_BITMAP *image);
	// Sets texture with offset
	Sprite(ALLEGRO_BITMAP *image, Vector2 offset);
	~Sprite();

	// Creates flat texture
	void New(Vector2 lenght, ALLEGRO_COLOR color);
	// Creates flat texture with offset
	void New(Vector2 lenght, Vector2 offset, ALLEGRO_COLOR color);
	// Sets texture
	void New(ALLEGRO_BITMAP *image);
	// Sets texture with offset
	void New(ALLEGRO_BITMAP *image, Vector2 offset);

	int GetWidth();
	int GetHeight();
	void SetOffset(Vector2 offset);
	void Draw(Vector2 position);
	void Draw(Vector2 position, bool hFlip);
	void Draw(Vector2 position, float rotation, float scale, bool hFlip);
	void DrawRegion(Vector2 position, Vector2 source, Vector2 length, bool hFlip);
	//void Draw(Vector2 position, bool hFlip, bool vFlip);
	//void Draw(Vector2 position, float rotation);
	//void Draw(Vector2 position, float scale);
	//void Draw(Vector2 position, float rotation, float scale);
	//void Draw(Vector2 position, float rotation, float scale, bool hFlip, bool vFlip);
};

