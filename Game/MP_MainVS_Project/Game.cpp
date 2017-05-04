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
	player = Player(spawnPosition, { 4, 10 }, { 0.01f, 10.0f }, al_load_bitmap("player.jpeg"));
	//scenes[0] = Scene(al_load_bitmap("bg.png"), 1);
	bg = al_load_bitmap("bg.jpg");
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
	al_draw_bitmap(bg, 0, 0, 0);
	// GAME DRAW
	player.Draw();
	//scenes[0].DrawUpdate();
	//scenes[currentLevel].DrawUpdate();
}

void Game::SetKeyDown(char key, bool isKeyDown)
{
	this->key = key;
	this->isKeyDown = isKeyDown;
}
