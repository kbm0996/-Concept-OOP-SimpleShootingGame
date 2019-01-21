#ifndef __BOSS_BULLET_OBJ__
#define __BOSS_BULLET_OBJ__
#include "BaseObject.h"

class CBossBullet : CBaseObject
{
public:
	CBossBullet(int X, int Y)
	{
		iX = X;
		iY = Y;

		bFlag = true;
		iHP = 1;
		iType = dfTYPE_ENEMY_SPECIAL_BULLET;
	}

	void Action();
	bool Draw();
	void CreateBullet(int iPosX, int iPosY, int Type, int iOriginX = 0);


	void GetPosition(int *OutX, int *OutY);
	int GetType();
	bool GetFlag();
	void DecreaseHP(int iDamage = 1);
};
#endif