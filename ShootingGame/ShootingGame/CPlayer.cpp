#include "CPlayer.h"
#include <conio.h>
#include "CBullet.h"
#include "CSceneMgr.h"

CPlayer* Player;

void CPlayer::CreateBullet(int iPosX, int iPosY, int Type, int iSpecial)
{
	CBaseObject* Bullet = (CBaseObject*)new CBullet(iPosX, iPosY, Type, iSpecial);
	CSceneMgr->_lst.push_back(Bullet);
}


void CPlayer::Action()
{
	int iAction;

	// 메시지 큐 방식 - 멀티플랫폼, 네트워크 프로그래밍 시에는 필수
	while (Dequeue(&iAction))
	{
		switch (iAction)
		{
		case dfUP:
			--iY;
			break;

		case dfDOWN:
			++iY;
			break;

		case dfLEFT:
			--iX;
			break;

		case dfRIGHT:
			++iX;
			break;

		case dfUPLEFT:
			--iY;
			--iX;
			break;

		case dfUPRIGHT:
			--iY;
			++iX;
			break;

		case dfDOWNLEFT:
			++iY;
			--iX;
			break;

		case dfDOWNRIGHT:
			++iY;
			++iX;
			break;

		case dfATTACK:
			CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
			break;

		//case dfUP_ATTACK:
		//	--iY;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfDOWN_ATTACK:
		//	++iY;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfLEFT_ATTACK:
		//	--iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfRIGHT_ATTACK:
		//	++iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfUPLEFT_ATTACK:
		//	--iY;
		//	--iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfUPRIGHT_ATTACK:
		//	--iY;
		//	++iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfDOWNLEFT_ATTACK:
		//	++iY;
		//	--iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		//case dfDOWNRIGHT_ATTACK:
		//	++iY;
		//	++iX;
		//	CreateBullet(iX, iY, dfTYPE_ALLY_BULLET);
		//	break;

		case dfESCAPE:
			_getch();
			break;
		}
	}

	if (iX < 0) iX = 0;
	if (iY < 0) iY = 0;
	if (iX > dfSCREEN_WIDTH - 2)	iX = dfSCREEN_WIDTH - 2;
	if (iY > dfSCREEN_HEIGHT - 1)	iY = dfSCREEN_HEIGHT - 1;

	if (iHP <= 0)	// 사망
	{
		bFlag = false;
	}
}
bool CPlayer::Draw()
{
	if (bFlag == 1)
	{
		Draw_Sprite(iX, iY, 'A');
		return true;
	}
	else
		return false;
}
void CPlayer::GetPosition(int *OutX, int *OutY)
{
	*OutX = iX;
	*OutY = iY;
}

int CPlayer::GetType()
{
	return iType;
}

bool CPlayer::GetFlag()
{
	return bFlag;
}

void CPlayer::DecreaseHP(int iDamage)
{
	iHP -= iDamage;
}

bool CPlayer::Enqueue(int iInData)
{
	if ((Rear + 1) % dfSIZE_PLAYER_QUEUE == Front)
		return false;
	Rear = (Rear + 1) % dfSIZE_PLAYER_QUEUE;
	Queue[Rear] = iInData;
	return true;
}
bool CPlayer::Dequeue(int *pOutData)
{
	if (Front == Rear)
		return false;
	Front = (Front + 1) % dfSIZE_PLAYER_QUEUE;
	*pOutData = Queue[Front];
	return true;
}
bool CPlayer::Peek(int *pOutData)
{
	if (Front == Rear)
		return false;
	*pOutData = Queue[Front];
	return true;
}
