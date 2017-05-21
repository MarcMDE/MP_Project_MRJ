#pragma once

#include "GameConfig.h"
#include "GameUtils2D.h"
//#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"
#include "Timer.h"

using namespace GameConfig;
using namespace GameUtils2D;
class UI
{
private:
	ALLEGRO_FONT* m_font;
	int m_counter;
	Timer m_timer;
	Titles m_currentTitle;

	void DrawSpaceMessage();
	void DrawLevelCompleteMessage();
	void DrawGameOverMessage();
	void DrawGameCompleteMessage();
	void DrawLevelMessage(int level);
	

public:
	UI();
	~UI();

	void New();
	void Update();
	void Draw(PangLevels level, int attempts, bool startMsg);
	bool AnyTitleActive();
	void SetCurrentTitle(Titles title);
	void GetCurrentTime(int &minuts, int &seconds);
};