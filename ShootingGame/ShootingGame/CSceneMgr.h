#ifndef __SCENE_MGR__
#define __SCENE_MGR__
#include "BaseScene.h"
#include "BaseObject.h"

class CSceneManager
{
public:
	bool _bChangeScene;
	int _iNextScene;
	ObjectList<CBaseObject*> _lst;

	static CSceneManager *GetInstance(void);
	static void Destroy(void);
	void Run();
	void LoadScene(int Type);
	void CollisionCheck();

private:
	CSceneManager();	// Singleton
	static CSceneManager *_pCSceneMgr;
	CScene *pScene = nullptr;
};

extern CSceneManager * CSceneMgr;

#endif