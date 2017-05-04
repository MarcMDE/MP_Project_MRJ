#pragma once
#include "Transform.h"

class GameObject 
{
private:
	bool isActive;
	bool onScreen;
public:
	void SetActive(bool active);
	bool IsActive();
	bool OnScreen();
	//void UpdateOnScreen(Vector2 lenght);

	GameObject();
	~GameObject();
};

