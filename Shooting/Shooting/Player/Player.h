#pragma once
#include"Global.h"


class Player
{
public:
	Player();

	inline float getPosX()
	{
		return m_PlayerPos.x;
	}

	inline float getPosY()
	{
		return m_PlayerPos.y;
	}

	inline void setPosX(float x)
	{
		m_PlayerPos.x = x;
	}

	inline void setPosY(float y)
	{
		m_PlayerPos.y = y;
	}

	void control(BYTE* diks);
	void render(IDirect3DDevice9* g_pD3Device, IDirect3DTexture9* g_pTexture);
private:
	POSITION m_PlayerPos;
	const POSITION m_StartPlayerPos = { 150.f ,400.f, 50.f };
	const float m_MovmentAmount = 4;
	int status;
	int counter;
};
