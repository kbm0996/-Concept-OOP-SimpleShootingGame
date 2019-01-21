#include "CScene_1Title.h"
#include "CSceneMgr.h"

#include "CPlayer.h"
#include "CEnemy.h"
#include "CBoss.h"
#include "KeyProcess.h"

CScene_TITLE::CScene_TITLE()
{
	Player = new CPlayer();
}
CScene_TITLE::~CScene_TITLE()
{
	CSceneMgr->_lst.push_back((CBaseObject*)Player);
}
void CScene_TITLE::Update()
{
	int iAction;

	Buffer_Clear();
	if (!KeyProcess()) return;
	Draw_Scene(dfSCENE_TITLE);
	Buffer_Flip();

	Player->Dequeue(&iAction);
	if (iAction == dfENTER)
	{
		CSceneMgr->_bChangeScene = true;
		CSceneMgr->_iNextScene = dfSCENE_STAGE1;
	}
}