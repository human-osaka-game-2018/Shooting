#pragma once
#include<dinput.h>


class DirectInput
{
public:
	HRESULT Initialize(HWND hWnd);
	void CaptureKeyState();
	bool IsKeyPressed(int key);
	~DirectInput();
private:
	BYTE m_diks[256];
	LPDIRECTINPUT8 m_pDinput = NULL;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice = NULL;
};
