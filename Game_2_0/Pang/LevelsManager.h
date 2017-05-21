#pragma once
#include "Level.h"
#include "InputsManager.h"
#include "UI.h"


class LevelsManager
{
private:
	PangLevels m_currentLevel;
	Level m_level;
	bool m_isStarted;
	int m_attempts;
	UI uInterface;

public:
	LevelsManager();
	LevelsManager(PangLevels level);
	~LevelsManager();

	void New(PangLevels level);
	void RestartLevel();
	void StartNewLevel(int level);
	void StartNextLevel();
	void Update();
	void Draw();
	bool GetIsStarted();
	Bubble* GetBubbles();
	int GetBubblesLenght();
	int GetActiveBubblesLeft();
};