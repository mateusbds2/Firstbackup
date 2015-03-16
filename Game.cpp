#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game* Game::m_pInstance = 0;

Game::Game(){
	m_pWindow = 0;
	m_pRenderer = 0;
	Running = true;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	int flag = SDL_WINDOW_SHOWN;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		std::cout << SDL_GetError() << std::endl;
	}
	if (fullscreen == true){
		flag = SDL_WINDOW_FULLSCREEN;
	}
	m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
	if (m_pWindow == NULL){
		std::cout << SDL_GetError() << std::endl;
	}
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	if (m_pRenderer == NULL){
		std::cout << SDL_GetError() << std::endl;
	}

	TheTextureManager::Instance()->load("assets/Arthas/Arthas.png", "Arthas", m_pRenderer);

	m_GameObjects.push_back(new Player(new LoaderParams(100, 100, 46, 71, "Arthas")));

	return true;
}

void Game::handlerEvents(){
	TheInputHandler::Instance()->update();
}

void Game::update(){
	for (int i = 0; i < m_GameObjects.size(); i++){
		m_GameObjects[i]->update();
	}
}

void Game::draw(){
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
	SDL_RenderClear(m_pRenderer);
	for (int i = 0; i < m_GameObjects.size(); i++){
		m_GameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean(){
	for (int i = 0; i < m_GameObjects.size(); i++){
		m_GameObjects[i]->clean();
	}
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit(){
	Running = false;
}
