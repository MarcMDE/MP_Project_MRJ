#include "BubbleManager.h"



BubbleManager::BubbleManager()
{
}


BubbleManager::~BubbleManager()
{
}

void BubbleManager::New(int category)
{
	*spriteSheet = (ALLEGRO_BITMAP*)malloc(sizeof(ALLEGRO_BITMAP*) * category + 1); // category 4 --> 5 different bubbles
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
