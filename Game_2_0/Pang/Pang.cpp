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
	test.New(al_load_bitmap("explosion2.png"), 9, 9, 1);
}

void Pang::Update()
{
	test.Update();
}

void Pang::Draw()
{
	test.Draw({ SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, false);
}
