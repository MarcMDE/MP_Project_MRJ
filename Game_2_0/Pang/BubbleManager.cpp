#include "BubbleManager.h"



BubbleManager::BubbleManager()
{
}


BubbleManager::~BubbleManager()
{
}

void BubbleManager::New(int category)
{
	*spriteSheet = (ALLEGRO_BITMAP*)malloc(sizeof(ALLEGRO_BITMAP*) * category + 1); // category 4 --> 5 different bubbles // Probable error on 2nd (ALLEGRO_BITMAP *) - malloc of an unsized pointer?
	char path[25] = "bubble_spritesheet_C.png";
	bubbles = (Bubble*)malloc(sizeof(Bubble)*pow(2, category));
	
	for (int i = 0; i < category + 1; i++)  // category 4 --> 5 different bubbles
	{
		path[20] = i;
		spriteSheet[i] = al_load_bitmap(path);
	
		bubbles[i].Deactivate();
	}

	bubbles[0].New({ SCREEN_WIDTH / 2 , BUBBLES_MAX_HEIGT}, category, 1, spriteSheet[category]);
}

void BubbleManager::Update()
{
	for (int i = 0; i < bubblesLenght; i++)
	{
		if (bubbles[i].IsHit())
		{
			if (bubbles[i].GetCategory() > 0)
			{
				int j = 0;
				while (j < bubblesLenght && bubbles[j].IsActive())
				{
					j++;
				}

				bubbles[j].New({ bubbles[i].GetPosition().x - BUBBLES_RADIUS[bubbles[i].GetCategory() - 1], bubbles[i].GetPosition().y }, bubbles[i].GetCategory() - 1, 
					-1, spriteSheet[bubbles[i].GetCategory() - 1]);
				bubbles[i].New({ bubbles[i].GetPosition().x - BUBBLES_RADIUS[bubbles[i].GetCategory() - 1], bubbles[i].GetPosition().y }, bubbles[i].GetCategory() - 1,
					-1, spriteSheet[bubbles[i].GetCategory() - 1]);
			}
			else bubbles[i].Deactivate();
		}
	}

	for (int i = 0; i < bubblesLenght; i++)
	{
		bubbles[i].Update();
	}
}

void BubbleManager::Draw()
{
	for (int i = 0; i < bubblesLenght; i++)
	{
		bubbles[i].Draw();
	}
}
