#include"Global.h"

void SetCustomvertex(CUSTOMVERTEX* pCustomvertex, POSITION position)
{
	float leftX = position.x - position.scale;
	float rightX = position.x + position.scale;
	float topY = position.y - position.scale;
	float bottomY = position.y + position.scale;

	pCustomvertex[0] = { leftX, topY, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f };
	pCustomvertex[1] = { rightX, topY, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f };
	pCustomvertex[2] = { rightX, bottomY, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f };
	pCustomvertex[3] = { leftX, bottomY, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f };
}
