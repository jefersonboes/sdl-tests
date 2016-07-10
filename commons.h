#ifndef COMMONS_H
#define COMMONS_H

#include <SDL.h>

void inline build_rect(SDL_Rect &rect, int x, int y, int w, int h)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

int inline speed_to_ms(int speed) {
	float ms = 1 / ((float)speed / 1000);

	return (int)ms;
}

int inline scale_speed(int min_pos, int max_pos, int min_speep, int max_speed, int pos)
{
	float percent = (float) (pos - min_pos) / (float) (max_pos - min_pos);

	return (max_speed - min_speep) * percent + min_speep;
	
}

void inline update_tick(int &tick)
{
	tick = SDL_GetTicks();
}

int inline last_tick(int tick) {
	return SDL_GetTicks() - tick;
}

#endif

