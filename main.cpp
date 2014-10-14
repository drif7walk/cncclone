/*
TODO: Competend handling of resources!!!
*/

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>

#include "prefs.h"
#include "imagefu.hpp"
#include "sysfu.hpp"
#include "clonerenderer.hpp"

using namespace std;

int main(int argc, char** argv)
{
	/* Remove error log */
	remove("error.log");

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		ERRLOG("(EE) SDL_INIT");
		return 1;
	}

	/* Create window using sysfu.h */
	MakeWindow();

	/* Set up renderer */
	CloneRenderer* ren = new CloneRenderer();
	
	/* End renderer setup */

	bool quit = false;
	SDL_Event e;

	ParseConfig();

	/* XXX */
	double _fps = 1000/fps;

	/* testbed for demos */
	SDL_Texture* tex = loadbmp("assets/guy.bmp", ren->renderer);

	/* end testbed for demos */

	/* Program loop */
	while (!quit)
	{
		/* Handle all events each iteration */
		while (SDL_PollEvent(&e)) 
		{
			switch (e.type)
			{
				case SDL_QUIT:
					quit = true;
				default: continue;
			}
		}

		/* Rudimentary drawing */
		ren->Clear();

			/* demo */
			//renderTexture(buffer, renderer, x, y); //xxx
			ren->Render(tex, 10, 10);
			/* end demo */
		ren->Present();
		
		/* XXX */
		SDL_Delay(_fps);
	}

	SDL_DestroyTexture(tex);

	SDL_DestroyWindow(window);
	delete ren;


	SDL_Quit();
	return 0;
}
