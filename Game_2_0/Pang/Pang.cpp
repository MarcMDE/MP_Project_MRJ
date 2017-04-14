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
	anim.New(al_load_bitmap("explosion2.png"), 9, 9, 1);
	aBox.New({ 100, SCREEN_HEIGHT / 2 }, { 50, 50 });
	bBox.New({ 230, SCREEN_HEIGHT / 2 }, { 50, 50 });
	aCirc.New({ 120, SCREEN_HEIGHT / 2 }, 25);
	bCirc.New({ 320, SCREEN_HEIGHT / 2 }, 25);

	if (aBox.CheckAABBsCollision(bBox)) printf("a-b box Collision\n");
	if (aCirc.CheckCirclesCollision(bCirc)) printf("a-b circ Collision\n");
	if (aBox.CheckAABBCircleCollision(aCirc)) printf("a-a box-circ Collisions\n");
}

void Pang::Update()
{
	anim.Update();
}

void Pang::Draw()
{
	anim.Draw({ SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, false);
	aBox.DebugDraw();
	bBox.DebugDraw();
	aCirc.DebugDraw();
	bCirc.DebugDraw();
}
