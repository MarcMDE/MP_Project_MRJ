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
	bool m_startNewLevel;
	int m_attempts;
	UI m_uInterface;
	bool m_gameFinished;

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
	void DrawUI();
	bool GetIsStarted();
	Bubble* GetBubbles();
	int GetBubblesLenght();
	int GetActiveBubblesLeft();
	bool IsGameFinished();
	PangLevels GetCurrentLevel();
	int GetTime();
	int GetAttemptsLeft();
	bool AnyTitleActive();
};