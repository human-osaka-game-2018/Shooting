#include"Player.h"


Player::Player()
{
	m_Pos = m_StartPos;
}

VOID Player::Control(DirectInput* directInput)
{
		if (directInput->IsKeyPressed(DIK_LEFT))
		{
			m_Pos.x -= m_MovmentAmount;

			if (0 >= (m_Pos.x - m_Pos.XScale))
			{
				m_Pos.x = 0 + m_Pos.XScale;
			}
		}

		if (directInput->IsKeyPressed(DIK_RIGHT))
		{
			m_Pos.x += m_MovmentAmount;

			if (1280 <= (m_Pos.x + m_Pos.XScale))
			{
				m_Pos.x = 1280 - m_Pos.XScale;
			}
		}

		if (directInput->IsKeyPressed(DIK_UP))
		{
			m_Pos.y -= m_MovmentAmount;

			if (0 >= (m_Pos.y - m_Pos.YScale))
			{
				m_Pos.y = 0 + m_Pos.YScale;
			}
		}

		if (directInput->IsKeyPressed(DIK_DOWN))
		{
			m_Pos.y += m_MovmentAmount;

			if (720 <= (m_Pos.y + m_Pos.YScale))
			{
				m_Pos.y = 720 - m_Pos.YScale;
			}
		}
}

void Player::Render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	CUSTOMVERTEX player[4];
	SetCustomvertex(player, m_Pos);

	pD3Device->SetTexture(0, pTexture);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}
