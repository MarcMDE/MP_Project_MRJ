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
	player = Player(spawnPosition, { 1, 1 }, { 0.0005f, 10.0f }, al_load_bitmap("player.jpeg"));
	//tst = al_load_bitmap("player.jpeg");
	// Backgrounds, + bitmap scene
	//scenes[currentLevel] = Scene();
}

void Game::Update()
{
	// GAME UPDATE
	player.Update(key, isKeyDown);
	//scenes[currentLevel].Update();
}

void Game::Draw()
{
	//al_draw_bitmap(tst, 20, 20, 0);
	// GAME DRAW
	player.Draw();
	//scenes[currentLevel].DrawUpdate();
}

void Game::SetKeyDown(char key, bool isKeyDown)
{
	this->key = key;
	this->isKeyDown = isKeyDown;
}
