#ifndef __PLAYER_OBJ__
#define __PLAYER_OBJ__
#include "BaseObject.h"

class CPlayer : CBaseObject
{
public:
	int Queue[dfSIZE_PLAYER_QUEUE];
	int Front;
	int Rear;
	int Temp;

	CPlayer()
	{
		bFlag = true;
		iHP = 5;
		iX = dfSCREEN_WIDTH / 2;
		iY = dfSCREEN_HEIGHT;
		iType = dfTYPE_ALLY;
	}
	void Action();
	bool Draw();
	void CreateBullet(int iPosX, int iPosY, int Type, int iOriginX = 0);

	void GetPosition(int *OutX, int *OutY);
	int GetType();
	bool GetFlag();
	void DecreaseHP(int iDamage = 1);

	bool Enqueue(int iInData);
	bool Dequeue(int *pOutData);
	bool Peek(int *pOutData);
};

extern CPlayer* Player;

#endif