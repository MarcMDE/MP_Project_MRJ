#include "Game.h"
#include <stdio.h>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize(int level)
{
	currentLevel = level;
	player = Player(spawnPosition, { 5, 5 }, { 0.1f, 0.1f }, al_load_bitmap("player.jpeg"));
	//tst = al_load_bitmap("player.jpeg");
	// Backgrounds, + bitmap scene
	//scenes[currentLevel] = Scene();
	printf("playerPos%f\n", player.GetPos().x);
}

void Game::Update()
{
	// GAME UPDATE
	//player.Update();
	//scenes[currentLevel].Update();
}

void Game::Draw()
{
	//al_draw_bitmap(tst, 20, 20, 0);
	// GAME DRAW
	player.Draw();
	//scenes[currentLevel].DrawUpdate();
}