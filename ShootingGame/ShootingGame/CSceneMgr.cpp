#include "CSceneMgr.h"

#include "CScene_1Title.h"
#include "CScene_2Gameover.h"
#include "CScene_Stage1.h"
#include "CScene_Stage2.h"

#include "Windows.h"
#include <ctime>

#include "Console.h"

#define SCENE_STAGE1 200 
#define SCENE_STAGE2 201
#define SCENE_TITLE 202
#define SCENE_GAMEOVER 203

CSceneManager * CSceneManager::_pCSceneMgr = NULL;
CSceneManager * CSceneMgr = CSceneManager::GetInstance();

CSceneManager::CSceneManager()
{
	pScene = (CScene*)new CScene_TITLE();
	///CSceneMgr->LoadScene(SCENE_TITLE);
	srand((unsigned int)time(0));
	cs_Initial();
}

CSceneManager * CSceneManager::GetInstance(void)
{
	if (NULL == _pCSceneMgr)
	{
		_pCSceneMgr = new CSceneManager;
		atexit(Destroy);
	}
	return _pCSceneMgr;
}

void CSceneManager::Destroy(void)
{
	delete _pCSceneMgr;
}

void CSceneManager::Run()
{
	pScene->Update();
	if (_bChangeScene == true)
	{
		LoadScene(_iNextScene);
		_bChangeScene = false;
		_iNextScene = 0;
	}
}
void CSceneManager::LoadScene(int Type)
{
	if (pScene != nullptr)
		delete pScene;

	switch (Type)
	{
	case SCENE_TITLE:
		pScene = (CScene*)new CScene_TITLE();
		break;

	case SCENE_STAGE1:
		pScene = (CScene*)new CScene_GAME1();
		break;

	case SCENE_STAGE2:
		pScene = (CScene*)new CScene_GAME2();
		break;

	case SCENE_GAMEOVER:
		pScene = (CScene*)new CScene_GAMEOVER();
		break;
	}
}

void CSceneManager::CollisionCheck()
{
	//CSceneManager *CSceneMgr = CSceneManager::GetInstance();
	ObjectList<CBaseObject*>::iterator Object_iter;
	ObjectList<CBaseObject*>::iterator Coll_iter;

	int iOriginX, iOriginY, iCmpX, iCmpY;

	for (Object_iter = CSceneMgr->_lst.begin(); Object_iter != CSceneMgr->_lst.end(); ++Object_iter)
	{
		for (Coll_iter = CSceneMgr->_lst.begin(); Coll_iter != CSceneMgr->_lst.end(); ++Coll_iter)
		{
			(*Object_iter)->GetPosition(&iOriginX, &iOriginY);
			(*Coll_iter)->GetPosition(&iCmpX, &iCmpY);

			if (iOriginX == iCmpX && iOriginY == iCmpY)
			{
				if ((*Object_iter)->GetType() == dfTYPE_ENEMY)
				{
					if ((*Coll_iter)->GetType() == dfTYPE_ALLY || (*Coll_iter)->GetType() == dfTYPE_ALLY_BULLET)
					{
						(*Object_iter)->DecreaseHP();
						(*Coll_iter)->DecreaseHP();
					}
				}
				else if ((*Object_iter)->GetType() == dfTYPE_ENEMY_SPECIAL_BULLET)
				{
					if ((*Coll_iter)->GetType() == dfTYPE_ALLY || (*Coll_iter)->GetType() == dfTYPE_ALLY_BULLET)
					{
						(*Object_iter)->DecreaseHP();
						(*Coll_iter)->DecreaseHP();
					}
				}
				else if ((*Object_iter)->GetType() == dfTYPE_ENEMY_BULLET)
				{
					if ((*Coll_iter)->GetType() == dfTYPE_ALLY)
					{
						(*Object_iter)->DecreaseHP();
						(*Coll_iter)->DecreaseHP();
					}
				}
			}
		}
	}
}