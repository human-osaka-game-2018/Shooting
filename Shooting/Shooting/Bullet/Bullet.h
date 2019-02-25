#pragma once
#include"Global.h"


class Bullet
{
public:
	Bullet(POSITION playerPosition);

	void render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture);
private:
	POSITION m_Pos;
	const float m_BulletXScale = 32.f;
	const float m_BulletYScale = 32.f;
};
