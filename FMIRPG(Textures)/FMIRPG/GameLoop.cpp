#include "GameLoop.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* playerObj;

GameLoop::GameLoop()
{
	this->counter = 0;
}


GameLoop::~GameLoop()
{
}

bool GameLoop::init(const char * title, int xPoss, int yPoss, int width, int height, bool fullscreen)
{
	//If we dont want any flags we set the flag value to 0
	int flag=0;
	if (fullscreen) {
		flag = SDL_WINDOW_FULLSCREEN;
	}
	//SDL_Init initilizes the SDL library and returns 0 if successful else and error
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "All of subsystems are initialized!" << std::endl;
		this->window = SDL_CreateWindow(title, xPoss, yPoss, width, height, flag);
		if (window != nullptr) {
			std::cout << "Window has been created!" << std::endl;
		}
		this->renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != nullptr) {
			SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 0);
			std::cout << "Renderer has been created!" << std::endl;
		}
		this->isRunning = true;
	}
	else {
		this->isRunning = false;
	}
	playerObj = new GameObject("Assets/AlgebraGuy.png", renderer, 0, 0);
	
	return this->isRunning;
}

void GameLoop::eventHandeler()
{
	SDL_Event event;
	//Returns 1 if there is a pending event or 0 if there are none available
	SDL_PollEvent(&event);
	switch (event.type) {
	//When we press X we generate an event that makes the running of the game to false
	case SDL_QUIT:
		this->isRunning = false;
		break;
	default:
		std::cout << "Unhandled event input!" << std::endl;
		break;
	}
}

void GameLoop::update()
{
	playerObj->update();
}

void GameLoop::render()
{
	SDL_RenderClear(this->renderer);
	playerObj->render();
	SDL_RenderPresent(this->renderer);
}

void GameLoop::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	delete[] playerObj;
	SDL_Quit();
	std::cout << "Game has been cleaned!" << std::endl;
}


