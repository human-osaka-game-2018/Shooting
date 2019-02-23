#pragma once
/**
*いろいろなとこで必要なものを一旦突っ込むところ
*/

#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <dinput.h>
#include <tchar.h>
#include <locale.h>

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

struct POSITION
{
	float x, y, scale;
};

void SetCustomvertex(CUSTOMVERTEX* pCustomvertex, POSITION position);
