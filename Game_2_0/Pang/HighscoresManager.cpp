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
	m_highscoresList.clear();
}

void HighscoresManager::New()
{
	m_bgSprite.New(al_load_bitmap(HS_BG_SPRITE));
	m_enterNameSprite.New(al_load_bitmap(HS_ENTERNAME_SPRITE));

	m_font = al_create_builtin_font();
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
		Highscore aux;
		while (!readF.eof() && i < HS_LENGHT)
		{
			//aux = new Highscore();

			readF.getline(auxName, HS_NAME_LENGHT);
			readF >> auxScore;

			aux.SetName(auxName);
			aux.SetScore(auxScore);

			m_highscoresList.emplace_back(aux);
			
			//m_highscores[i].SetName(auxName);
			//m_highscores[i].SetScore(auxScore);
			i++;

			printf("READD\n");

			readF.ignore();
			readF.ignore();
		}

		readF.close();
	}

	/*for (i; i < HS_LENGHT; i++)
	{
		m_highscores[i].SetName("XXXXXX");
		m_highscores[i].SetScore(0);
	}*/
}

bool HighscoresManager::IsHighscore(PangLevels level, int seconds, int attemptsLeft)
{
	m_newScore = CalculateScore(level, seconds, attemptsLeft);
	int i = 0;

	//while (i < HS_LENGHT && m_newScore < m_highscores[i].GetScore())
	//{
	//	i++;
	//}

	list<Highscore>::iterator it = m_highscoresList.begin();

	while (it != m_highscoresList.end() && m_newScore < it->GetScore())
	{
		i++;
		it++;
	}

	if (i != HS_LENGHT)
	{
		m_newPosition = i;
		m_newNameIndex = 0;
		for (int i = 0; i < HS_NAME_LENGHT - 1; i++) m_newName[i] = ' ';
		//charInput.SetActive(true);
		return true;
	}
	return false;
}

bool HighscoresManager::EnterName(bool anyTitleActive)
{
	bool nameEntered = true;

	if (!anyTitleActive)
	{
		if (m_newNameIndex < HS_NAME_LENGHT - 1)
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
			nameEntered = false;
		}
		charInput.SetActive(!nameEntered);
	}
	else
	{
		nameEntered = false;
		charInput.SetActive(false);
	}

	return nameEntered;
}

void HighscoresManager::AddNewHighscore()
{
	if (m_newPosition != -1)
	{
		//list<Highscore>::iterator it = m_highscoresList.begin();
		list<Highscore>::iterator it = m_highscoresList.begin();

		/*int i = HS_LENGHT - 2;

		for (i; i >= m_newPosition; i--)
		{
			m_highscores[i + 1].SetName(m_highscores[i].GetName());
			m_highscores[i + 1].SetScore(m_highscores[i].GetScore());
		}

		m_highscores[m_newPosition].SetName(m_newName);
		m_highscores[m_newPosition].SetScore(m_newScore);*/

		int i = 0;
		for (i; i < m_newPosition; i++)
		{
			it++;
		}
		
		if (i == 0)
		{
			m_highscoresList.emplace_front();
			it = m_highscoresList.begin();
		}
		else
		{
			//it--;
			it = m_highscoresList.emplace(it);
		}

		if (i >= 9) m_highscoresList.pop_back();

		it->SetName(m_newName);
		it->SetScore(m_newScore);
	}

}

void HighscoresManager::DrawHighscores()
{
	m_bgSprite.Draw(HS_BG_POSITION_X, HS_BG_POSITION_Y);
	
	list<Highscore>::iterator it = m_highscoresList.begin();

	int i = 0;
	for (it; it != m_highscoresList.end(); it++)
	{
		al_draw_text(m_font, al_map_rgb(255, 255, 255), HS_BG_POSITION_X + HS_OFFSET_X, HS_BG_POSITION_Y + HS_OFFSET_Y + HS_LINESPACE * i,
			ALLEGRO_ALIGN_CENTER, it->GetName());

		al_draw_textf(m_font, al_map_rgb(255, 255, 255), HS_BG_POSITION_X + HS_OFFSET_X + HS_SCORESPACE, HS_BG_POSITION_Y + HS_OFFSET_Y + HS_LINESPACE * i,
			ALLEGRO_ALIGN_CENTER, "%i", it->GetScore());

		i++;
	}


	/*for (int i = 0; i < HS_LENGHT; i++)
	{
		al_draw_text(m_font, al_map_rgb(255, 255, 255), HS_BG_POSITION_X + HS_OFFSET_X, HS_BG_POSITION_Y + HS_OFFSET_Y + HS_LINESPACE * i,
			ALLEGRO_ALIGN_CENTER, m_highscores[i].GetName());

		al_draw_textf(m_font, al_map_rgb(255, 255, 255), HS_BG_POSITION_X + HS_OFFSET_X + HS_SCORESPACE, HS_BG_POSITION_Y + HS_OFFSET_Y + HS_LINESPACE * i,
			ALLEGRO_ALIGN_CENTER, "%i",  m_highscores[i].GetScore());
	}*/
}

void HighscoresManager::DrawEnterName(bool anyTitleActive)
{
	if (!anyTitleActive)
	{
		m_enterNameSprite.Draw(HS_ENTERNAME_POSITION_X, HS_ENTERNAME_POSITION_Y);
		al_draw_textf(m_font, al_map_rgb(255, 255, 255), HS_ENTERNAME_POSITION_X + HS_ENTERNAME_OFFSET_X, HS_ENTERNAME_POSITION_Y + HS_ENTERNAME_OFFSET_Y,
		ALLEGRO_ALIGN_CENTER, m_newName);
	}
}

void HighscoresManager::SaveHighscores()
{
	ofstream writeF;

	writeF.open(HS_FILENAME);
	
	if (writeF.is_open())
	{
		
		list<Highscore>::iterator it = m_highscoresList.begin();
		
		for (it; it != m_highscoresList.end(); it++)
		{
			writeF << it->GetName() << endl;
			writeF << it->GetScore() << endl;
			printf("ASD\n");
		}

		writeF.close();
	}
}
