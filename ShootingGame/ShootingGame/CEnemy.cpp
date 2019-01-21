#include "CEnemy.h"
#include "Windows.h"
#include "CBullet.h"
#include "CSceneMgr.h"

void CEnemy::CreateBullet(int iPosX, int iPosY, int Type, int iSpecial)
{
	CBaseObject* Bullet = (CBaseObject*)new CBullet(iPosX, iPosY, Type, iSpecial);
	CSceneMgr->_lst.push_back(Bullet);
}

void CEnemy::Action()
{
	// 이동
	if (iX == iSpawnX + iRoamingX || iX == iSpawnX - iRoamingX)
		iCycleX *= -1;

	if (iCycleX == 1)
		++iX;
	else
		--iX;


	// 공격
	if ((rand() % 100) + 1 == 1)
		CreateBullet(iX, iY, dfTYPE_ENEMY_BULLET);

	// 사망
	if (iHP <= 0)
	{
		bFlag = false;
		//iDeadCnt++;
	}
}
bool CEnemy::Draw()
{
	if (bFlag == 1)
	{
		Draw_Sprite(iX, iY, '@');
		return true;
	}
	else
		return false;
}
void CEnemy::GetPosition(int *OutX, int *OutY)
{
	*OutX = iX;
	*OutY = iY;
}

int CEnemy::GetType()
{
	return iType;
}
bool CEnemy::GetFlag()
{
	return bFlag;
}

bool CEnemy::CmpType(int Type)
{
	if (iType != Type)
		return false;
	return true;
}

void CEnemy::DecreaseHP(int iDamage)
{
	iHP -= iDamage;
}