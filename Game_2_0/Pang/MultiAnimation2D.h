#pragma once

#include "allegro5/allegro.h"
#include "Sprite.h"
#include "GameUtils2D.h"

using namespace GameUtils2D;

class MultiAnimation2D
{
private:
	FramesSequence *animations;
	int counter;
	int currentFrame;
	int currentAnimation;
	int animationsLenght;
	float sourceY;
	Sprite spriteSheet;

public:
	MultiAnimation2D();
	~MultiAnimation2D();

	void New(ALLEGRO_BITMAP *image, FramesSequence *animations, int animationsLenght);

	void Reset();
	void Update();
	void SetSequence(int index);
	void Draw(Vector2 position, bool hFlip);

};

