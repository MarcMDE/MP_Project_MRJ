#pragma once

#include "Highscore.h"
#include "GameConfig.h"
#include <iostream>
#include <fstream>
#include "CharInput.h"
#include "InputsManager.h"

using namespace GameConfig;

class HighscoresManager
{
private:
	Highscore m_highscores[HS_LENGHT];
	string m_newName;
	int m_newScore;
	int m_newPosition;
	int m_newNameIndex;

	int CalculateScore(PangLevels level, int seconds, int attemptsLeft);

public:
	HighscoresManager();
	~HighscoresManager();
	
	void ReadHighscores();
	bool IsHighscore(PangLevels level, int seconds, int attemptsLeft);
	bool EnterName();
	void AddNewHighscore(PangLevels level, int seconds, int attemptsLeft, int position, string newName);
	void Draw();
	void SaveHighscores();


};

