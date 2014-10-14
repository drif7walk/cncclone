#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>

#include "errorMsg.hpp"
#include "prefs.h"

namespace renderer
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* renderer;
	
	bool initialize()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			ERRLOG("(EE) SDL_INIT");
			return true;
		}

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRW, SCRH, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			ERRLOG("(EE) Create window.");
			SDL_Quit();
			return true;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr)
		{
			ERRLOG("(EE) Unable to create renderer.");
			SDL_Quit();
			return true;
		}
	}
}



#endif