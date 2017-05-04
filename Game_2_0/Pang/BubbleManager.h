#pragma once
#include "Bubble.h"
#include "GameConfig.h"
#include "GameUtils2D.h"
#include <math.h>
#include <string>

using namespace GameConfig;
using namespace GameUtils2D;
using namespace std;

class BubbleManager
{
private:
	
	int bubblesLenght;
	Bubble * bubbles;
	ALLEGRO_BITMAP **spriteSheet;
	bool * newBubbles;
	int activeBubbles;

public:
	BubbleManager();
	~BubbleManager();

	void New(int category);

	Bubble* GetBubbles();
	int GetBubblesLenght();
	int GetActiveBubblesLeft();

	void Update();
	void Draw();
};

