#pragma once

#include "GameObject.h"
#include "allegro5\allegro_font.h"

class Timer : public GameObject
{
private: 
	int m_seconds;
	int m_minuts;
	int m_counter;
public:
	Timer();
	~Timer();
	void New(Vector2 position);
	void Reset();
	void Update();
	void Draw(ALLEGRO_FONT* font, ALLEGRO_COLOR color);
	int GetSeconds();
	int GetMinuts();
};

