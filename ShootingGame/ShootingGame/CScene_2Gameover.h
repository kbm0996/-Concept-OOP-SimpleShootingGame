#ifndef __SCENE_OVER__
#define __SCENE_OVER__
#include "BaseScene.h"

class CScene_GAMEOVER : CScene
{
public:
	CScene_GAMEOVER();
	~CScene_GAMEOVER();
	void Update();
	void Draw() {}
	void Action() {}
};

#endif