#include "KeyProcess.h"
#include <Windows.h>
#include "CPlayer.h"

bool KeyProcess()
{
	if (GetAsyncKeyState(VK_UP) & 0x8001)
		Player->Enqueue(dfUP);

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		Player->Enqueue(dfDOWN);

	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		Player->Enqueue(dfLEFT);

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		Player->Enqueue(dfRIGHT);

	if (GetAsyncKeyState(VK_UP) & 0x8001 && GetAsyncKeyState(VK_LEFT) & 0x8001)
		Player->Enqueue(dfUPLEFT);

	if (GetAsyncKeyState(VK_UP) & 0x8001 && GetAsyncKeyState(VK_RIGHT) & 0x8001)
		Player->Enqueue(dfUPRIGHT);

	if (GetAsyncKeyState(VK_DOWN) & 0x8001 && GetAsyncKeyState(VK_LEFT) & 0x8001)
		Player->Enqueue(dfDOWNLEFT);

	if (GetAsyncKeyState(VK_DOWN) & 0x8001 && GetAsyncKeyState(VK_RIGHT) & 0x8001)
		Player->Enqueue(dfDOWNRIGHT);

	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
		Player->Enqueue(dfATTACK);

	//if (GetAsyncKeyState(VK_UP) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfUP_ATTACK);

	//if (GetAsyncKeyState(VK_DOWN) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfDOWN_ATTACK);

	//if (GetAsyncKeyState(VK_LEFT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfLEFT_ATTACK);

	//if (GetAsyncKeyState(VK_RIGHT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfRIGHT_ATTACK);

	//if (GetAsyncKeyState(VK_UP) & 0x8001 && GetAsyncKeyState(VK_LEFT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfUPLEFT_ATTACK);

	//if (GetAsyncKeyState(VK_UP) & 0x8001 && GetAsyncKeyState(VK_RIGHT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfUPRIGHT_ATTACK);

	//if (GetAsyncKeyState(VK_DOWN) & 0x8001 && GetAsyncKeyState(VK_LEFT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfDOWNLEFT_ATTACK);

	//if (GetAsyncKeyState(VK_DOWN) & 0x8001 && GetAsyncKeyState(VK_RIGHT) & 0x8001 && GetAsyncKeyState(VK_SPACE) & 0x8001)
	//	Player->Enqueue(dfDOWNRIGHT_ATTACK);

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		Player->Enqueue(dfESCAPE);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		Player->Enqueue(dfENTER);

	return true;
}