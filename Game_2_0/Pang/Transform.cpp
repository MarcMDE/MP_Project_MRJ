#include "Transform.h"



Transform::Transform()
{
	position.x = 0;
	position.y = 0;

	rotation = .0f;
	scale = .0f;
}

Transform::Transform(Vector2 p, float r, float s)
{
	position = p;
	rotation = r;
	scale = s;
}


Transform::~Transform()
{
}

void Transform::SetPosition(Vector2 p)
{
	position = p;
}

void Transform::SetRotation(float r)
{
	rotation = r;
}

void Transform::SetScale(float s)
{
	scale = s;
}

Vector2 Transform::GetPosition()
{
	return position;
}

float Transform::GetRotation()
{
	return rotation;
}

float Transform::GetScale()
{
	return scale;
}

void Transform::Translate(Vector2 d)
{
	position += d;
}

void Transform::Rotate(float d)
{
	rotation += d;
}

void Transform::Scalate(float d)
{
	scale += d;
}
