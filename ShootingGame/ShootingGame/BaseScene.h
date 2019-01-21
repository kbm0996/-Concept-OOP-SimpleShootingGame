#ifndef __SCENE__
#define __SCENE__
#include "_config.h"
#include <Windows.h>
#include "LinkedList.h"
#include "Draw.h"
class CScene
{
public:
	virtual ~CScene() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Action() = 0;
};

#endif