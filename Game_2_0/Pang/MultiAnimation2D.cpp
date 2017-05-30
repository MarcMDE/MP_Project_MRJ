#include "MultiAnimation2D.h"

MultiAnimation2D::MultiAnimation2D()
{
	animations = NULL;
}

MultiAnimation2D::~MultiAnimation2D()
{
	delete[]animations;
}

void MultiAnimation2D::New(ALLEGRO_BITMAP * image, int animationsLenght)
{
	spriteSheet.New(image);
	this->animationsLenght = animationsLenght;

	//animations = (FramesSequence*)malloc(sizeof(FramesSequence) * animationsLenght);
	animations = new FramesSequence[animationsLenght];
	currentAnimation = 0;
	Reset();
}

void MultiAnimation2D::NewSequence(FramesSequence sequence, int index)
{
	animations[index] = sequence;
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

		if (currentFrame < animations[currentAnimation].frames-1)
		{
			currentFrame++;
		}
		else if (animations[currentAnimation].repeat) currentFrame = 0;

		//printf("currFrame: %i \n", currentFrame);
	}
	else
	{
		counter++;
	}
}

void MultiAnimation2D::SetCurrentSequence(int index)
{
	currentAnimation = index;
	spriteSheet.SetOffset(animations[index].offset);

	sourceY = 0;

	for (int i = 1; i <= currentAnimation; i++)
	{
		sourceY += animations[i - 1].height;
	}
}

void MultiAnimation2D::Draw(Vector2 position, bool hFlip)
{
	spriteSheet.DrawRegion(position, { (float)currentFrame * animations[currentAnimation].width, sourceY },
	{(float)animations[currentAnimation].width, (float)animations[currentAnimation].height}, (int)hFlip);
}

bool MultiAnimation2D::IsCurrentSequenceFinished()
{
	return !animations[currentAnimation].repeat && currentFrame >= animations[currentAnimation].frames - 1;
}
