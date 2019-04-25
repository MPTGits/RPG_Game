#pragma once
#include "SDL.h"
#include <iostream>

class GameLoop
{
	private:
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
	public:
		GameLoop();
		~GameLoop();
		bool running() {
			return  isRunning;
		}
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

