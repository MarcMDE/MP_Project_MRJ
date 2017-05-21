#include "LevelsManager.h"

LevelsManager::LevelsManager()
{
}

LevelsManager::LevelsManager(PangLevels level)
{
	m_currentLevel = level;
	m_level.New(level);
	m_isStarted = false;
}

LevelsManager::~LevelsManager()
{
}

void LevelsManager::New(PangLevels level)
{
	m_currentLevel = level;
	m_level.New(level);
	m_isStarted = false;
	m_attempts = MAX_ATTEMPTS;
	uInterface.New();
}

void LevelsManager::RestartLevel()
{
	if (m_attempts > 0)
	{
		StartNewLevel(m_currentLevel);
		m_attempts--;
	}
	else
	{
		// GAME END
		uInterface.SetCurrentTitle(GAME_OVER);
	}
}

void LevelsManager::StartNewLevel(int level)
{
	m_level.New(level);
	m_isStarted = false;
	level = m_currentLevel;
	m_level.Update(); // Check why needed. // Temp
	uInterface.SetCurrentTitle(LEVEL);
}

void LevelsManager::StartNextLevel()
{
	if (m_currentLevel < LEVELS_LENGHT - 1)
	{
		StartNewLevel(m_currentLevel + 1);
	}
	else
	{
		// TODO: END SCREEN
	}
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

	uInterface.Update();

#ifdef DEBUG
	if (input.IsKeyPressed(ALLEGRO_KEY_R))
	{
		RestartLevel();
	}
#endif // DEBUG

}

void LevelsManager::Draw()
{	
	m_level.Draw();	
	uInterface.Draw(m_currentLevel, m_attempts, !m_isStarted);
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
