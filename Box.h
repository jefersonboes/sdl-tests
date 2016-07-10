#ifndef BOX_H
#define BOX_H

#include <SDL.h>

class Box
{
private:
	SDL_Rect rect;
	int tick = SDL_GetTicks();
	int speed = 400;
	int dirx = 1;
	int diry = 1;
public:
	Box();
	virtual void update();
	virtual void draw(SDL_Renderer *renderer);
};

#endif

