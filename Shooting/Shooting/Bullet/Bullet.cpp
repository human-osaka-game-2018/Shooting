#include"Bullet.h"


Bullet::Bullet(POSITION playePosition)
{
	m_Pos.x = playePosition.x;
	m_Pos.y = playePosition.y - playePosition.YScale;
	m_Pos.YScale = m_BulletXScale;
	m_Pos.XScale = m_BulletYScale;
}

void Bullet::Render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	CUSTOMVERTEX bullet[4];
	float Tu = 32 / 392;
	float Tv = 32 / 455;
	SetCustomvertex(bullet, m_Pos, Tu, Tv);


	pD3Device->SetTexture(0, pTexture);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, bullet, sizeof(CUSTOMVERTEX));
}
