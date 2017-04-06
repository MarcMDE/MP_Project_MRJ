#include "CharacterController.h"
#include <stdio.h>

CharacterController::CharacterController()
{
}

CharacterController::CharacterController(Vector2 position, Vector2 topSpeed, Vector2 speedIncrement, Vector2 colliderOffset, Vector2 colliderLenght)
{
	body = Body(position, colliderOffset, colliderLenght);
	friction = { 0.0f, 0.5f };
	speed = { 0, 0 };
	this->topSpeed = topSpeed;
	this->speedIncrement = speedIncrement;
	direction = { 0, 0 };
	auxVelocity = { 0, 0 };
	finalVelocity = { 0, 0 };
	updateSpeed = false;
	isJumping = false;
	isGrounded = false;
}

void CharacterController::Update(char key, bool isKeyDown)
{
	Move(key, isKeyDown);
}

void CharacterController::Draw(Sprite sprite)
{
	body.Draw(sprite);
}

Vector2 CharacterController::GetPos() const
{
	return body.GetPos();
}

void CharacterController::Move(char key, bool isKeyDown, )
{
	isGrounded = false;
	updateSpeed = false;


	if (!isGrounded && body.GetPos().y >= 480)
	{
		isGrounded = true;
		isJumping = false;
		body.SetInstantPosition({ body.GetPos().x, 480 });
		speed.y = 0;
		auxVelocity.y = 0;
		direction.y = 0;
	}
	else if (!isGrounded)
	{
		printf("posY: %f\n", GetPos().y);
		auxVelocity.y += friction.y;
	}

	Jump(key, isKeyDown);

	if (isKeyDown && !isJumping)
	{
		switch (key)
		{
		case 'R':
		case 'r':
			if (direction.x != -1)
			{
				auxVelocity.x = 0;
				direction.x = -1;
				speed.x = 0;
			}
			else
			{
				updateSpeed = true;
			}
			break;

		case 's':
		case 'S':
			if (direction.x != 1)
			{
				auxVelocity.x = 0;
				direction.x = 1;
				speed.x = 0;
			}
			else
			{
				updateSpeed = true;
			}
			break;
		default:
			updateSpeed = false;
			speed.x = 0;
			auxVelocity.x = 0;
			direction.x = 0;
		}
	}
	else if (!isJumping)
	{
		updateSpeed = false;
		speed.x = 0;
		auxVelocity.x = 0;
		direction.x = 0;
	}
	if (updateSpeed)
	{
		speed.x += speedIncrement.x;
	}
	
	if (speed.x > topSpeed.x) speed.x = topSpeed.x;

	auxVelocity.x += speed.x;
	auxVelocity.x -= friction.x;

	if (auxVelocity.x < 0) auxVelocity.x = 0;

	finalVelocity.x = auxVelocity.x * direction.x;
	finalVelocity.y = auxVelocity.y;

	body.UpdatePosition(finalVelocity);
}

void CharacterController::Jump(char key, bool isKeyDown)
{
	if (isGrounded && !isJumping && isKeyDown)
	{
		if (key == 'K')
		{
			speed.y += speedIncrement.y;
			isJumping = true;
			direction.y = 1;
			auxVelocity.y -= speed.y;
		}
	}
}



CharacterController::~CharacterController()
{
}
