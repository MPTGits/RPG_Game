#include "GameLoop.h"


int main(int argc,char* argv[]) {
	/*
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window * mainWindow = SDL_CreateWindow("MainWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	
	SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
	
	SDL_SetRenderDrawColor(mainRenderer, 0, 25, 0, 25);
	
	SDL_RenderClear(mainRenderer);
	
	SDL_RenderPresent(mainRenderer);
	
	SDL_Delay(4000);
*/
	GameLoop* game = new GameLoop();

	game->init();
	
	while (game->running()) {
		game->eventHandeler();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}