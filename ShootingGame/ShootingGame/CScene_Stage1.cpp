#include "CScene_Stage1.h"
#include "CSceneMgr.h"

#include "CPlayer.h"
#include "CEnemy.h"
#include "CBoss.h"
#include "KeyProcess.h"

CScene_GAME1::CScene_GAME1()
{
	CBaseObject* pdfTYPE_ENEMY;
	_iRemainEnemy = 0;
	for (int iCnt = 0; iCnt < 3; ++iCnt)
		for (int iCnt2 = 0; iCnt2 < 20; ++iCnt2)
		{
			pdfTYPE_ENEMY = (CBaseObject*)new CEnemy(8 + (iCnt2 + 1) * 3, 5 + iCnt * 3);
			CSceneMgr->_lst.push_back(pdfTYPE_ENEMY);
			++_iRemainEnemy;
		}
}
CScene_GAME1::~CScene_GAME1()
{
}
void CScene_GAME1::Update()
{
	Buffer_Clear();
	if (!KeyProcess()) return;
	Action();
	Draw();
	CSceneMgr->CollisionCheck();
	Buffer_Flip();

	if (_iRemainEnemy == 0)
	{
		CSceneMgr->_bChangeScene = true;
		CSceneMgr->_iNextScene = dfSCENE_STAGE2;
	}
}

void CScene_GAME1::Action()
{
	ObjectList<CBaseObject*>::iterator Object_iter;
	ObjectList<CBaseObject*>::Node* pNode;

	for (Object_iter = CSceneMgr->_lst.begin(); Object_iter != CSceneMgr->_lst.end(); ++Object_iter)
	{
		(*Object_iter)->Action();
	}

	//ChkEnemey&Plater
	for (Object_iter = CSceneMgr->_lst.begin(); Object_iter != CSceneMgr->_lst.end(); ++Object_iter)
	{
		pNode = Object_iter.getNode();

		if (pNode != nullptr)
		{
			if ((pNode->_Data)->GetFlag() == false)
			{
				if (pNode->_Data != NULL)
				{
					if ((pNode->_Data)->GetType() == dfTYPE_ENEMY)		// Àû »ç¸Á
					{
						_iRemainEnemy--;
					}
					else if ((pNode->_Data)->GetType() == dfTYPE_ALLY)	// ÇÃ·¹ÀÌ¾î »ç¸Á
					{
						CSceneMgr->_bChangeScene = true;
						CSceneMgr->_iNextScene = dfSCENE_GAMEOVER;
						break;
					}
					delete pNode->_Data;
					CSceneMgr->_lst.erase(Object_iter);
				}
			}
		}
		else
			break;
	}
}

void CScene_GAME1::Draw()
{
	ObjectList<CBaseObject*>::iterator Object_iter;

	for (Object_iter = CSceneMgr->_lst.begin(); Object_iter != CSceneMgr->_lst.end(); ++Object_iter)
	{
		(*Object_iter)->Draw();
	}
}
