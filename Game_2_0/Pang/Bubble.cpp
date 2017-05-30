#include "Bubble.h"
#include "stdio.h"


void Bubble::Move()
{
	velocity.x = BUBBLES_SPEED[category].x * directionX;
	velocity.y += BUBBLES_GRAVITY_Y;

	Translate(velocity);

	if (currentAnimation == BUBBLEANIM_GROUND_COLLISION && animator.IsCurrentSequenceFinished() == true)
	{
		DefineCurrentAnimation(BUBBLEANIM_IDLE);
	}

	if (GetPosition().y + collider.GetRadius() >= GROUND_Y)
	{
		velocity.y = -BUBBLES_SPEED[category].y;
		SetPosition({ GetPosition().x, GROUND_Y - collider.GetRadius() });
		DefineCurrentAnimation(BUBBLEANIM_GROUND_COLLISION);
		printf("bounce\n");
	}

	if (GetPosition().x + collider.GetRadius() >= SCREEN_WIDTH)
	{
		directionX = -1;
		SetPosition({ SCREEN_WIDTH - collider.GetRadius(), GetPosition().y });
	}
	else if (GetPosition().x - collider.GetRadius() <= 0)
	{
		directionX = 1;
		SetPosition({ 0 + collider.GetRadius(), GetPosition().y });
	}

	animator.SetCurrentSequence(currentAnimation);
	//printf("Curr anim: %i\n", (int)currentAnimation);
	
}

void Bubble::DefineCurrentAnimation(BubbleAnimations animation)
{
	if (currentAnimation != animation)
	{
		currentAnimation = animation;
		animator.Reset();
	}
}

Bubble::Bubble()
{
	SetPosition({ 0, 0 });
	category = 0;
	directionX = 0;
}


Bubble::~Bubble()
{
}

void Bubble::New(Vector2 position, int category, int directionX, ALLEGRO_BITMAP * spriteSheet)
{
	SetPosition(position);
	this->category = category;

	velocity = { 0, 0 };
	this->directionX = directionX;
	isHit = false;

	animator.New(spriteSheet, BUBBLES_SEQUENCES_LENGHT);
	animator.NewSequence({ BUBBLES_SEQUENCE_FRAMES, BUBBLES_RADIUS[category]*2, BUBBLES_RADIUS[category]*2, BUBBLES_SEQUENCE_DURATION, 
	{(float)-BUBBLES_RADIUS[category], (float)-BUBBLES_RADIUS[category] }, true }, 0);
	animator.NewSequence({ BUBBLES_SEQUENCE_FRAMES, BUBBLES_RADIUS[category]*2, BUBBLES_RADIUS[category]*2, BUBBLES_SEQUENCE_DURATION, 
	{(float)-BUBBLES_RADIUS[category], (float)-BUBBLES_RADIUS[category] }, false }, 1);

	DefineCurrentAnimation(BUBBLEANIM_IDLE);
	collider.New(GetPosition(), BUBBLES_RADIUS[category]);
	Activate();
}

void Bubble::SetAsHit()
{
	isHit = true;
}

int Bubble::GetCategory()
{
	return category;
}

bool Bubble::IsHit()
{
	return isHit;
}

void Bubble::Activate()
{
	SetActive(true);
	SetDrawable(true);
}

void Bubble::Deactivate()
{
	SetActive(false);
	SetDrawable(false);
}

void Bubble::Update(bool move)
{
	if (IsActive())
	{
		if (move) Move();
		collider.UpdatePosition(GetPosition());
		animator.Update();

#ifdef DEBUG
		if (input.IsKeyPressed(ALLEGRO_KEY_K))
		{
			isHit = true;
		}
#endif

	}
}

void Bubble::Draw()
{
	if (IsDrawable())
	{
		animator.Draw(GetPosition(), false);
		#ifdef DEBUG	
		collider.DebugDraw();
		#endif
	}
}

CircleCollider Bubble::GetCollider()
{
	return collider;
}
