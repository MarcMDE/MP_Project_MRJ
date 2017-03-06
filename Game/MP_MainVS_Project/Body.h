#pragma once
#include "GameUtils.h"

class Body
{
public:
	Body();
	~Body();
	Vector2 Position
	{
		get
		{
			return position;

		}
	};

private:
	Vector2 position;
	Collider collider;
};

