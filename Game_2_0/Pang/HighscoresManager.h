#pragma once

#include "Highscore.h"
#include "GameConfig.h"
#include <iostream>
#include <fstream>
#include "CharInput.h"
#include "InputsManager.h"
#include "Sprite.h"
#include "allegro5\allegro_font.h"
#include <list>

using namespace GameConfig;
using namespace std;

class HighscoresManager
{
private:
	//Highscore m_highscores[HS_LENGHT];
	list<Highscore> m_highscoresList;
	ALLEGRO_FONT *m_font;
	Sprite m_bgSprite;
	Sprite m_enterNameSprite;
	char m_newName[HS_NAME_LENGHT];
	int m_newScore;
	int m_newPosition;
	int m_newNameIndex;

	int CalculateScore(PangLevels level, int seconds, int attemptsLeft);

public:
	HighscoresManager();
	~HighscoresManager();
	
	void New();
	void ReadHighscores();
	bool IsHighscore(PangLevels level, int seconds, int attemptsLeft);
	bool EnterName(bool anyTitleActive);
	void AddNewHighscore();
	void DrawHighscores();
	void DrawEnterName(bool anyTitleActive);
	void SaveHighscores();
};

