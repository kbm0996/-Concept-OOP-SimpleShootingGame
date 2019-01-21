#ifndef __ENEMY_OBJ__
#define __ENEMY_OBJ__
#include "BaseObject.h"

class CEnemy : CBaseObject
{
public:
	CEnemy(int X, int Y) :iCycleX(1), iCycleY(1)
	{
		iRoamingX = 8;

		iX = X;
		iY = Y;
		iSpawnX = X;
		iSpawnY = Y;

		bFlag = true;
		iHP = 1;
		iType = dfTYPE_ENEMY;
	}
	void Action();
	bool Draw();
	void CreateBullet(int iPosX, int iPosY, int Type, int iOriginX = 0);

	void GetPosition(int *OutX, int *OutY);
	int GetType();
	bool GetFlag();
	bool CmpType(int Type);
	void DecreaseHP(int iDamage = 1);

protected:
	int iSpawnX;	// 생성됐던 위치
	int iSpawnY;
	int iRoamingX;	// 이동 반경
	int iRoamingY;
	int iCycleX;	// X축 끝 부분에 도달했는가
	int iCycleY;	// Y축 끝 부분에 도달했는가
};

#endif