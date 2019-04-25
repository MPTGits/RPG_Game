#pragma once
#include "SDL.h"
#include "TextureManager.h"
class GameObject
{
	private:
		int xPoss;
		int yPoss;
		SDL_Texture * objectTexture;
		SDL_Rect srcRec;
		SDL_Rect destRec;
		SDL_Renderer* renderer;
	public:
	GameObject(const char* texture, SDL_Renderer* rend,int xPoss,int yPoss);
	void update();
	void render();
	~GameObject();
};

