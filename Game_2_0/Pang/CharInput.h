#ifndef CHARINPUT_H
#define CHARINPUT_H


class CharInput
{
private:
	char m_key;
	bool m_keyPressed;
	bool m_isActive;

public:
	CharInput();
	~CharInput();
	
	void SetPressedKey(char key);
	char GetPressedKey();
	bool AnyKeyPressed();
	void ClearPressedKey();
	void SetActive(bool active);
	bool IsActive();
};

extern CharInput charInput;

#endif // !CHARINPUT_H
