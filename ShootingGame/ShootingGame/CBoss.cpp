#include "CBoss.h"
#include "CBullet.h"
#include "CBossBullet.h"
#include "CSceneMgr.h"

void CBoss::Action()
{
	// 이동
	if (iX == 1 || iX == dfSCREEN_WIDTH - 2)
		iCycleX *= -1;

	if (iCycleX == -1)
		++iX;
	else
		--iX;


	if (iY == 1 || iY == dfSCREEN_HEIGHT / 2 - 1)
		iCycleY *= -1;

	if (iCycleY == -1)
		++iY;
	else
		--iY;


	// 공격
	if (iY == 1)
		CreateSpecialBullet(iX, iY);

	if (iY == dfSCREEN_HEIGHT / 2 - 1)
		CreateBullet(iX, iY, dfTYPE_ENEMY_BULLET);



	// 사망
	if (iHP <= 0)
		bFlag = false;
}
bool CBoss::Draw()
{
	if (bFlag == 1)
	{
		Draw_Sprite(iX, iY, '#');
		return true;
	}
	else
		return false;
}
void CBoss::GetPosition(int *OutX, int *OutY)
{
	*OutX = iX;
	*OutY = iY;
}
int CBoss::GetType()
{
	return iType;
}
bool CBoss::GetFlag()
{
	return bFlag;
}
void CBoss::DecreaseHP(int iDamage)
{
	--iHP;
}

void CBoss::CreateBullet(int iPosX, int iPosY, int Type, int iSpecial)
{
	CBaseObject* Bullet = (CBaseObject*)new CBullet(iPosX, iPosY, Type, iSpecial);
	CSceneMgr->_lst.push_back(Bullet);
}

void CBoss::CreateSpecialBullet(int iPosX, int iPosY)//int Type)
{
	CBaseObject* Bullet = (CBaseObject*)new CBossBullet(iPosX, iPosY);
	CSceneMgr->_lst.push_back(Bullet);
}