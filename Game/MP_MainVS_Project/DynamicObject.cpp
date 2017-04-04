#include "DynamicObject.h"


void DynamicObject::UpdateVelocity()
{
	velocity.x = speed.x * direction.x;
	velocity.y = speed.y * direction.y;
}

DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(Transform transform, Vector2 colliderOffset, Vector2 colliderLenght, Vector2 friction)
{
	body = Body(transform, colliderOffset, colliderLenght);
	velocity = { 0, 0 };
	direction = { 0, 0 };
	speed = { 0, 0 };
	maxSpeed = { 0.1f, 0.1f };
	this->friction = friction;
	grounded = true;
	active = true;
}


DynamicObject::~DynamicObject()
{
}

void DynamicObject::SetDirection(Vector2 direction)
{
	this->direction = direction;
}

void DynamicObject::AddForce(Vector2 force, Vector2 direction)
{
	if (active)
	{
		this->direction = direction;

		speed.x += force.x;
		speed.y += force.y;

		if (maxSpeed.x != -1 && speed.x > maxSpeed.x) speed.x = maxSpeed.x;
		if (maxSpeed.y != -1 && speed.y > maxSpeed.y) speed.y = maxSpeed.y;

		UpdateVelocity();
	}
}

void DynamicObject::Update()
{
	if (active)
	{
		UpdateVelocity();
		body.UpdatePosition(velocity);
	
		//speed.x -= friction.x;
		//if (speed.x < 0) velocity.x = 0;
	}
}

void DynamicObject::SetAsGrounded()
{
	direction.y = 0;
	speed.y = 0;
	UpdateVelocity();
}

void DynamicObject::SetAsActive(bool active)
{
	this->active = active;
}

Vector2 DynamicObject::GetPosition()
{
	return body.GetPosition();
}

