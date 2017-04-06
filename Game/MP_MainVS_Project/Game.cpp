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

	// Backgrounds, + bitmap scene
	scenes[currentLevel] = Scene();
	//player = Player();

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