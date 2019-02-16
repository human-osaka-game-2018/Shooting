#include"Player.h"


Player::Player() : m_PosX(150.f), m_PosY(400.f), m_Scale(50)
{
}

VOID Player::control(LPDIRECTINPUTDEVICE8 pKeyDevice)
{
	//“ü—Í‚ð’²‚×AˆÚ“®‚³‚¹‚é
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK_LEFT] & 0x80)
		{
			m_PosX -= m_MovmentAmount;

			if (0 >= (m_PosX - m_Scale))
			{
				m_PosX = 0 + m_Scale;
			}
		}

		if (diks[DIK_RIGHT] & 0x80)
		{
			m_PosX += m_MovmentAmount;

			if (1280 <= (m_PosX + m_Scale))
			{
				m_PosX = 1280 - m_Scale;
			}
		}

		if (diks[DIK_UP] & 0x80)
		{
			m_PosY -= m_MovmentAmount;

			if (0 >= (m_PosY - m_Scale))
			{
				m_PosY = 0 + m_Scale;
			}
		}

		if (diks[DIK_DOWN] & 0x80)
		{
			m_PosY += m_MovmentAmount;

			if (720 <= (m_PosY + m_Scale))
			{
				m_PosY = 720 - m_Scale;
			}
		}
	}
}

void Player::render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	//’¸“_î•ñ‚ð“ü‚ê‚é--------------------------------------
	CUSTOMVERTEX player[4]
	{
		{ m_PosX - m_Scale, m_PosY - m_Scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ m_PosX + m_Scale, m_PosY - m_Scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ m_PosX + m_Scale, m_PosY + m_Scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ m_PosX - m_Scale, m_PosY + m_Scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	pD3Device->SetTexture(0, &pTexture[PLAYER_TEX]);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}
