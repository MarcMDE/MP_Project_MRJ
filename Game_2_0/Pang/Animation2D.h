#pragma once

#include "allegro5/allegro.h"
#include "Sprite.h"
#include "GameUtils2D.h"

using namespace GameUtils2D;

class Animation2D
{
private:
	int frames;
	int currentFrame;
	int duration;
	int counter;
	int columns;
	Vector2 lenght;
	Sprite spriteSheet;
	bool repeat;
	
public:
	Animation2D();
	/*
	Animation2D(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int duration);
	Animation2D(ALLEGRO_BITMAP *image, int columns, int rows, int duration);
	Animation2D(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int frames, int columns, int duration);
	Animation2D(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int duration, Vector2 offset);
	Animation2D(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int frames, int coulmns, int duration, Vector2 offset);
	*/
	~Animation2D();

	void New(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int duration, bool repeat);
	void New(ALLEGRO_BITMAP *image, int columns, int rows, int duration, bool repeat);
	void New(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int frames, int columns, int duration, bool repeat);
	void New(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int duration, Vector2 offset, bool repeat);
	void New(ALLEGRO_BITMAP *image, Vector2 spriteLenght, int frames, int coulmns, int duration, Vector2 offset, bool repeat);

	void Reset();
	void Update();
	void Draw(Vector2 position, bool hFlip);
	bool IsFinished();
};