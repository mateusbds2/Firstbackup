#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"

class TextureManager{
public:
	static TextureManager* Instance(){
		if (m_pInstance == 0){
			m_pInstance = new TextureManager();
			return m_pInstance;
		}
		return m_pInstance;
	}
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer*	pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	static TextureManager* m_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif;
