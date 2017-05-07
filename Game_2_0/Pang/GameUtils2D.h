#pragma once

#include <stdlib.h>

namespace GameUtils2D
{
	enum Orientation {RIGHT = 0, LEFT};

	struct Vector2
	{
		float x;
		float y;

		Vector2 operator+(const Vector2 &rhs)
		{
			return{ this->x + rhs.x, this->y + rhs.y };
		}

		Vector2& operator+=(const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		Vector2 operator-(const Vector2 &rhs)
		{
			return{ this->x - rhs.x, this->y - rhs.y };
		}

		Vector2& operator-=(const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		Vector2 operator*(const Vector2 &rhs)
		{
			return{ this->x * rhs.x, this->y * rhs.y };
		}

		Vector2& operator*=(const Vector2& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		Vector2 operator*(const float& rhs)
		{
			return{ this->x * rhs, this->y * rhs };
		}

		Vector2& operator*=(const float& rhs)
		{
			x *= rhs;
			y *= rhs;
			return *this;
		}

		Vector2& operator/=(const float& rhs)
		{
			x /= rhs;
			y /= rhs;
			return *this;
		}

		Vector2 operator/(const float& rhs)
		{
			return{ this->x / rhs, this->y / rhs };
		}
	};

	struct FramesSequence
	{
		int frames;
		int width;
		int height;
		int duration;
		Vector2 offset;
		bool repeat;
	};
	
	// TODO: REPAIR!
	int GetRandomValue(int a, int b);
	float GetRandomValue(float a, float b);
}