#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>
#include "Vec2.hpp"


class Sprite {

private:
	SDL_Texture* texture;
	Vec2 position;

public:

	SDL_Texture* getTexture() { return this->texture; }
	Vec2 GetPosition() { return position; }

	Sprite();
	~Sprite();

};

#endif
