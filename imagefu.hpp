#ifndef IMAGEFU_HPP
#define IMAGEFU_HPP

#include <SDL2/SDL.h>
#include "sysfu.hpp"

SDL_Texture* loadbmp(char* filename, SDL_Renderer* ren)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* loadedimg = SDL_LoadBMP(filename);
	
	if (loadedimg != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(ren, loadedimg);
		SDL_FreeSurface(loadedimg);

		if (texture == nullptr)
		{
			ERRLOG("(EE) Unable to load image.");
		}
	}
}

#endif
