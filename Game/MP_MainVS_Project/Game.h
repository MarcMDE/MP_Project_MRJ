#pragma once
#include "Player.h"
#include "GameUtils.h"
#include "Scene.h"

const Vector2 SCREEN_LENGHT = { 640, 480 };
const Vector2 SCREEN_START = { 0, 0 };

class Game
{
	private:
		static const int levelsLenght = 3;
		const int blocksWidth = 64;
		const int groundY = SCREEN_LENGHT.y - blocksWidth * 1;
		const Vector2 spawnPosition = { (float)blocksWidth * 2, (float)blocksWidth * 3.17f };
		const Vector2 friction = { 0.0005f, 0.0005f };

		int currentLevel;
		Player player;
		Scene scenes[levelsLenght];

	public:
		Game();
		~Game();
		void Initialize(int level);
		void Update();
		void Draw();
};

