#include"Player.h"


Player::Player()
{
	m_PlayerPos = m_StartPlayerPos;
}

VOID Player::control(LPDIRECTINPUTDEVICE8 pKeyDevice)
{
	//入力を調べ、移動させる
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK_LEFT] & 0x80)
		{
			m_PlayerPos.x -= m_MovmentAmount;

			if (0 >= (m_PlayerPos.x - m_PlayerPos.scale))
			{
				m_PlayerPos.x = 0 + m_PlayerPos.scale;
			}
		}

		if (diks[DIK_RIGHT] & 0x80)
		{
			m_PlayerPos.x += m_MovmentAmount;

			if (1280 <= (m_PlayerPos.x + m_PlayerPos.scale))
			{
				m_PlayerPos.x = 1280 - m_PlayerPos.scale;
			}
		}

		if (diks[DIK_UP] & 0x80)
		{
			m_PlayerPos.y -= m_MovmentAmount;

			if (0 >= (m_PlayerPos.y - m_PlayerPos.scale))
			{
				m_PlayerPos.y = 0 + m_PlayerPos.scale;
			}
		}

		if (diks[DIK_DOWN] & 0x80)
		{
			m_PlayerPos.y += m_MovmentAmount;

			if (720 <= (m_PlayerPos.y + m_PlayerPos.scale))
			{
				m_PlayerPos.y = 720 - m_PlayerPos.scale;
			}
		}
	}
}

void Player::render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX player[4]
	{
		{ m_PlayerPos.x - m_PlayerPos.scale, m_PlayerPos.y - m_PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ m_PlayerPos.x + m_PlayerPos.scale, m_PlayerPos.y - m_PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ m_PlayerPos.x + m_PlayerPos.scale, m_PlayerPos.y + m_PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ m_PlayerPos.x - m_PlayerPos.scale, m_PlayerPos.y + m_PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	pD3Device->SetTexture(0, &pTexture[PLAYER_TEX]);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}
