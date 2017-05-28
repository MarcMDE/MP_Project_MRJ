#pragma once

#include "GameConfig.h"
#include <iostream>

using namespace GameConfig;
using namespace std;

class Highscore
{
private:
	char m_name[HS_NAME_LENGHT];
	int m_score;
	
public:
	Highscore();
	~Highscore();

	void New();
	char* GetName();
	int GetScore();
	void SetScore(int score);
	void SetScore(PangLevels level, int seconds, int attemptsLeft);
	void SetName(char name[HS_NAME_LENGHT]);
};

