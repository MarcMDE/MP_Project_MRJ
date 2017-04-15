#include "InputsManager.h"

InputsManager input;

InputsManager::InputsManager()
{
	Reset();
}


InputsManager::~InputsManager()
{
}

void InputsManager::Reset()
{
	for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
	{
		keysDown[i] = false;
	}

	keyPressed = 0;
	isKeyPressed = false;
	keysCounter = 0;
}

bool InputsManager::IsKeyPressed(int allegroKeyCode) const
{
	return (isKeyPressed && keyPressed == allegroKeyCode);
}

bool InputsManager::IsKeyDown(int allegroKeyCode) const
{
	return (IsAnyKeyDown() && keysDown[allegroKeyCode]);
}

bool InputsManager::IsAnyKeyDown() const
{
	return keysCounter > 0;
}

void InputsManager::SetPressedKey(int allegroKeyCode)
{
	if (!keysDown[allegroKeyCode])
	{
		isKeyPressed = true;
		keysCounter++;

		keyPressed = allegroKeyCode;
		keysDown[allegroKeyCode] = true;
	}
}

void InputsManager::SetReleasedKey(int allegroKeyCode)
{
	keysDown[allegroKeyCode] = false;
	keysCounter--;
}

void InputsManager::ClearPressedKey()
{
	keyPressed = 0;
	isKeyPressed = false;
}
