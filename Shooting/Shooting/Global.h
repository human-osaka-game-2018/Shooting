#pragma once
/**
*いろいろなとこで必要なものを一旦突っ込むところ
*/

#include <windows.h>


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