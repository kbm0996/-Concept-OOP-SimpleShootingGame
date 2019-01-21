#include "Windows.h"
#include "CSceneMgr.h"

void main()
{
	CSceneManager * CSceneMgr = CSceneManager::GetInstance();
	while (1)
	{
		CSceneMgr->Run();
		Sleep(100);
	}
}
