#pragma once

#include "GameObject.h"
#include "Sprite.h"

class Particle : public GameObject
{
private:

	Sprite m_sprite;
	Vector2 m_speed;
	Vector2 m_direction;
	Vector2 m_velocity;
	int m_counter;
	
public:
	Particle();
	~Particle();

	//Particle(ALLEGRO_BITMAP* image);
	void Construct(ALLEGRO_BITMAP* image);
	void New(Vector2 position, Vector2 speed, Vector2 direction, int duration);
	void Update();
	void Draw();


};

