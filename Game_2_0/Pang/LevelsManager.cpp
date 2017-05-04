#include "LevelsManager.h"

LevelsManager::LevelsManager()
{
	//m_font = al_create_builtin_font();
}


LevelsManager::LevelsManager(int level)
{
	m_currentLevel = level;
	m_level.New(level);
	m_isStarted = false;
}



LevelsManager::~LevelsManager()
{
}

void LevelsManager::RestartLevel()
{
	StartNewLevel(m_currentLevel);
	m_attempts--;
}

void LevelsManager::StartNewLevel(int level)
{
	m_level.New(level);
	m_isStarted = false;
	level = m_currentLevel;
	m_level.Update(); // Check why needed. // Temp
}

void LevelsManager::StartNextLevel()
{
	StartNewLevel(m_currentLevel + 1);
}

void LevelsManager::Update()
{
	if (m_isStarted)
	{
		m_level.Update();
	}
	else if (input.IsKeyPressed(ALLEGRO_KEY_SPACE))
	{
		m_isStarted = true;
	}

#ifdef DEBUG
	if (input.IsKeyPressed(ALLEGRO_KEY_R))
	{
		RestartLevel();
	}
#endif // DEBUG

}

void LevelsManager::Draw()
{
	//if (!m_isStarted) al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT - 70, ALLEGRO_ALIGN_CENTER, "PRESS <SPACE> TO START!!!");
	
	m_level.Draw();

	//al_draw_textf(m_font, al_map_rgb(255, 255, 255), 100, SCREEN_HEIGHT - 70, ALLEGRO_ALIGN_CENTER, "Attempts: %i", m_attempts);
	
}

bool LevelsManager::GetIsStarted()
{
	return m_isStarted;
}

Bubble * LevelsManager::GetBubbles()
{
	return m_level.GetBubbles();
}

int LevelsManager::GetBubblesLenght()
{
	return m_level.GetBubblesLenght();
}

int LevelsManager::GetActiveBubblesLeft()
{
	return m_level.GetActiveBubblesLeft();
}
