#include"Global.h"

void SetCustomvertex(CUSTOMVERTEX* pCustomvertex, POSITION position, float rightTU, float bottomTV, float leftTU, float topTV)
{
	float leftX = position.x - position.XScale;
	float rightX = position.x + position.XScale;
	float topY = position.y - position.YScale;
	float bottomY = position.y + position.YScale;

	pCustomvertex[0] = { leftX, topY, 1.f, 1.f, 0xFFFFFFFF, leftTU, topTV };
	pCustomvertex[1] = { rightX, topY, 1.f, 1.f, 0xFFFFFFFF, rightTU, topTV };
	pCustomvertex[2] = { rightX, bottomY, 1.f, 1.f, 0xFFFFFFFF, rightTU, bottomTV };
	pCustomvertex[3] = { leftX, bottomY, 1.f, 1.f, 0xFFFFFFFF, leftTU, bottomTV };
}
