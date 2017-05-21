#include "Timer.h"



Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::New(Vector2 position)
{
	SetPosition(position);
	Reset();
}

void Timer::Reset()
{
	m_seconds = 0;
	m_minuts = 0;
	m_counter = 0;
}

void Timer::Update()
{
	if (IsActive())
	{
		if (m_counter < 59) m_counter++;
		else
		{
			m_counter = 0;
			if (m_seconds < 59) m_seconds++;
			else
			{
				m_seconds = 0;
				m_minuts++;
			}
		}
	}
}

void Timer::Draw(ALLEGRO_FONT * font, ALLEGRO_COLOR color)
{
	if (IsDrawable())
	{
		al_draw_textf(font, color, GetPosition().x, GetPosition().y, ALLEGRO_ALIGN_CENTER, "%i : %i", m_minuts, m_seconds);
	}
}

int Timer::GetSeconds()
{
	return m_seconds;
}

int Timer::GetMinuts()
{
	return m_minuts;
}
