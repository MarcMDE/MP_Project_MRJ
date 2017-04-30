#include "GameUtils2D.h"

void GameUtils2D::CharSringCpy(char a[], char b[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		b[i] = a[i];
	}
}

void GameUtils2D::CharSringCpy(char a[], char b[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		b[i] = a[i];
	}
}
