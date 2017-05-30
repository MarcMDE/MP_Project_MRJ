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
	m_uInterface.New();
	m_startNewLevel = false;
	m_gameFinished = false;
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
		m_uInterface.SetCurrentTitle(GAME_OVER);
		m_gameFinished = true;
	}
}

void LevelsManager::StartNewLevel(PangLevels level)
{
	if (level != m_currentLevel) m_level.Deinitialize();
	m_level.New(level);
	m_isStarted = false;
	m_startNewLevel = false;
	m_gameFinished = false;
	m_currentLevel = level;
	m_level.Update(); // Check why needed. // Temp
	m_uInterface.SetCurrentTitle(LEVEL);
	powerUpsManager.Reset();

}

void LevelsManager::StartNextLevel()
{
	if (m_currentLevel < LEVELS_LENGHT - 1)
	{
		StartNewLevel((PangLevels)((int)m_currentLevel + 1));
	}
	else
	{
		// TODO: END SCREEN
		m_uInterface.SetCurrentTitle(GAME_COMPLETE);
	}
}

void LevelsManager::Update()
{
	if (m_isStarted)
	{
		if (m_level.GetActiveBubblesLeft() <= 0)
		{
			if (m_startNewLevel)
			{
				if (!m_uInterface.AnyTitleActive())
				{
					StartNextLevel();
				}
			}
			else
			{
				m_uInterface.SetCurrentTitle(LEVEL_COMPLETE);
				m_startNewLevel = true;
			}
		}

		if (!m_gameFinished)
		{
			m_level.Update();
			m_uInterface.TimerUpdate();
		}
		
		if (powerUpsManager.IsEffectActive(HEALTH_UP))
		{
			m_attempts++;
			powerUpsManager.DeactivateEffect(HEALTH_UP);
		}

		m_uInterface.Update();	
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
	m_level.Draw();	
}

void LevelsManager::DrawUI()
{
	m_uInterface.Draw(m_currentLevel, m_attempts, !m_isStarted);
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

bool LevelsManager::IsGameFinished()
{
	return m_gameFinished;
}

PangLevels LevelsManager::GetCurrentLevel()
{
	return m_currentLevel;
}

int LevelsManager::GetTime()
{
	int min, sec;
	m_uInterface.GetCurrentTime(min, sec);
	return sec + min * 60;
}

int LevelsManager::GetAttemptsLeft()
{
	return m_attempts;
}

bool LevelsManager::AnyTitleActive()
{
	return m_uInterface.AnyTitleActive();
}
