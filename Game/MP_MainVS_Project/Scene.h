#ifndef SCENE_H
#define SCENE_H
#include "Block.h"

enum BlockTypes {STONE = 0, ICE};

class Scene
{
private:
	const static int blockTypesLenght = 2;
	Block **blocks = new Block*[blockTypesLenght];
	Sprite blockSprites[blockTypesLenght];
	int blocksLengt[blockTypesLenght];

	Sprite *backgrounds;
	int backgroundsLenght;

	//Trap *traps
	//UI ui
	
	void UpdateBlocks();
	void DrawBlocks();
	void DrawBackgrounds();

public:
	Scene();
	Scene(ALLEGRO_BITMAP * sceneBitmap, Sprite *backgrounds, int backgroundsLenght);
	Scene(Sprite *backgrounds, int backgroundsLenght);
	~Scene();
	void Update();
	void DrawUpdate();
};

#endif 