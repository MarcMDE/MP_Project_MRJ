#pragma once
#include "Transform.h"
#include "Game.h"

class GameObject : public Transform
{
private:
	bool isActive;
	bool onScreen;
public:
	void SetActive(bool active);
	bool IsActive();
	bool OnScreen();
	void UpdateOnScreen(Vector2 lenght);

	GameObject();
	~GameObject();
};

