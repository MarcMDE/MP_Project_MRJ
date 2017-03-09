#include "DynamicObject.h"



DynamicObject::DynamicObject()
{
}


DynamicObject::~DynamicObject()
{
}

void DynamicObject::AddForce(Vector2 force)
{
	velocity.x += force.x;
	velocity.y += force.y;
}
