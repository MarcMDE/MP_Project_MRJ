#include "Scene.h"



Scene::Scene()
{
}

Scene::Scene(ALLEGRO_BITMAP * sceneBitmap, Sprite *backgrounds, int backgroundsLenght)
{
	this->backgrounds = backgrounds;
	this->backgroundsLenght = backgroundsLenght;

	// Read bitmap & set everythings position
	//block[0] = new Block[blocksLenght[0]];
}

Scene::Scene(Sprite *backgrounds, int backgroundsLenght)
{
	this->backgrounds = backgrounds;
	this->backgroundsLenght = backgroundsLenght;
}


Scene::~Scene()
{
}

void Scene::Update()
{
}

void Scene::DrawUpdate()
{
}

void Scene::UpdateBlocks()
{
	for (int i = 0; i < blockTypesLenght; i++)
	{
		for (int j = 0; j < blocksLengt[i]; j++)
		{
			blocks[i][j].Update();
		}
	}
}

void Scene::DrawBlocks()
{
	for (int i = 0; i < blockTypesLenght; i++)
	{
		for (int j = 0; j < blocksLengt[i]; j++)
		{
			blocks[i][j].DrawUpdate(blockSprites[i]);
		}
	}
}

void Scene::DrawBackgrounds()
{
	for (int i=0; i<backgroundsLenght; i++) backgrounds[i].Draw({ 0, 0 });
}
