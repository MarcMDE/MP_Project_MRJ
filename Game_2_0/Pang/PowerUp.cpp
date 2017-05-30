#include "PowerUp.h"
#include <stdio.h>


PowerUp::PowerUp()
{
}


PowerUp::~PowerUp()
{
}

void PowerUp::New(PowerUps type)
{
	m_isGrounded = false;
	m_sprite.New(al_load_bitmap(POWERUPS_SPRITE[type]));
	m_collider.New({ 0.0f, .0f }, {(float)m_sprite.GetWidth(), (float)m_sprite.GetHeight()});
	Deactivate();
}

void PowerUp::Spawn(Vector2 position)
{
	m_isGrounded = false;
	SetPosition(position);
	m_collider.UpdatePosition(position);
	m_velocity = { 0, 0 };
	m_counter = POWERUPS_DURATION;
	Activate();
	printf("PowerUp_Spawn!\n");
}

void PowerUp::Update()
{
	if (IsActive())
	{
		if (m_isGrounded == false)
		{
			m_velocity.y += POWERUPS_GRAVITY;
			Translate(m_velocity);
			if (GetPosition().y + m_collider.GetLenght().y / 2 >= GROUND_Y)
			{
				m_isGrounded = true;
				SetPosition({ GetPosition().x, GROUND_Y - m_collider.GetLenght().y / 2 });
			}
			m_collider.UpdatePosition(GetPosition());
		}
		else if (m_counter <= 0)
		{
			Deactivate();
		}
		else
		{
			m_counter--;
		}
	}
}

void PowerUp::Draw()
{
	if (IsDrawable())
	{
		m_sprite.Draw(GetPosition());

#ifdef DEBUG	
		m_collider.DebugDraw();
#endif
	}
}

bool PowerUp::CheckPlayerCollision(AABB c)
{
	if (IsActive() && m_collider.CheckAABBsCollision(c))
	{
		printf("Colliding!\n");
		//m_emitter.Burst();
		Deactivate();
		// TODO: Apply PowerUp effect.
		return true;
	}
	return false;
}

PowerUps PowerUp::GetType()
{
	return m_type;
}
