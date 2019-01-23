#ifndef __BASE_OBJ__
#define __BASE_OBJ__
#include "_config.h"
#include "LinkedList.h"
#include "Draw.h"
class CBaseObject
{
public:
	// ��ü ���Ž� ������ �Ҹ��ڸ� ȣ���ϱ� ���� ���� �Լ��� ����
	virtual ~CBaseObject() {}

	virtual void Action() = 0;
	virtual bool Draw() = 0;

	virtual void GetPosition(int *OutX, int *OutY) = 0;
	virtual int GetType() = 0;
	virtual bool GetFlag() = 0;
	virtual void DecreaseHP(int iDamage = 1) = 0;

protected:
	bool bFlag;
	int iX, iY;
	int iHP;
	int iType;
};

#endif