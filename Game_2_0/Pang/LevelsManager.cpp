#include "LevelsManager.h"



LevelsManager::LevelsManager()
{
}

LevelsManager::LevelsManager(int level)
{
	m_currentLevel = level;
	m_level.New(level);
	isStarted = false;
}


LevelsManager::~LevelsManager()
{
}

void LevelsManager::RestartLevel()
{
	StartNewLevel(m_currentLevel);
}

void LevelsManager::StartNewLevel(int level)
{
	m_level.New(level);
	isStarted = false;
	level = m_currentLevel;
}

void LevelsManager::Update()
{
	if (isStarted)
	{
		m_level.Update();
	}
	else if (input.IsKeyPressed(ALLEGRO_KEY_SPACE))
	{
		isStarted = true;
	}
}

void LevelsManager::Draw()
{
	m_level.Draw();
}

Bubble * LevelsManager::GetBubbles()
{
	return m_level.GetBubbles();
}

int LevelsManager::GetBubblesLenght()
{
	return m_level.GetBubblesLenght();
}
