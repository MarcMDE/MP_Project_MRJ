#ifndef GAMEUTILS_H
#define GAMEUTILS_H


//BASIC STRUCTS

typedef struct
{
	float x;
	float y;
}Vector2;

typedef struct
{
	Vector2 position;
	float rotation;
	float scale;
}Transform;

#endif // !GAMEUTILS_H