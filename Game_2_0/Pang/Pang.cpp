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
	bBox.New({ 200, SCREEN_HEIGHT / 2 }, { 50, 50 });
	aCirc.New({ 300, SCREEN_HEIGHT / 2 }, 25);
	bCirc.New({ 400, SCREEN_HEIGHT / 2 }, 25);
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
