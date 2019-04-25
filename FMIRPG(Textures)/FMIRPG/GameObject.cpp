#include "GameObject.h"
#include "TextureManager.h"
	

GameObject::GameObject(const char* texture,SDL_Renderer* rend,int xPoss,int yPoss)
{
	this->renderer = rend;
	this->objectTexture = TextureManager::loadTexture(texture, rend);
	this->srcRec.h=64;
	this->srcRec.w = 64;
	//the x location of the rectangle's upper left corner
	this->srcRec.x = 0;
	//the y location of the rectangle's upper left corner
	this->srcRec.y = 0;
	this->destRec.h = srcRec.h*2;
	this->destRec.w = srcRec.w*2;	
	this->xPoss = xPoss;
	this->yPoss = yPoss;
}

void GameObject::update()
{
	++xPoss;
	++yPoss;
	this->destRec.x = xPoss;
	this->destRec.y = yPoss;
}

void GameObject::render()
{
	//Use this function to copy a portion of the texture to the current rendering target.
	SDL_RenderCopy(this->renderer, this->objectTexture, &srcRec, &destRec);
}


GameObject::~GameObject()
{
}
