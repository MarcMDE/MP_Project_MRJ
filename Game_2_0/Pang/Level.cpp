#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::New(int level)
{
	this->level = level;
	

	background.New(al_load_bitmap(LEVEL_BACKGROUND[level]), LEVEL_BACKGROUNDANIMS_LENGHT);
	for (int i = 0; i < LEVEL_BACKGROUNDANIMS_LENGHT; i++)
	{
		background.NewAnimation(al_load_bitmap(LEVEL_BACKGROUNDANIMS[level][i]), LEVEL_BACKGROUNDANIM_LENGHT[level][i], LEVEL_BACKGROUNDANIM_FRAMES[level][i],
			LEVEL_BACKGROUNDANIM_COLUMNS[level][i], LEVEL_BACKGROUNDANIM_DURATION[level][i], LEVEL_BACKGROUNDANIM_POSITION[level][i], i);
	}

	bubbleManagers = new BubbleManager[LEVEL_BUBBLEMANAGERS_LENGHT[level]];

	for (int i = 0; i < LEVEL_BUBBLEMANAGERS_LENGHT[level]; i++)
	{
		// Init bubblemanagers	
	}
}

void Level::Update()
{
	background.Update();
}

void Level::Draw()
{
	background.Draw();
}
