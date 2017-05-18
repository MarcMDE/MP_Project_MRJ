#include "Particle.h"



Particle::Particle()
{
}


Particle::~Particle()
{
}

//Particle::Particle(ALLEGRO_BITMAP* image)
//{
//	m_sprite.New(image);
//	Deactivate();
//}

void Particle::Construct(ALLEGRO_BITMAP * image)
{
	m_sprite.New(image);
	Deactivate();
}

void Particle::New(Vector2 position, float speed, Vector2 direction, int duration, bool gravity)
{
	SetPosition(position);
	m_speed = speed;
	m_direction = direction;
	m_velocity = { 0, 0 };
	m_counter = duration;
	m_gravity = gravity;
	Activate();
	m_velocity = m_direction * m_speed;
}

void Particle::Update()
{
	if (IsActive())
	{
		Translate(m_velocity);
		if (m_gravity) m_velocity.y += PARTICLES_GRAVITY;

		if (m_counter == 0)
		{
			Deactivate();
		}
		else
		{
			m_counter--;
		}
	}
}

void Particle::Draw()
{
	if(IsDrawable())
	{
		m_sprite.Draw(GetPosition());
	}
}
