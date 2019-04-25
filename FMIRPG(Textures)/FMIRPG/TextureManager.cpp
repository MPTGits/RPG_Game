#include "TextureManager.h"

SDL_Texture * TextureManager::loadTexture(const char * texture, SDL_Renderer * renderer)
{
	SDL_Surface* tmpSurface=IMG_Load(texture);

	if (!tmpSurface) {
		std::cout << "No such image found!" << std::endl;
		exit(1);
	}	
	//We create a texture from a surface and then remove the surface
	//SDL_Texture=A structure that contains an efficient, driver-specific representation of pixel data.
	SDL_Texture* neededTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return neededTexture;
}
