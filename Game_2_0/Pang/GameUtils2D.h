#pragma once

namespace GameUtils2D
{
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
}