#ifndef _SDLGAMEOBJECT_H_
#define _SDLGAMEOBJECT_H_

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject{
public:
	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	
protected:

	int face;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	int m_numRows;
	std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

};

#endif
