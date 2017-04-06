#include "Transform.h"
#include <stdio.h>

Transform::Transform()
{
	
	printf("here");
	position = { 50, 0};
	scale = 1.0f;
	rotation = 0.0f;
	
}

Transform::Transform(Vector2 p)
{
	position = p;
	printf("T%f\n", position.x);
	scale = 1.0f;
	rotation = 0.0f;
}

Transform::~Transform()
{
}

Vector2 Transform::GetPosition() const
{
	return position;
}

float Transform::GetScale() const
{
	return scale;
}

float Transform::GetRotation() const
{
	return rotation;
}

void Transform::SetPosition(Vector2 v)
{
	position = v;
}

void Transform::SetScale(float v)
{
	scale = v;
}

void Transform::SetRotation(float v)
{
	rotation = v;
}

void Transform::Translate(Vector2 v)
{
	position.x += v.x;
}

void Transform::ScaleUp(float v)
{
	scale += v;
}

void Transform::Rotate(float v)
{
	rotation += v;
}
