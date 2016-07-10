
#include "Box.h"
#include "commons.h"
#include "screen.h"

Box::Box()
{
	build_rect(rect, 100, 400, 100, 100);
}

void Box::update()
{
	if (last_tick(tick) > speed_to_ms(speed)) {
		//rect.x = rect.x + 1 * dirx;
		rect.y = rect.y + 1 * diry;

		if (rect.x >= SCREEN_W - rect.w)
			dirx = -1;

		if (rect.x <= 0)
			dirx = 1;

		if (rect.y >= SCREEN_H - rect.h)
			diry = -1;

		if (rect.y <= 400)
			diry = 1;

		update_tick(tick);

		speed = scale_speed(400, SCREEN_H - 100, 100, 400, rect.y);

		//printf("%d, %d, %d\n", speed, rect.x, rect.y);
	}
}

void Box::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x28, 0x28, 0x28, 0xFF);
	SDL_RenderFillRect(renderer, &rect);
}

