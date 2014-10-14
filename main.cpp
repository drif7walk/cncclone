#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>

#include "prefs.h"
#include "imagefu.hpp"
#include "sysfu.hpp"
using namespace std;

int main(int argc, char** argv)
{
	/* Remove error log */
	remove("error.log");

	bool quit = false;
	SDL_Event e;

	ParseConfig();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		ERRLOG("(EE) SDL_INIT");
		return 1;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRW, SCRH, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		ERRLOG("(EE) Create window.");
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		ERRLOG("(EE) Unable to create renderer.");
		SDL_Quit();
		return 1;
	}

	/* Program loop */
	while (!quit)
	{
		/* Handle all events each iteration */
		while (SDL_PollEvent(&e)) 
		{
			switch (e.type)
			{
				case SDL_QUIT:
					quit = true; break;
				default: continue;
			}
		}

		//SDL_RenderClear(renderer); //xxx
		//renderTexture(buffer, renderer, x, y); //xxx
		//SSSDL_RenderPresent(renderer); //xxx
		
	}

	SDL_Quit();
	return 0;
}
