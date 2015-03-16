#include "Player.h"
#include "InputHandler.h"
#include <iostream>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){
	m_currentFrame = 1;
	m_currentRow = 1;
}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update(){
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	SDLGameObject::update();
}

void Player::clean(){

}

void Player::handleInput(){
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
		m_velocity.setX(2);
		m_acceleration.setX(1);
		m_currentRow = 2;
		face = 1;
		m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	}
	else{
		m_velocity.setX(0);
		m_acceleration.setX(0);
		m_currentRow = 1;
		m_currentFrame = int(((SDL_GetTicks() / 100) % 5) + 5);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
		m_velocity.setX(-2);
		m_acceleration.setX(1);
		face = -1;
		m_currentRow = 2;
		m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	}
	else{
		//m_velocity.setX(0);
		//m_currentRow = 1;
		//m_acceleration.setX(0);
	}
}
