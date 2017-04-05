#ifndef GAMEUTILS_H
#define GAMEUTILS_H


//BASIC STRUCTS

struct Vector2
{
	float x;
	float y;

	Vector2& operator+(const Vector2& rhs) 
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2& operator*(const Vector2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
};

#endif // !GAMEUTILS_H