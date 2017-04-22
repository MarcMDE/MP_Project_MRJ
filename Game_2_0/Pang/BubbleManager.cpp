#include "BubbleManager.h"
#include <stdio.h>


BubbleManager::BubbleManager()
{
}


BubbleManager::~BubbleManager()
{
}

void BubbleManager::New(int category)
{
	//*spriteSheet = (ALLEGRO_BITMAP*)malloc(sizeof(ALLEGRO_BITMAP*) * category + 1);// category 4 --> 5 different bubbles // Probable error on 2nd (ALLEGRO_BITMAP *) - malloc of an unsized pointer?
	spriteSheet = new ALLEGRO_BITMAP*[category+1];
	char **path;
	path = new char*[category + 1];
	for (int i = 0; i < category + 1; i++) path[i] = new char[25];
	
	for (int i = 0; i < category + 1; i++)
	{
		path[i][0] = 'B';
		path[i][1] = 'u';
		path[i][2] = 'b';
		path[i][3] = 'b';
		path[i][4] = 'l';
		path[i][5] = 'e';
		path[i][6] = '_';
		path[i][7] = 'S';
		path[i][8] = 'p';
		path[i][9] = 'r';
		path[i][10] = 'i';
		path[i][11] = 't';
		path[i][12] = 'e';
		path[i][13] = 'S';
		path[i][14] = 'h';
		path[i][15] = 'e';
		path[i][16] = 'e';
		path[i][17] = 't';
		path[i][18] = '_';
		path[i][19] = 48+i; // 48 = ASCII 0
		path[i][20] = '.';
		path[i][21] = 'p';
		path[i][22] = 'n';
		path[i][23] = 'g';
		path[i][24] = '\0';
	}
	
	bubblesLenght = pow(2, category);
	bubbles = (Bubble*)malloc(sizeof(Bubble)*bubblesLenght);
	
	for (int i = 0; i < category + 1; i++)  // category 4 --> 5 different bubbles
	{
		spriteSheet[i] = al_load_bitmap(path[i]);
		printf(path[i]);
		bubbles[i].New({ SCREEN_WIDTH / 2 , BUBBLES_MAX_HEIGT }, 0, 1, spriteSheet[category]); // Pas per referenica??
		bubbles[i].Deactivate();
	}

	bubbles[0].New({ SCREEN_WIDTH / 2 , BUBBLES_MAX_HEIGT}, category, 1, spriteSheet[category]);
	printf("asd\n");
}

void BubbleManager::Update()
{
	for (int i = 0; i < bubblesLenght; i++)
	{
		printf("num %i", i);
		//bubbles[i].Update();

		/*if (bubbles[i].IsHit())
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
		}*/
	}
}

void BubbleManager::Draw()
{
	for (int i = 0; i < bubblesLenght; i++)
	{
		//bubbles[i].Draw();
	}
}
