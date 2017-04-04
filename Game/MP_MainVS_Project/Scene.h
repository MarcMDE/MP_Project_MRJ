#pragma once
#include "Block.h"

class Scene
{
private:
	Block *blocks;
	//Trap *traps
	//UI ui
	Sprite background_01;
	Sprite background_02;
	Sprite foreground;

public:
	Scene();
	~Scene();
	void UpdateBackgrounds();
	void UpdateBlocks();
	void UpdateTraps();
	void UpdateUI();
};

