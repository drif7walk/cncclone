#ifndef IMAGEFU_HPP
#define IMAGEFU_HPP

#include <SDL.h>
#include "sysfu.hpp"
#include "errorMsg.hpp"


//SDL_Texture* CheckerPattern(int w, int h)
//{
//	/* TODO: Generate checker pattern for testing purposes.*/
//}

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
			ERRLOG("(EE) Unable to convert texture.");
		}
	}
	else
		ERRLOG("(EE) Unable to load image.");

	return texture;
}

void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;	

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

#endif
