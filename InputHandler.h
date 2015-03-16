#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#include <SDL.h>
#include <vector>

#include "Vector2D.h"

enum mouse_buttons{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler{
public:
	static InputHandler* Instance()	{
		if (s_pInstance == 0)		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();

	bool getMouseButtonState(int buttonNumber){
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition(){
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);

	void reset();

private:
	InputHandler();

	static InputHandler* s_pInstance;
	std::vector<bool> m_mouseButtonStates;

	Vector2D* m_mousePosition;

	void onKeyDown();
	void onKeyUp();

	const Uint8* m_keystates;

	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
};

typedef InputHandler TheInputHandler;
#endif
