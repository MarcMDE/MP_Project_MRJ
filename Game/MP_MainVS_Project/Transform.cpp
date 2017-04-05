#include "Transform.h"

Transform::Transform()
{
	position = { 0, 0};
	scale = 1.0f;
	rotation = 0.0f;
}

Transform::Transform(Vector2 p)
{
	position = p;
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
