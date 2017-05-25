#include "HighscoresManager.h"



int HighscoresManager::CalculateScore(PangLevels level, int seconds, int attemptsLeft)
{
	return ((int)level + 1) * 1000 - seconds + attemptsLeft * 100;
}

HighscoresManager::HighscoresManager()
{
}


HighscoresManager::~HighscoresManager()
{
}

void HighscoresManager::ReadHighscores()
{
	ifstream readF;
	char auxName[HS_NAME_LENGHT];
	int auxScore;

	readF.open(HS_FILENAME);

	int i = 0;
	
	if (readF.is_open())
	{

		while (!readF.eof() && i < HS_LENGHT)
		{
			readF.getline(auxName, HS_NAME_LENGHT);
			readF >> auxScore;

			m_highscores[i].SetName(auxName);
			m_highscores[i].SetScore(auxScore);
			i++;
		}

		readF.close();
	}

	for (i; i < HS_LENGHT; i++)
	{
		m_highscores[i].SetName(HS_DEFAULT_NAME);
		m_highscores[i].SetScore(0);
	}
}

bool HighscoresManager::IsHighscore(PangLevels level, int seconds, int attemptsLeft)
{
	m_newScore = CalculateScore(level, seconds, attemptsLeft);
	
	int i = 0;
	while (i < HS_LENGHT && m_newScore < m_highscores[i].GetScore())
	{
		i++;
	}

	if (i != HS_LENGHT)
	{
		m_newPosition = i;
		return true;
	}
	return false;
}

bool HighscoresManager::EnterName()
{
	if (m_newNameIndex < HS_NAME_LENGHT)
	{	
		if (input.IsKeyPressed(KEY_CONFIRM)) m_newNameIndex = HS_NAME_LENGHT;
		else if (input.IsKeyPressed(KEY_ERASE) && m_newNameIndex > 0)
		{
			m_newNameIndex--;
			m_newName[m_newNameIndex] = ' ';
		}
		else if (charInput.AnyKeyPressed())
		{
			m_newName[m_newNameIndex] = charInput.GetPressedKey();
			m_newNameIndex++;
		}
	}	

	return true;
}

void HighscoresManager::AddNewHighscore(PangLevels level, int seconds, int attemptsLeft, int position, string newName)
{
	if (position != -1)
	{
		int i = HS_LENGHT - 2;
		for (i = 0; i > position; i--)
		{
			m_highscores[i + 1].SetName(m_highscores[i].GetName());
			m_highscores[i + 1].SetScore(m_highscores[i].GetScore());
		}

		m_highscores[position].SetName(newName);
		m_highscores[position].SetScore(CalculateScore(level, seconds, attemptsLeft));
	}
}
