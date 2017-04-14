#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Initialize()
{
	isActive = true;
}

void GameObject::Update()
{
	if (isActive)
	{

	}
}

void GameObject::Draw()
{
	if (isActive)
	{

	}
}

void GameObject::SetActive(bool active)
{
	isActive = active;
}

bool GameObject::IsActive()
{
	return isActive;
}
