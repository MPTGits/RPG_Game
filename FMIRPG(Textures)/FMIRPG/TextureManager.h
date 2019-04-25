#pragma once
#include "GameLoop.h"
//Helper class that loads our images
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* texture, SDL_Renderer* renderer);
};

