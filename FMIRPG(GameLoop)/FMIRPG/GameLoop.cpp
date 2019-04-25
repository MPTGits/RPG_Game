#include "GameLoop.h"


GameLoop::GameLoop()
{

}


GameLoop::~GameLoop()
{
}

void GameLoop::init(const char * title, int xPoss, int yPoss, int width, int height, bool fullscreen)
{
	int flag=0;
	if (fullscreen) {
		flag = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "All of subsystems are initialized!" << std::endl;
		this->window = SDL_CreateWindow(title, xPoss, yPoss, width, height, flag);
		if (window != nullptr) {
			std::cout << "Window has been created!" << std::endl;
		}
		this->renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != nullptr) {
			SDL_SetRenderDrawColor(this->renderer, 0, 10, 200, 0);
			std::cout << "Renderer has been created!" << std::endl;
		}
		this->isRunning = true;
	}
	else {
		this->isRunning = false;
	}
}

void GameLoop::eventHandeler()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		this->isRunning = false;
		break;
	default:
		std::cout << "Unhandled event input!" << std::endl;
	}
}

void GameLoop::update()
{
}

void GameLoop::render()
{
	SDL_RenderClear(this->renderer);
	//We add stuff to renderer here 
	SDL_RenderPresent(this->renderer);
}

void GameLoop::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	std::cout << "Game has been cleaned!" << std::endl;
}


