#pragma once
#include"Global.h"

#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

class Player
{
public:
	Player();
	inline float getPosX()
	{
		return PlayerPos.x;
	}
	inline float getPosY()
	{
		return PlayerPos.y;
	}
	inline void setPosX(float x)
	{
		PlayerPos.x = x;
	}
	inline void setPosY(float y)
	{
		PlayerPos.y = y;
	}
	void control(LPDIRECTINPUTDEVICE8 pKeyDevice);
	void render(IDirect3DDevice9* g_pD3Device, IDirect3DTexture9* g_pTexture);
private:
	POSITION PlayerPos;
	const float m_MovmentAmount = 4;
	int status;
	int counter;
};
