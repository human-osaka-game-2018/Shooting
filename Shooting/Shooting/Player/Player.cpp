﻿#include"Player.h"


Player::Player()
{
	m_Pos = m_StartPos;
}

VOID Player::control(BYTE* diks)
{
		if (diks[DIK_LEFT] & 0x80)
		{
			m_Pos.x -= m_MovmentAmount;

			if (0 >= (m_Pos.x - m_Pos.scale))
			{
				m_Pos.x = 0 + m_Pos.scale;
			}
		}

		if (diks[DIK_RIGHT] & 0x80)
		{
			m_Pos.x += m_MovmentAmount;

			if (1280 <= (m_Pos.x + m_Pos.scale))
			{
				m_Pos.x = 1280 - m_Pos.scale;
			}
		}

		if (diks[DIK_UP] & 0x80)
		{
			m_Pos.y -= m_MovmentAmount;

			if (0 >= (m_Pos.y - m_Pos.scale))
			{
				m_Pos.y = 0 + m_Pos.scale;
			}
		}

		if (diks[DIK_DOWN] & 0x80)
		{
			m_Pos.y += m_MovmentAmount;

			if (720 <= (m_Pos.y + m_Pos.scale))
			{
				m_Pos.y = 720 - m_Pos.scale;
			}
		}
}

void Player::render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	CUSTOMVERTEX player[4];
	SetCustomvertex(player, m_Pos);

	pD3Device->SetTexture(0, &pTexture[PLAYER_TEX]);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}
