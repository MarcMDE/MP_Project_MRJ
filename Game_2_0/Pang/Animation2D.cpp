#include "Animation2D.h"
#include <stdio.h>

Animation2D::Animation2D()
{
}

/*
Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration)
{
	New(image, spriteLenght, duration);
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, int columns, int rows, int duration)
{
	New(image, columns, rows, duration);
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration)
{
	New(image, spriteLenght, frames, columns, duration);
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration, Vector2 offset)
{
	New(image, spriteLenght, duration, offset);
}

Animation2D::Animation2D(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int coulmns, int duration, Vector2 offset)
{
	New(image, spriteLenght, frames, columns, duration, offset);
}
*/

Animation2D::~Animation2D()
{
	spriteSheet.~Sprite();
}

void Animation2D::New(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration)
{
	spriteSheet.New(image, { -spriteLenght.x / 2, -spriteLenght.y / 2 });
	lenght = spriteLenght;
	columns = spriteSheet.GetWidth() / lenght.x;
	this->duration = duration;
	counter = 0;
	frames = (spriteSheet.GetWidth() / lenght.x) * (spriteSheet.GetHeight() / lenght.y);
	currentFrame = 0;
}

void Animation2D::New(ALLEGRO_BITMAP * image, int columns, int rows, int duration)
{
	spriteSheet.New(image);
	lenght.x = (float)(spriteSheet.GetWidth() / columns);
	lenght.y = (float)(spriteSheet.GetHeight() / rows);
	spriteSheet.New(image, { -lenght.x / 2, -lenght.y / 2 });
	this->columns = columns;
	this->duration = duration;
	counter = 0;
	frames = (spriteSheet.GetWidth() / lenght.x) * (spriteSheet.GetHeight() / lenght.y);
	currentFrame = 0;
}

void Animation2D::New(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int columns, int duration)
{
	spriteSheet.New(image, { -spriteLenght.x / 2, -spriteLenght.y / 2 });
	lenght = spriteLenght;
	this->columns = columns;
	this->duration = duration;
	counter = 0;
	this->frames = frames;
	currentFrame = 0;
}

void Animation2D::New(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int duration, Vector2 offset)
{
	spriteSheet.New(image, offset);
	lenght = spriteLenght;
	columns = spriteSheet.GetWidth() / lenght.x;
	this->duration = duration;
	counter = 0;
	frames = (spriteSheet.GetWidth() / lenght.x) * (spriteSheet.GetHeight() / lenght.y);
	currentFrame = 0;
}

void Animation2D::New(ALLEGRO_BITMAP * image, Vector2 spriteLenght, int frames, int coulmns, int duration, Vector2 offset)
{
	spriteSheet.New(image, offset);
	lenght = spriteLenght;
	this->columns = columns;
	this->duration = duration;
	counter = 0;
	this->frames = frames;
	currentFrame = 0;
}

void Animation2D::Reset()
{
	currentFrame = 0;
	counter = 0;
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

		//printf("currFrame: %i \n", currentFrame);
	}
	else
	{
		counter++;
	}

}

void Animation2D::Draw(Vector2 position, bool hFlip)
{
	spriteSheet.DrawRegion(position, { (float)(currentFrame - (currentFrame / columns) * columns) * lenght.x, (float)(currentFrame / columns) * lenght.y },
		lenght, (int)hFlip);
}
