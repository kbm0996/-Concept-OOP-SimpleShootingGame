#include "CBossBullet.h"
#include "CBullet.h"
#include "CSceneMgr.h"

void CBossBullet::Action()
{
	if (bFlag == true)
		// 이동
		++iY;

	// 공격
	CreateBullet(iX, iY, dfTYPE_ENEMY_BULLET, 1);
	CreateBullet(iX, iY, dfTYPE_ENEMY_BULLET, 2);

	// 사망
	if (iHP <= 0)
		bFlag = false;

	if (iX < 0) bFlag = false;
	if (iY < 0) bFlag = false;
	if (iX > dfSCREEN_WIDTH - 2)	bFlag = false;
	if (iY > dfSCREEN_HEIGHT - 1)	bFlag = false;
}
bool CBossBullet::Draw()
{
	if (bFlag == 1)
	{
		Draw_Sprite(iX, iY, '@');
		return true;
	}
	else
		return false;
}
void CBossBullet::GetPosition(int *OutX, int *OutY)
{
	*OutX = iX;
	*OutY = iY;
}

int CBossBullet::GetType()
{
	return iType;
}

bool CBossBullet::GetFlag()
{
	return bFlag;
}

void CBossBullet::DecreaseHP(int iDamage)
{
	iHP-= iDamage;
}

void CBossBullet::CreateBullet(int iPosX, int iPosY, int Type, int iSpecial)
{
	CBaseObject* Bullet = (CBaseObject*)new CBullet(iPosX, iPosY, Type, iSpecial);
	CSceneMgr->_lst.push_back(Bullet);
}