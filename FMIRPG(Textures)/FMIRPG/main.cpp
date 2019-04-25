#include "GameLoop.h"

/* This is how to create a window
SDL_Init(SDL_INIT_EVERYTHING);
//Creates an sdl window
SDL_Window * mainWindow = SDL_CreateWindow("MainWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
//Creates and renderer with index -1(the index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags) and 0 flags
SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
//Setting color in RGB
SDL_SetRenderDrawColor(mainRenderer, 0, 25, 0, 25);
//https://wiki.libsdl.org/SDL_RenderClear
//Use this function to clear the current rendering target with the drawing color
SDL_RenderClear(mainRenderer);
//Use this function to update the screen with any rendering performed since the previous call.
SDL_RenderPresent(mainRenderer);

SDL_Delay(4000);
*/


int main(int argc,char* argv[]) {
	GameLoop* game = new GameLoop();
	//Good fps is 60(closes to screen refreshing)
	const int FPS = 60;
	//Max time we have between frames
	int frameDelay = 1000 / FPS;
	//long long is a type that is at least 64 bits		
	long long startFrame;
	long long currFrameTime;

	game->init();
	
	while (game->running()) {
		startFrame = SDL_GetTicks();
		
		game->eventHandeler();
		
		game->update();
		
		game->render();

		currFrameTime = SDL_GetTicks() - startFrame;
		//A lot more smoother frame rate with the delay
		if (frameDelay > currFrameTime){
			SDL_Delay(frameDelay- currFrameTime);
		}
	}
	game->clean();

	return 0;
}