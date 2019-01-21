#ifndef __BOSS_OBJ__
#define __BOSS_OBJ__
#include "BaseObject.h"

class CBoss : CBaseObject
{
public:
	CBoss(int X, int Y) :iCycleX(1), iCycleY(1)
	{
		iX = X;
		iY = Y;

		bFlag = true;
		iHP = 3;
		iType = dfTYPE_ENEMY;
	}

	void Action();
	bool Draw();

	void GetPosition(int *OutX, int *OutY);
	int GetType();
	bool GetFlag();
	void DecreaseHP(int iDamage = 1);

	void CreateBullet(int iPosX, int iPosY, int Type, int iOriginX = 0);
	void CreateSpecialBullet(int iPosX, int iPosY);

protected:
	int iSpawnX;	// �����ƴ� ��ġ
	int iSpawnY;
	int iRoamingX;	// �̵� �ݰ�
	int iRoamingY;
	int iCycleX;	// X�� �� �κп� �����ߴ°�
	int iCycleY;	// Y�� �� �κп� �����ߴ°�
};
#endif