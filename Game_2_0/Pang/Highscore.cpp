#include "Highscore.h"



Highscore::Highscore()
{
}


Highscore::~Highscore()
{
}

void Highscore::New()
{
	for (int i = 0; i < HS_NAME_LENGHT - 1; i++)
	{
		m_name[i] = 'X';
	}

	m_score = 0;
}

char* Highscore::GetName()
{
	return m_name;
}

int Highscore::GetScore()
{
	return m_score;
}

void Highscore::SetScore(int score)
{
	m_score = score;
}

void Highscore::SetScore(PangLevels level, int seconds, int attemptsLeft)
{
	m_score = ((int)level + 1) * 1000 - seconds + attemptsLeft * 100;
}

void Highscore::SetName(char name[HS_NAME_LENGHT])
{
	for (int i = 0; i < HS_NAME_LENGHT; i++)
	{
		m_name[i] = name[i];
	}
	//m_name[HS_NAME_LENGHT - 1] = '\n';
}

