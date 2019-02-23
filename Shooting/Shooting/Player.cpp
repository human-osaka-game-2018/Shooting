#include"Player.h"


Player::Player()
{
	PlayerPos.x = 150.f;
	PlayerPos.y = 400.f;
	PlayerPos.scale = 50;
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
			PlayerPos.x -= m_MovmentAmount;

			if (0 >= (PlayerPos.x - PlayerPos.scale))
			{
				PlayerPos.x = 0 + PlayerPos.scale;
			}
		}

		if (diks[DIK_RIGHT] & 0x80)
		{
			PlayerPos.x += m_MovmentAmount;

			if (1280 <= (PlayerPos.x + PlayerPos.scale))
			{
				PlayerPos.x = 1280 - PlayerPos.scale;
			}
		}

		if (diks[DIK_UP] & 0x80)
		{
			PlayerPos.y -= m_MovmentAmount;

			if (0 >= (PlayerPos.y - PlayerPos.scale))
			{
				PlayerPos.y = 0 + PlayerPos.scale;
			}
		}

		if (diks[DIK_DOWN] & 0x80)
		{
			PlayerPos.y += m_MovmentAmount;

			if (720 <= (PlayerPos.y + PlayerPos.scale))
			{
				PlayerPos.y = 720 - PlayerPos.scale;
			}
		}
	}
}

void Player::render(IDirect3DDevice9* pD3Device, IDirect3DTexture9* pTexture)
{
	//’¸“_î•ñ‚ð“ü‚ê‚é--------------------------------------
	CUSTOMVERTEX player[4]
	{
		{ PlayerPos.x - PlayerPos.scale, PlayerPos.y - PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ PlayerPos.x + PlayerPos.scale, PlayerPos.y - PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ PlayerPos.x + PlayerPos.scale, PlayerPos.y + PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ PlayerPos.x - PlayerPos.scale, PlayerPos.y + PlayerPos.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	pD3Device->SetTexture(0, &pTexture[PLAYER_TEX]);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
}
