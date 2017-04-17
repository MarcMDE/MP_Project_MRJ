#include "Bubble.h"



void Bubble::Move()
{

	DefineCurrentAnimation(IDLE);

	velocity.x = BUBBLES_SPEED[category].x * directionX;
	velocity.y += GRAVITY_Y;

	if (GetPosition().y + collider.GetRadius() >= GROUND_Y)
	{
		velocity.y = -BUBBLES_SPEED[category].y;
		SetPosition({ GetPosition().x, GROUND_Y });
		DefineCurrentAnimation(GROUND_COLLISION);
	}

	if (GetPosition().x + collider.GetRadius() >= SCREEN_WIDTH)
	{
		directionX = -1;
		orientation = LEFT;
		SetPosition({ SCREEN_WIDTH - collider.GetRadius(), GetPosition().y });
	}
	else if (GetPosition().x - collider.GetRadius() <= 0)
	{
		directionX = 1;
		orientation = RIGHT;
		SetPosition({ SCREEN_WIDTH + collider.GetRadius(), GetPosition().y });
	}

	Translate(velocity);
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
}


Bubble::~Bubble()
{
}

void Bubble::New(Vector2 position, int category, MultiAnimation2D animator, int directionX)
{
	SetPosition(position);
	this->category = category;
	this->animator = animator;
	velocity = { 0, 0 };
	this->directionX = directionX;

	collider.New(GetPosition(), BUBBLES_RADIUS[category]);
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

void Bubble::Update()
{
	if (IsActive())
	{
		Move();
		collider.UpdatePosition(GetPosition());
	}
}

void Bubble::Draw()
{
	if (IsDrawable())
	{
		animator.Draw(GetPosition(), (bool)orientation);
	}
}
