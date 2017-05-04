#ifndef INPUTSMANAGER_H
#define INPUTSMANAGER_H

#include <allegro5/allegro.h>

class InputsManager
{
private:
	bool keysDown[ALLEGRO_KEY_MAX];
	int keyPressed;
	bool isKeyPressed;
	int keysCounter;

public:
	InputsManager();
	~InputsManager();
	void Reset();
	bool IsKeyPressed(int allegroKeyCode) const;
	bool IsKeyDown(int allegroKeyCode) const;
	bool IsAnyKeyDown() const;
	void SetPressedKey(int allegroKeyCode);
	void SetReleasedKey(int allegroKeyCode);
	// Call after checkig pressed key. Clear the key pressed during the current frame
	void ClearPressedKey();
	
};

extern InputsManager input;

#endif // !INPUTSMANAGER_H
