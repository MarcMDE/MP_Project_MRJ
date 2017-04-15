#include "Player.h"
#include <stdio.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::New()
{
	SetPosition({ PLAYER_1_SOURCEPOSITION_X, GROUND_Y });
	SetRotation(0);
	SetScale(1);

	speed = PLAYER_1_SPEED;
	topSpeed = { PLAYER_1_TOPSPEED_X, 0 };
	direction = { 0, 0 };
	velocity = { 0, 0 };
	isGrounded = false;
	isJumping = false;
	fallingMovementFactor = PLAYER_1_FALLING_MOV_FACTOR;
	jumpingMovementFactor = PLAYER_1_JUMPING_MOV_FACTOR;

	sprite.New(al_load_bitmap("character.png"), { -PLAYER_WIDTH / 2, -PLAYER_HEIGHT });
	collider.New(GetPosition(), { 0, -PLAYER_HEIGHT/2 }, { PLAYER_WIDTH, PLAYER_HEIGHT });
}

void Player::Update()
{
	if (IsActive())
	{
		isGrounded = false;
		direction.x = 0;

		if (GetPosition().y >= GROUND_Y)
		{
			isGrounded = true;
			isJumping = false;
			velocity.y = 0;
			SetPosition({ GetPosition().x, GROUND_Y });
		}

		// JUMP
		if (isGrounded && !isJumping && input.IsKeyPressed(PLAYER_1_JUMP))
		{
			isJumping = true;
			velocity.y = -PLAYER_1_JUMPSPEED;
		}
		else if (!isGrounded)
		{
			// FALLING
			velocity.y += GRAVITY_Y;
		}

		// MOVEMENT
		if (input.IsKeyDown(PLAYER_1_RIGHT))
		{
			direction.x = 1;
		}
		else if (input.IsKeyDown(PLAYER_1_LEFT))
		{
			direction.x = -1;
		}

		if (input.IsKeyDown(PLAYER_1_UP))
		{
			direction.y = -1;
		}
		else if (input.IsKeyDown(PLAYER_1_DOWN))
		{
			direction.y = 1;
		}

		/*
		if (!isJumping && !isGrounded)
		{
			// falling
			velocity.x = direction.x * speed.x * fallingMovementFactor;
		}
		else if (isJumping)
		{
			// grounded or jumping
			velocity.x = direction.x * speed.x * jumpingMovementFactor;
		}
		else
		{
			velocity.x = direction.x * speed.x;
		}
		*/

		if (isGrounded)
		{
			velocity.x += speed.x * direction.x;
			if (velocity.x > topSpeed.x) velocity.x = topSpeed.x;
			else if (velocity.x < -topSpeed.x) velocity.x = -topSpeed.x;

			if (direction.x == 0)
			{
				if (velocity.x > 0)
				{
					velocity.x -= GROUND_FRICTION_X;
					if (velocity.x < 0) velocity.x = 0;
				}
				else if (velocity.x < 0)
				{
					velocity.x += GROUND_FRICTION_X;
					if (velocity.x > 0) velocity.x = 0;
				}
			}
		}

		// SCREEN BOUNDS COLLISION
		if (GetPosition().x - collider.GetLenght().x / 2 <= 0)
		{
			if (velocity.x < 0) velocity.x = 0;
			SetPosition({ 0 + collider.GetLenght().x / 2, GetPosition().y });
		}
		else if (GetPosition().x + collider.GetLenght().x / 2 >= SCREEN_WIDTH)
		{
			if (velocity.x > 0) velocity.x = 0;
			SetPosition({ SCREEN_WIDTH - collider.GetLenght().x / 2, GetPosition().y });
		}

		printf("P_v: %f\n", velocity.x);

		Translate(velocity);
		collider.UpdatePosition(GetPosition());
	}
}

void Player::Draw()
{
	if (IsDrawable())
	{
		sprite.Draw(GetPosition());
		collider.DebugDraw();
	}
}
