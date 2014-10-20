#ifndef IMAGEFU_HPP
#define IMAGEFU_HPP

#include <SDL2/SDL.h>
#include "sysfu.hpp"

SDL_Texture* CheckerPatternTexture(SDL_Renderer* ren, int w, int h)
{
	/* Voodoo */
	SDL_Surface *surface;
    Uint32 rmask, gmask, bmask, amask;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
	       on the endianness (byte order) of the machine */
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	    rmask = 0xff000000;
	    gmask = 0x00ff0000;
	    bmask = 0x0000ff00;
	    amask = 0x000000ff;
	#else
	    rmask = 0x000000ff;
	    gmask = 0x0000ff00;
	    bmask = 0x00ff0000;
	    amask = 0xff000000;
	#endif

	    surface = SDL_CreateRGBSurface(0, w, h, 32,
		                           rmask, gmask, bmask, amask);
	    if(surface == NULL) {
		ERRLOG("E CreateRGBSurface failed ");
		exit(1);
	    }

            int bpp = surface->format->BytesPerPixel;
	    
	    for (int i = 0; i < w; i++)
		for (int j = 0; j<h; j++)
		{
		    Uint32 pixel = 0xFF00FFFF;
		    Uint8 *p = (Uint8 *)surface->pixels + i * surface->pitch + j * bpp;

		    if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
		    p[0] = (pixel >> 16) & 0xff;
		    p[1] = (pixel >> 8) & 0xff;
		    p[2] = pixel & 0xff;
		} else {
		    p[0] = pixel & 0xff;
		    p[1] = (pixel >> 8) & 0xff;
		    p[2] = (pixel >> 16) & 0xff;
		}
		
		*(Uint32 *)p = pixel;
		}
	    /* or using the default masks for the depth: */
	    surface = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);




	return SDL_CreateTextureFromSurface(ren, surface);
}

SDL_Texture* loadbmp(const string &filename, SDL_Renderer* ren)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* loadedimg = SDL_LoadBMP(filename.c_str());

	if (loadedimg != nullptr)
	{
		SDL_SetColorKey(loadedimg, 1, 0xff00ff);
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
