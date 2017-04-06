#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize(int level)
{
	currentLevel = level;
	player = Player(spawnPosition, { 5, 5 }, { 0.1f, 0.1f }, al_load_bitmap("player.jpg"));
	// Backgrounds, + bitmap scene
	scenes[currentLevel] = Scene();

}

void Game::Update()
{
	// GAME UPDATE
	player.Update();
	scenes[currentLevel].Update();
}

void Game::Draw()
{
	// GAME DRAW
	player.Draw();
	scenes[currentLevel].DrawUpdate();
}