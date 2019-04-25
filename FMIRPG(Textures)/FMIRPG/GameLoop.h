#pragma once
#include "SDL.h"
//Lets us use images in sdl
#include "SDL_image.h"
#include <iostream>
//This class is responsiable for updating the SDL
class GameLoop
{
	private:
			
		int counter;
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
	public:
		GameLoop();
		~GameLoop();
		//Quick check if the game is still running
		bool running() {
			return  isRunning;
		}
		//Initilizing the game window 
		void init(const char* title="TITLE", 
					int xPoss=SDL_WINDOWPOS_CENTERED, 
					int yPoss=SDL_WINDOWPOS_CENTERED, 
					int width=800, 
					int height=600, 
					bool fullscreen=0);
		void eventHandeler();
		void update();
		void render();
		void clean();
		

};

