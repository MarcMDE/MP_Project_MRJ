#include "Arrow.h"

#include <stdio.h>



Arrow::Arrow()
{
}


Arrow::~Arrow()
{
}

void Arrow::New(ALLEGRO_BITMAP * image)
{
	sprite.New(image, { ARROW_BODY_WIDTH / 2, 0 });
	Deactivate();
	Reset();
}

void Arrow::Update()
{
	if (IsActive())
	{
		if (lenghtY < ARROW_BODY_MAX_LENGHT && GetPosition().y - lenghtY - ARROW_HEAD_HEIGHT > 0)
		{
			lenghtY += ARROW_SPEED;
			collider.SetLenght({ collider.GetLenght().x, lenghtY + ARROW_HEAD_HEIGHT });
			collider.SetOffset({ 0, -(lenghtY + ARROW_HEAD_HEIGHT)/2});
		}
		else
		{
			if (lenghtY > ARROW_BODY_MAX_LENGHT)
			{
				lenghtY = ARROW_BODY_MAX_LENGHT;
			}
			
			if (counter < ARROW_DURATION)
			{
				counter++;
			}
			else
			{
				Deactivate();
			}
		}
	}
}

void Arrow::CheckBubblesCollision(Bubble * b, int lenght)
{
	if (IsActive())
	{
		int i = 0;
		while (IsActive() && i < lenght)
		{
			if (b[i].IsActive() && collider.CheckAABBCircleCollision(b[i].GetCollider()))
			{
				b[i].SetAsHit();
				Deactivate();
			}
			i++;
		}
	}
}

void Arrow::Draw()
{
	if (IsDrawable())
	{
		//sprite.Draw({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });

		// Set Offset
		sprite.SetOffset({-ARROW_BODY_WIDTH/2, -lenghtY});
		// Draw
		sprite.DrawRegion(GetPosition(), { 0, ARROW_BODY_MAX_LENGHT - lenghtY }, { ARROW_BODY_WIDTH, lenghtY }, false);

		// SetOffset
		sprite.SetOffset({ -ARROW_HEAD_WIDTH / 2, -ARROW_HEAD_HEIGHT });
		// Draw
		sprite.DrawRegion({GetPosition().x, GetPosition().y - lenghtY}, { ARROW_BODY_WIDTH, ARROW_BODY_MAX_LENGHT - ARROW_HEAD_HEIGHT }, { ARROW_HEAD_WIDTH, ARROW_HEAD_HEIGHT }, false);
		
		collider.DebugDraw();
	}
}

void Arrow::Shot(Vector2 position)
{
	if (!IsActive())
	{
		SetPosition(position);
		Reset();
		collider.New(position, { -ARROW_BODY_WIDTH / 2, -lenghtY }, { ARROW_BODY_WIDTH, lenghtY + ARROW_HEAD_HEIGHT });
		Activate();
		printf("Arrow shot!\n");
	}
}

void Arrow::Reset()
{
	lenghtY = 0;
	counter = 0;
}
