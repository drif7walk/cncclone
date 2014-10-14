#ifndef SYSFU_HPP
#define SYSFU_HPP

#include <string.h>
using namespace std;

/* globals */
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

void ERRLOG(string errmsg);

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

			if      (!s.substr(0, i).compare("WindowWidth"))
			{	SCRW = atoi((char*)s.substr(i+1,s.length()).c_str());}
			else if (!s.substr(0, i).compare("WindowHeight"))
			{	SCRH = atoi((char*)s.substr(i+1,s.length()).c_str());}
			/* etc.  */

			
			
		}

		conffile.close();
	}
	else // File does not exist
	{
		ERRLOG("(II) Config file not found, a new one was generated.");
		ofstream conffile("cfg.silly");
		
		if (conffile.is_open())
		{
			conffile << "# Default configuration file" << endl;
			conffile << "# Lines beginning with # get ignored." << endl;
			conffile << "WindowWidth=800" << endl;
			conffile << "WindowHeight=600" << endl;
		}

		conffile.close();

		
		ParseConfig();
	}

}

void ERRLOG(string errmsg)
{
	/*
	X-style prefix
	(II) - Information
	(EE) - Error
	(WW) - Warning
	*/
	ofstream conffile("error.log");
		
	if (conffile.is_open())
	{
		conffile << (char*)errmsg.c_str();
	}

	conffile.close();
}

#endif
