#pragma once
class InputManager
{
	const int keyDownFrames = 10;
	char key;
	bool keyPressed;
	bool keyDown;
	int keyDownTimer;

public:
	InputManager();
	~InputManager();
	void SetKey();
	bool IsKeyDown();
};

