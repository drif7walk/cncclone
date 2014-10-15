#ifndef IMAGEFU_HPP
#define IMAGEFU_HPP

#include <SDL2/SDL.h>
#include "sysfu.hpp"

SDL_Texture* CheckerPattern(int w, int h)
{
	/* TODO: Generate checker pattern for testing purposes.*/
	SDL_Texture* texture = nullptr;
	return texture;
}

SDL_Texture* loadbmp(const string &filename, SDL_Renderer* ren)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* loadedimg = SDL_LoadBMP(filename.c_str());

	if (loadedimg != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(ren, loadedimg);

		SDL_FreeSurface(loadedimg);

		if (texture == nullptr)
		{
			ERRLOG(SDL_GetError());
		}
	}
	else
		ERRLOG("E Unable to load image.");

	ERRLOG("I Loaded texture.");

	return texture;
}

#endif