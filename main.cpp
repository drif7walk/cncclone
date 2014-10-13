#include <SDL2/SDL.h>

const int SCRW = 800;
const int SCRH = 600;

int main(int argc, char** argv)
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("yep. it iTwerks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRW, SCRH, SDL_WINDOW_SHOWN);

	

	SDL_Quit();
	return 0;
}
