#ifndef __SCENE_GAME1__
#define __SCENE_GAME1__
#include "BaseScene.h"

class CScene_GAME1 :CScene
{
public:
	CScene_GAME1();
	~CScene_GAME1();
	void Update();
	void Draw();
	void Action();

private:
	int _iRemainEnemy;
};

#endif