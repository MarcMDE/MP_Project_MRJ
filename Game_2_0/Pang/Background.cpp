#include "Background.h"



Background::Background()
{
}


Background::~Background()
{
}

void Background::New(ALLEGRO_BITMAP * image, int animationsLenght)
{
	back.New(image);
	this->animationsLenght = animationsLenght;
	animations = (Animation2D*)malloc(sizeof(Animation2D) * animationsLenght);
	animationsPosition = (Vector2*)malloc(sizeof(Vector2) * animationsLenght);
	SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
}

void Background::NewAnimation(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration, Vector2 position, int index)
{
	animations[index].New(image, spriteLenght, frames, columns, duration, true);
	animationsPosition[index] = position;
}

void Background::NewAnimation(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration, Vector2 offset, Vector2 position, int index)
{
	animations[index].New(image, spriteLenght, frames, columns, duration, offset, true);
	animationsPosition[index] = position;
}

void Background::Update()
{
	if (IsActive())
	{
		for (int i = 0; i < animationsLenght; i++)
		{
			animations[i].Update();
		}
	}
}

void Background::Draw()
{
	if (IsDrawable())
	{
		back.Draw(GetPosition());

		for (int i = 0; i < animationsLenght; i++)
		{
			animations[i].Draw(animationsPosition[i], false);
		}
	}
}
