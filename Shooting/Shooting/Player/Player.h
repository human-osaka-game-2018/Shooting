#pragma once
#include"Global.h"
#include "DirectInput/DirectInput.h"


class Player
{
public:
	Player();

	inline POSITION getPos()
	{
		return m_Pos;
	}

	void control(DirectInput* directInput);
	void render(IDirect3DDevice9* g_pD3Device, IDirect3DTexture9** g_pTexture);
private:
	POSITION m_Pos;
	const POSITION m_StartPos = { 150.f ,400.f, 50.f, 50.f };
	const float m_MovmentAmount = 4;
	int status;
	int counter;
};
