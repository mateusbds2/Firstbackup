#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game{
public:

	static Game* Instance(){
		if (m_pInstance == NULL){
			m_pInstance = new Game();
			return m_pInstance;
		}
		return m_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handlerEvents();
	void update();
	void draw();
	void clean();
	void quit();

	bool getRunning(){ return Running; }
	SDL_Renderer* getRenderer(){ return m_pRenderer; }

private:

	Game();
	static Game* m_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool Running;
	std::vector<GameObject*> m_GameObjects;

};

typedef Game TheGame;

#endif
