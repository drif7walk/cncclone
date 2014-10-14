#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>

#include "prefs.h"
#include "imagefu.hpp"
#include "sysfu.hpp"
#include "renderer.hpp"
#include "errorMsg.hpp"

using namespace std;

int main(int argc, char** argv)
{
	/* Remove error log */
	remove("error.log");

	bool quit = false;
	SDL_Event e;


	ParseConfig();
	quit = renderer::initialize();
	

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
