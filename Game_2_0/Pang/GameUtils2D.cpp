#pragma once

#include "GameUtils2D.h"

int GameUtils2D::GetRandomValue(int a, int b)
{
	return rand() % (b - a) + a;
}

float GameUtils2D::GetRandomValue(float a, float b)
{
	return (float)rand() / ((b - a) + a) * a;
}
