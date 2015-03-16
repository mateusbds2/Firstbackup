#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "LoaderParams.h"
#include <vector>

class GameObject{
public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

#endif
