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

void Particle::New(Vector2 position, Vector2 speed, Vector2 direction, int duration)
{
	SetPosition(position);
	m_speed = speed;
	m_direction = direction;
	m_velocity = { 0, 0 };
	m_counter = duration;
	Activate();
	

}

void Particle::Update()
{
	if (IsActive())
	{
		m_velocity = m_speed*m_direction;
		Translate(m_velocity);

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
