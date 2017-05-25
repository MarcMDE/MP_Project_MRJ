#include "CharInput.h"

CharInput charInput;

CharInput::CharInput()
{
	m_key = 'a';
	m_keyPressed = false;
}


CharInput::~CharInput()
{
}

void CharInput::SetPressedKey(char key)
{
	m_key = key;
	m_keyPressed = true;
}

char CharInput::GetPressedKey()
{
	return m_keyPressed;
}

bool CharInput::AnyKeyPressed()
{
	return m_keyPressed;
}

void CharInput::ClearPressedKey()
{
	m_keyPressed = false;
}
