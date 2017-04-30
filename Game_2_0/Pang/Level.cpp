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
		background.NewAnimation(LEVEL_BACKGROUNDANIMS[level][i], LEVEL_BACKGROUNDANIM_LENGHT[level][i], LEVEL_BACKGROUNDANIM_FRAMES[level][i], LEVEL_BACKGROUNDANIM_COLUMNS[level][i], LEVEL_BACKGROUNDANIM_DURATION[level][i], LEVEL_BACKGROUNDANIMS_POSITION[level][i], i);
	}
}
