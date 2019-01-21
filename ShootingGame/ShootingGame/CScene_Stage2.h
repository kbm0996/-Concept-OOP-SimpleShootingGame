#ifndef __SCENE_GAME2__
#define __SCENE_GAME2__
#include "BaseScene.h"

class CScene_GAME2 :CScene
{
public:
	CScene_GAME2();
	~CScene_GAME2();
	void Update();
	void Draw();
	void Action();

private:
	int _iRemainEnemy;
};

#endif