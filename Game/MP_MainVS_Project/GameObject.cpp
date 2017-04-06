#include "GameObject.h"


void GameObject::SetActive(bool active)
{
	isActive = active;
}

bool GameObject::IsActive()
{
	return isActive;
}

bool GameObject::OnScreen()
{
	return onScreen;
}
/*
void GameObject::UpdateOnScreen(Vector2 lenght)
{
	if (GetPosition().x < 0 - lenght.x / 2 || GetPosition().x > SCREEN_LENGHT.x + lenght.x / 2 ||
		GetPosition().y < 0 - lenght.y / 2 || GetPosition().y > SCREEN_LENGHT.y + lenght.y / 2)
	{
		onScreen = false;
	}
	else onScreen = true;
}
*/

GameObject::GameObject()
{

}


GameObject::~GameObject()
{
}
