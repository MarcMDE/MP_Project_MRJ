#pragma once

#include "GameUtils2D.h"

#define RAND_MAX 100

int GameUtils2D::GetRandomValue(int a, int b)
{
	return rand() % ((b+1) - a) + a;
}

float GameUtils2D::GetRandomValue(float a, float b)
{
	return (float)GetRandomValue((int)a * 10000, (int)b * 10000) / 10000;
}
