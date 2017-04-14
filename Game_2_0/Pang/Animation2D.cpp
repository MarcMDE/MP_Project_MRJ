#include "Animation2D.h"



Animation2D::Animation2D()
{
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration)
{
	spriteSheet = Sprite(image);
	lenght = spriteLenght;
	columns = spriteSheet.GetWidth() / lenght.x;
	this->duration = duration;
	counter = 0;
	frames = (spriteSheet.GetWidth() / lenght.x) * (spriteSheet.GetHeight() / lenght.y);
	currentFrame = 0;
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration)
{
	spriteSheet = Sprite(image);
	lenght = spriteLenght;
	this->columns = columns;
	this->duration = duration;
	counter = 0;
	this->frames = frames;
	currentFrame = 0;
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration, Vector2 offset)
{
	spriteSheet = Sprite(image, offset);
	lenght = spriteLenght;
	columns = spriteSheet.GetWidth() / lenght.x;
	this->duration = duration;
	counter = 0;
	frames = (spriteSheet.GetWidth() / lenght.x) * (spriteSheet.GetHeight() / lenght.y);
	currentFrame = 0;
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int coulmns, int duration, Vector2 offset)
{
	spriteSheet = Sprite(image, offset);
	lenght = spriteLenght;
	this->columns = columns;
	this->duration = duration;
	counter = 0;
	this->frames = frames;
	currentFrame = 0;
}


Animation2D::~Animation2D()
{
}

void Animation2D::Update()
{
	if (counter >= duration)
	{
		counter = 0;

		if (currentFrame < frames)
		{
			currentFrame++;
		}
		else currentFrame = 0;
	}
	else
	{
		counter++;
	}
}

void Animation2D::Draw(Vector2 position, bool hFlip)
{
	spriteSheet.DrawRegion(position, { currentFrame - (currentFrame / columns) * columns, currentFrame / columns }, lenght, hFlip);
}
