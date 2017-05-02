#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
	delete[] bubbleManagers;
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
		for (int j = 0; j < LEVEL_BUBBLEMANAGERS_LENGHT[level]; j++)
		{
			bubbleManagers[i].New(LEVEL_BUBBLEMANAGERS_CAT[level][j]);
		}
	}
}

void Level::Update()
{
	background.Update();

	for (int i = 0; i < LEVEL_BUBBLEMANAGERS_LENGHT[level]; i++)
	{
		bubbleManagers[i].Update();
	}
}

void Level::Draw()
{
	background.Draw();

	for (int i = 0; i < LEVEL_BUBBLEMANAGERS_LENGHT[level]; i++)
	{
		bubbleManagers[i].Draw();
	}
}

Bubble * Level::GetBubbles()
{
	return bubbleManagers[level].GetBubbles();
}

int Level::GetBubblesLenght()
{
	return bubbleManagers[level].GetBubblesLenght();
}

int Level::GetActiveBubblesLeft()
{
	return bubbleManagers[level].GetActiveBubblesLeft();
}
