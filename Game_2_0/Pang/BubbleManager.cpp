#include "BubbleManager.h"
#include <stdio.h>


void BubbleManager::Deinitialize()
{
	delete[]bubbles;
	delete[]newBubbles;
	//delete[]spriteSheet;
}

BubbleManager::BubbleManager()
{
}


BubbleManager::~BubbleManager()
{
	Deinitialize();
}

void BubbleManager::New(int category)
{
	//*spriteSheet = (ALLEGRO_BITMAP*)malloc(sizeof(ALLEGRO_BITMAP*) * category + 1);// category 4 --> 5 different bubbles // Probable error on 2nd (ALLEGRO_BITMAP *) - malloc of an unsized pointer?
	spriteSheet = new ALLEGRO_BITMAP*[category+1];
	
	bubblesLenght = pow(2, category);
	//bubbles = (Bubble*)malloc(sizeof(Bubble)*bubblesLenght);
	bubbles = new Bubble[bubblesLenght];
	newBubbles = new bool[bubblesLenght];

	for (int i = 0; i < category + 1; i++)  // category 4 --> 5 different bubbles
	{
		spriteSheet[i] = al_load_bitmap(BUBBLES_SPRITE[i]);
		//bubbles[i].New({ SCREEN_WIDTH / 2 , BUBBLES_MAX_HEIGT }, 0, 1, spriteSheet[i]); // Pas per referenica??
	}

	for (int i = 0; i < bubblesLenght; i++)
	{
		bubbles[i].Deactivate();
		newBubbles[i] = false;
	}

	bubbles[0].New({ SCREEN_WIDTH / 2 , BUBBLES_MAX_HEIGT}, category, 1, spriteSheet[category]);
	activeBubbles = 1;
}

Bubble * BubbleManager::GetBubbles()
{
	return bubbles;
}

int BubbleManager::GetBubblesLenght()
{
	return bubblesLenght;
}

int BubbleManager::GetActiveBubblesLeft()
{
	return activeBubbles;
}

void BubbleManager::Update()
{
	int j;
	for (int i = 0; i < bubblesLenght; i++)
	{
		if (!newBubbles[i])
		{
			bubbles[i].Update(!powerUpsManager.IsEffectActive(PARALYSIS));
		}

		if ((bubbles[i].IsHit() || (powerUpsManager.IsEffectActive(EXPLOSIVE_DIARREA)) && newBubbles[i] == false) && bubbles[i].IsActive()) // Bubble Destoyed
		{
			audioManager.PlaySound(PLOP);

			powerUpsManager.SpawnRandomPowerUp(bubbles[i].GetPosition()); // Spawn Power Up

			if (bubbles[i].GetCategory() > 0)
			{
				j = 0;
				while (j < bubblesLenght && bubbles[j].IsActive())
				{
					j++;
				}
				bubbles[j].New({ bubbles[i].GetPosition().x - BUBBLES_RADIUS[bubbles[i].GetCategory() - 1], bubbles[i].GetPosition().y }, bubbles[i].GetCategory() - 1,
					-1, spriteSheet[bubbles[i].GetCategory() - 1]);
				newBubbles[j] = true;
				bubbles[i].New({ bubbles[i].GetPosition().x + BUBBLES_RADIUS[bubbles[i].GetCategory() - 1], bubbles[i].GetPosition().y }, bubbles[i].GetCategory() - 1,
					1, spriteSheet[bubbles[i].GetCategory() - 1]);

				activeBubbles++;
				if (powerUpsManager.IsEffectActive(PARALYSIS)) bubbles[j].Update(true);
			}
			else
			{
				bubbles[i].Deactivate();
				activeBubbles--;
			}
		}
	}

	for (int i = 0; i < bubblesLenght; i++)
	{
		newBubbles[i] = false;
	}
}

void BubbleManager::Draw()
{
	for (int i = 0; i < bubblesLenght; i++)
	{
		bubbles[i].Draw();
	}
}
