#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "GameConfig.h"

using namespace GameConfig;

class Particle : public GameObject
{
private:
	Sprite m_sprite;
	float m_speed;
	Vector2 m_direction;
	Vector2 m_velocity;
	int m_counter;
	bool m_gravity;
	
public:
	Particle();
	~Particle();

	//Particle(ALLEGRO_BITMAP* image);
	void Construct(ALLEGRO_BITMAP* image);
	void New(Vector2 position, float speed, Vector2 direction, int duration, bool gravity);
	void Update();
	void Draw();


};

