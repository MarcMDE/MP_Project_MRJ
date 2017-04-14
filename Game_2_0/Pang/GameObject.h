#pragma once

#include "Transform.h"
#include "GameUtils2D.h"

using namespace GameUtils2D;

class GameObject : Transform
{
private:
	bool isActive;

public:
	GameObject();
	~GameObject();

	void Initialize();
	void Update();
	void Draw();

	void SetActive(bool active);
	bool IsActive();
};

