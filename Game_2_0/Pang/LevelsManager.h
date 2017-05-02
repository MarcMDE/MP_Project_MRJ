#pragma once
#include "Level.h"
#include "InputsManager.h"
#include "allegro5/allegro_font.h"

class LevelsManager
{
private:
	int m_currentLevel;
	Level m_level;
	bool m_isStarted;
	int m_attempts;
	ALLEGRO_FONT* m_font;

public:
	LevelsManager();
	//LevelsManager(int level);
	~LevelsManager();

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