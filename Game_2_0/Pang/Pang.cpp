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
	test.Ini(al_load_bitmap("explosion2.png"), 9, 9, 1);
}

void Pang::Update()
{
	test.Update();
}

void Pang::Draw()
{
	test.Draw({ SCREEN_WIDTH, SCREEN_HEIGHT}, false);
}
