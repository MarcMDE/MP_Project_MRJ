#pragma once

#include "Transform.h"
#include "GameUtils2D.h"

using namespace GameUtils2D;

class GameObject : public Transform
{
private:
	bool isActive;
	bool isDrawable;

public:
	GameObject();
	~GameObject();

	void New();
	void SetActive(bool active);
	void SetDrawable(bool drawable);
	bool IsActive();
	bool IsDrawable();
};

