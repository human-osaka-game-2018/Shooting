#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <dinput.h>

/**
*@mainpage
*ゲーム開発研究部サンプルコード
*/
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum TEXTURE
{
	PLAYER_TEX,
	TEXMAX
};

class Player
{
public:
	Player();
	inline float getPosX()
	{
		return m_PosX;
	}
	inline float getPosY()
	{
		return m_PosY;
	}
	inline void setPosX(float x)
	{
		m_PosX = x;
	}
	inline void setPosY(float y)
	{
		m_PosY = y;
	}
	void control(LPDIRECTINPUTDEVICE8 pKeyDevice);
	void render(IDirect3DDevice9* g_pD3Device, IDirect3DTexture9* g_pTexture);
private:
	float m_PosX;
	float m_PosY;
	float m_Scale;
	float m_MovmentAmount;
	int status;
	int counter;
};
