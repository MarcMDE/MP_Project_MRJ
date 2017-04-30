#include "Pang.h"
#include <stdio.h>


Pang::Pang()
{
}

Pang::~Pang()
{
	player.~Player();
	background.~Background();
	bubbleManager.~BubbleManager();
	pauseSprite.~Sprite();
}

void Pang::Initialize()
{
	player.New(0);
	background.New(al_load_bitmap("main_background.png"), 2);
	background.NewAnimation(al_load_bitmap("clowd.png"), { 128, 128 }, 4, 2, 20, { 200, 150 }, 0);
	background.NewAnimation(al_load_bitmap("solet.png"), { 512, 512 }, 4, 2, 10, { SCREEN_WIDTH - 150, 150 }, 1);
	bubbleManager.New(2);

	//bI = al_load_bitmap("SpriteSheet_4.png"); // Temp
	//b.New({ SCREEN_WIDTH / 2, 150 }, 4, 1, bI); // Temp


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
		player.CheckBubblesCollision(bubbleManager.GetBubbles(), bubbleManager.GetBubblesLenght());
		player.Update();
		background.Update();
		bubbleManager.Update();
		
		//b.Update(); // Temp
	}
}

void Pang::Draw()
{
	background.Draw();
	player.Draw();
	bubbleManager.Draw();
	//b.Draw(); // Temp

	if (isPaused)
	{
		pauseSprite.Draw({SCREEN_WIDTH/2, SCREEN_HEIGHT/2});
	}
}
