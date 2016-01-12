#pragma once

class CInput
{
private:
	enum KEYSTATE { DEFAULT = 0 , DOWN , UP };
	KEYSTATE m_eKeyState[256];

public:
	static CInput* ins()
	{
		static CInput ins;
		return &ins;
	}
	CInput();
	~CInput();

public:
	inline bool KeyDown(int vk);
	inline bool KeyUp(int vk);

public:
	bool GetKeyDown(int vk);
	bool GetKeyUp(int vk);

public:
	void Update();
};