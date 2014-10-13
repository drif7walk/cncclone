#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int SCRW = 800;
int SCRH = 600;
int foo = 1337;
void ParseConfig()
{
	/* open config then parse config */
	string s;
	ifstream conffile("cfg.silly");

	if (conffile.is_open()) // File exists
	{
		while(getline(conffile, s))
		{
			/* C++ does not do switch on strings, use if/else if/else if */
			if (s[0] == '#') continue; // comment
			
			/* find index */
			int i;
			for (i = 0; i < s.length(); i++) 
			{
				if (s[i] == '=') break;
			}
			if (i >= s.length()) continue;
			
			/* XXX */
			if      (!s.substr(0, i).compare("WindowWidth"))
			{	SCRW = atoi((char*)s.substr(i+1,s.length()).c_str());}
			else if (!s.substr(0, i).compare("WindowHeight"))
			{	SCRH = atoi((char*)s.substr(i+1,s.length()).c_str());}
			else if (!s.substr(0, i).compare("foo"))
			{	foo = atoi((char*)s.substr(i+1,s.length()).c_str());}
			/* etc.  */

			
			
		}

		conffile.close();
	}
	else // File does not exist :(
	{

	}

}

int main(int argc, char** argv)
{
	ParseConfig();

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("yep. it iTwerks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRW, SCRH, SDL_WINDOW_SHOWN);

	SDL_Delay(1000);

	SDL_Quit();
	return 0;
}
