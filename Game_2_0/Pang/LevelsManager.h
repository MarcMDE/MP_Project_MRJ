#pragma once
#include "Level.h"
#include "InputsManager.h"

class LevelsManager
{
private:
	int m_currentLevel;
	Level m_level;
	bool isStarted;

public:
	LevelsManager();
	LevelsManager(int level);
	~LevelsManager();

	void RestartLevel();
	void StartNewLevel(int level);
	void Update();
	void Draw();
	Bubble* GetBubbles();
	int GetBubblesLenght();
};