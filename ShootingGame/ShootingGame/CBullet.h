#ifndef __BULLET_OBJ__
#define __BULLET_OBJ__
#include "BaseObject.h"

class CBullet : CBaseObject
{
public:
	CBullet(int X, int Y, int Type, int Special = 0)
	{
		iX = X;
		iY = Y;
		iType = Type;
		iOriginX = X;
		iSpecial = Special;

		bFlag = true;
		iHP = 1;
	}

	void Action();
	bool Draw();

	void GetPosition(int *OutX, int *OutY);
	int GetType();
	bool GetFlag();
	bool CmpType(int Type);
	void DecreaseHP(int iDamage = 1);

protected:
	int iSpecial;
	int iOriginX; // Special Bullet Only
};

#endif