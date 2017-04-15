#include "Pang.h"
#include <stdio.h>


Pang::Pang()
{
}

Pang::~Pang()
{
}

void Pang::Initialize()
{
	player.New();
	isPaused = false;
	pauseSprite.New({ SCREEN_WIDTH, SCREEN_HEIGHT }, al_map_rgba( 120, 120, 120, 25));
}

void Pang::Update()
{
	/*
	anim.Update();

	if (input.IsKeyDown((int)ALLEGRO_KEY_A)) auxPosition.x-=2;
	else if (input.IsKeyDown((int)ALLEGRO_KEY_D)) auxPosition.x+=2;
	if (input.IsKeyDown((int)ALLEGRO_KEY_W)) auxPosition.y-=2;
	else if (input.IsKeyDown((int)ALLEGRO_KEY_S)) auxPosition.y+=2;

	aBox.UpdatePosition(auxPosition);
	if (aBox.CheckAABBsCollision(bBox))
	{
		printf("a-b box Collision\n");
	}
	if (aBox.CheckAABBCircleCollision(aCirc))
	{
		printf("a-a box-circ Collisions\n");
	}
	*/

	if (input.IsKeyPressed(ALLEGRO_KEY_P)) isPaused = !isPaused;

	if (!isPaused)
	{
		player.Update();
	}
}

void Pang::Draw()
{
	player.Draw();

	if (isPaused)
	{
		pauseSprite.Draw({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
	}
}
