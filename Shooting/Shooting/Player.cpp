#include"Player.h"


Player::Player() : m_PosX(150.f), m_PosY(400.f), m_Scale(100)
{
}

VOID Player::control(LPDIRECTINPUTDEVICE8 pKeyDevice)
{
	//���͂𒲂ׁA�ړ�������
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (diks[DIK_LEFT] & 0x80)
		{
			m_PosX -= 4;
		}
		if (diks[DIK_RIGHT] & 0x80)
		{
			m_PosX += 4;
		}
		if (diks[DIK_UP] & 0x80)
		{
			m_PosY -= 4;
		}
		if (diks[DIK_DOWN] & 0x80)
		{
			m_PosY += 4;
		}
	}
}

void Player::render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	//���_��������--------------------------------------
	CUSTOMVERTEX player[4]
	{
		{ m_PosX - m_Scale, m_PosY - m_Scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ m_PosX + m_Scale, m_PosY - m_Scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ m_PosX + m_Scale, m_PosY + m_Scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ m_PosX - m_Scale, m_PosY + m_Scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//��ʂ̏���
	pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//�`��̊J�n
	pD3Device->BeginScene();

	pD3Device->SetTexture(0, &pTexture[PLAYER_TEX]);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));

	//�`��̏I��
	pD3Device->EndScene();
	//�\��
	pD3Device->Present(NULL, NULL, NULL, NULL);
}
