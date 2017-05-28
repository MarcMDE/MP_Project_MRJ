#include "CharInput.h"

CharInput charInput;

CharInput::CharInput()
{
	m_key = 'a';
	m_keyPressed = false;
	m_isActive = false;
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
	return m_key;
}

bool CharInput::AnyKeyPressed()
{
	return m_keyPressed;
}

void CharInput::ClearPressedKey()
{
	m_keyPressed = false;
}

void CharInput::SetActive(bool active)
{
	m_isActive = active;
}

bool CharInput::IsActive()
{
	return m_isActive;
}
