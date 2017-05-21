#include "UI.h"



UI::UI()
{
}


UI::~UI()
{
}

void UI::New()
{
	// Load font
	m_font = al_create_builtin_font();
	m_counter = 0;
	m_timer.New({ SCREEN_WIDTH / 2, UI_TIME_POSITION_Y });
	m_currentTitle = (Titles)0;
}

void UI::Update()
{
	m_timer.Update();
	if (m_counter > 0)
	{
		m_counter--;
	}
}

void UI::Draw(PangLevels level, int attempts, bool startMsg)
{	
	//al_draw_textf(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "%i", time);
	m_timer.Draw(m_font, al_map_rgb(255, 255, 255));
	al_draw_textf(m_font, al_map_rgb(255, 255, 255), UI_ATTEMPTS_POSITION_X, UI_ATTEMPTS_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_ATTEMPTS_MESSAGE, attempts);
	if (startMsg) DrawSpaceMessage();

	if (m_counter > 0)
	{
		switch (m_currentTitle)
		{
			case GameConfig::LEVEL_COMPLETE:
				DrawLevelCompleteMessage();
				break;
			case GameConfig::GAME_OVER:
				DrawGameOverMessage();
				break;
			case GameConfig::GAME_COMPLETE:
				DrawLevelCompleteMessage();
				break;
			case GameConfig::LEVEL:
				DrawLevelMessage(level);
				break;
			default: break;
		}
	}
}

bool UI::AnyTitleActive()
{
	return m_counter > 0;
}

void UI::SetCurrentTitle(Titles title)
{
	m_currentTitle = title;
	m_counter = UI_TITLES_DURATION;
}

void UI::GetCurrentTime(int & minuts, int & seconds)
{
	minuts = m_timer.GetMinuts();
	seconds = m_timer.GetSeconds();
}

void UI::DrawSpaceMessage()
{
	al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, UI_MESSAGES_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_PRESS_SPACE_MESSAGE);
}


void UI::DrawLevelCompleteMessage()
{
	al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, UI_TITLES_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_LEVEL_COMPLETE_MESSAGE);
}

void UI::DrawGameOverMessage()
{
	al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, UI_TITLES_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_GAME_OVER_MESSAGE);
}

void UI::DrawGameCompleteMessage()
{
	al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, UI_TITLES_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_GAME_COMPLETE_MESSAGE);
}

void UI::DrawLevelMessage(int level)
{
	al_draw_text(m_font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, UI_TITLES_POSITION_Y, ALLEGRO_ALIGN_CENTRE, UI_LEVEL_MESSAGE[level]);
}
