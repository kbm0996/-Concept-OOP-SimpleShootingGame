#include "CBullet.h"


void CBullet::Action()
{
	if (bFlag == true)
	{
		if (iType == dfTYPE_ALLY_BULLET)
			--iY;

		if (iType == dfTYPE_ENEMY_BULLET && iSpecial == 1) // Boss Bullet of Bullet
		{
			++iX;
			if (iX > iOriginX + 12)	bFlag = false;
		}
		else if (iType == dfTYPE_ENEMY_BULLET && iSpecial == 2) // Boss Bullet of Bullet
		{
			--iX;
			if (iX < iOriginX - 12)	bFlag = false;
		}
		else if (iType == dfTYPE_ENEMY_BULLET)
			++iY;

		if (iX < 0) bFlag = false;
		if (iY < 0) bFlag = false;
		if (iX > dfSCREEN_WIDTH - 2)	bFlag = false;
		if (iY > dfSCREEN_HEIGHT - 1)	bFlag = false;
	}

	if (iHP <= 0)
		bFlag = false;
}

bool CBullet::Draw()
{
	if (bFlag == true)
	{
		if (iType == dfTYPE_ALLY_BULLET)
			Draw_Sprite(iX, iY, '^');
		else if (iType == dfTYPE_ENEMY_BULLET && iSpecial == 1)
			Draw_Sprite(iX, iY, '>');
		else if (iType == dfTYPE_ENEMY_BULLET && iSpecial == 2)
			Draw_Sprite(iX, iY, '<');
		else if (iType == dfTYPE_ENEMY_BULLET)
			Draw_Sprite(iX, iY, 'v');

		return true;
	}
	else
		return false;
}
void CBullet::GetPosition(int *OutX, int *OutY)
{
	*OutX = iX;
	*OutY = iY;
}

int CBullet::GetType()
{
	return iType;
}

bool CBullet::GetFlag()
{
	return bFlag;
}

bool CBullet::CmpType(int Type)
{
	if (iType != Type)
		return false;
	return true;
}

void CBullet::DecreaseHP(int iDamage)
{
	iHP -= iDamage;
}