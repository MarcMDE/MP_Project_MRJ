#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	// Replace Initialize -> Constructor
	player.Initialize({ spawnPosition, 0, 0 }, friction);
	//background.LoadTexture("bg.jpg");
}

void Game::Update()
{
	// GAME UPDATE
	player.Update();
}

void Game::Draw()
{
	// GAME DRAW
	//background.Draw({ 0, 0 });
	player.Draw();
}