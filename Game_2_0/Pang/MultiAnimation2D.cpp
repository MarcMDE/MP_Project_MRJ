#include "MultiAnimation2D.h"

MultiAnimation2D::MultiAnimation2D()
{
}


MultiAnimation2D::~MultiAnimation2D()
{
}

void MultiAnimation2D::New(ALLEGRO_BITMAP * image, FramesSequence * animations, int animationsLenght)
{
	spriteSheet.New(image);
	this->animations = animations;
	this->animationsLenght = animationsLenght;
	
	sourceY = 0;

	for (int i = 1; i <= animationsLenght; i++)
	{
		sourceY += animations[i - 1].height;
	}

	currentAnimation = 0;
	Reset();
}

void MultiAnimation2D::Reset()
{
	counter = 0;
	currentFrame = 0;
}

void MultiAnimation2D::Update()
{
	if (counter >= animations[currentAnimation].duration)
	{
		counter = 0;

		if (currentFrame < animations[currentAnimation].frames)
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

void MultiAnimation2D::SetSequence(int index)
{
	currentAnimation = index;
	spriteSheet.SetOffset(animations[index].offset);
	Reset();
}

void MultiAnimation2D::Draw(Vector2 position, bool hFlip)
{
	spriteSheet.DrawRegion(position, { (float)currentFrame * animations[currentAnimation].width, sourceY },
	{(float)animations[currentAnimation].width, (float)animations[currentAnimation].height}, (int)hFlip);
}
