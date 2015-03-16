#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "SDLGameObject.h"

class Enemy : public SDLGameObject{
public:
	Enemy(const LoaderParams* pParams);

	virtual void update();
	virtual void draw();
	virtual void clean();
};

#endif
