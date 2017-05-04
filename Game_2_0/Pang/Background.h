#pragma once

#include "Sprite.h"
#include "Animation2D.h"
#include "GameUtils2D.h"
#include "GameConfig.h"
#include "GameObject.h"

using namespace GameConfig;

class Background : public GameObject
{
private:
	Sprite back;
	Animation2D *animations;
	Vector2 *animationsPosition;
	int animationsLenght;
	
public:
	Background();
	~Background();

	void New(ALLEGRO_BITMAP * image, int animationsLenght);
	void NewAnimation(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration, Vector2 position, int index);
	void NewAnimation(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration, Vector2 offset, Vector2 position, int index);

	void Update();
	void Draw();
};

