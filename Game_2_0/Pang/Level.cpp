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

	background.New(al_load_bitmap(LEVEL_01_BACKGROUND), LEVEL_01_BACKGROUNDANIMS_LENGHT);
	background.NewAnimation()
}
