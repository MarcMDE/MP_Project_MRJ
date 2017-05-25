#pragma once

#include "GameConfig.h"
#include <iostream>

using namespace GameConfig;
using namespace std;

class Highscore
{
private:
	string m_name;
	int m_score;
	
public:
	Highscore();
	~Highscore();

	void New();
	string GetName();
	int GetScore();
	void SetScore(int score);
	void SetScore(PangLevels level, int seconds, int attemptsLeft);
	void SetName(string name);
};

