//BASIC STRUCTS

struct Vector2
{
	float x;
	float y;
};

struct Collider
{
	Vector2 position;
	Vector2 offset;
	Vector2 lenght;
	bool active;
};

struct Transform
{
	Vector2 position;
	float rotation;
	float scale;
};