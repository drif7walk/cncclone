/* 
Deals with rendering.
Anything that has anything to do with the screen ought to bottleneck through here.
*/

#ifndef CLONERENDERER_H
#define CLONERENDERER_H

#include <SDL2/SDL.h>

class CloneRenderer {
public:
	SDL_Renderer*	renderer;



	/* Methods */


	void Render(SDL_Texture* tex, int x, int y)
	{
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;

		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
		SDL_RenderCopy(this->renderer, tex, NULL, &dst);
	}

	void Clear() { SDL_RenderClear(this->renderer); }
	void Present() { SDL_RenderPresent(this->renderer); }

	CloneRenderer()
	{
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (this->renderer == nullptr) {
			ERRLOG("E Unable to create renderer.");
		}
		ERRLOG("I Created renderer.");
	}
	~CloneRenderer()
	{
		SDL_DestroyRenderer(this->renderer);
	}


} clRen;

#endif
