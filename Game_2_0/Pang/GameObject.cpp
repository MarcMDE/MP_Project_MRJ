#include "GameObject.h"


GameObject::GameObject()
{
	New();
}

GameObject::~GameObject()
{
}

void GameObject::New()
{
	isActive = true;
	isDrawable = true;
}

void GameObject::SetActive(bool active)
{
	isActive = active;
}

void GameObject::SetDrawable(bool drawable)
{
	isDrawable = drawable;
}

bool GameObject::IsActive()
{
	return isActive;
}

bool GameObject::IsDrawable()
{
	return isDrawable;
}

void GameObject::Activate()
{
	SetActive(true);
	SetDrawable(true);
}

void GameObject::Deactivate()
{
	SetActive(false);
	SetDrawable(false);
}
