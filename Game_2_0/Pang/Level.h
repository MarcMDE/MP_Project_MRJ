#pragma once

#include "BubbleManager.h"
#include "Background.h"

class Level
{
private:
	PangLevels level;
	Background background;
	BubbleManager * bubbleManagers;

public:
	Level();
	~Level();

	void New(PangLevels level);
	void Update();
	void Draw();
	Bubble* GetBubbles();
	int GetBubblesLenght();
	int GetActiveBubblesLeft();
	void Deinitialize();
};

