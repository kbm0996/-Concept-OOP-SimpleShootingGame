#include "CScene_2Gameover.h"
#include "CSceneMgr.h"

#include "CPlayer.h"
#include "CEnemy.h"
#include "CBoss.h"
#include "KeyProcess.h"

CScene_GAMEOVER::CScene_GAMEOVER()
{
}
CScene_GAMEOVER::~CScene_GAMEOVER()
{
	ObjectList<CBaseObject*>::iterator Object_iter;
	ObjectList<CBaseObject*>::Node* pNode;

	for (Object_iter = CSceneMgr->_lst.begin(); Object_iter != CSceneMgr->_lst.end(); ++Object_iter)
	{
		pNode = Object_iter.getNode();
		if (pNode != nullptr)
		{
			if (pNode->_Data != NULL)
			{
				delete pNode->_Data;
				CSceneMgr->_lst.erase(Object_iter);
			}
		}
	}
}
void CScene_GAMEOVER::Update()
{
	int iAction;

	Buffer_Clear();
	if (!KeyProcess()) return;
	Draw_Scene(dfSCENE_GAMEOVER);
	Buffer_Flip();

	Player->Dequeue(&iAction);
	if (iAction == dfENTER)
	{
		CSceneMgr->_bChangeScene = true;
		CSceneMgr->_iNextScene = dfSCENE_TITLE;
	}
}