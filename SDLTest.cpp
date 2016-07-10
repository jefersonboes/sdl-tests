
#include <SDL.h>
#include "commons.h"
#include "screen.h"
#include "Box.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int ti;

#define BOX_COUNT 1

Box box[BOX_COUNT];

void update()
{
	for (int i = 0; i < BOX_COUNT; i++)
		box[i].update();
}

void draw(SDL_Renderer *renderer)
{
	if (last_tick(ti) >= SCREEN_TICKS_PER_FRAME) {
		//printf("ltick %d, %d\n", last_tick(ti), SCREEN_TICKS_PER_FRAME);

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		
		for (int i = 0; i < BOX_COUNT; i++)
			box[i].draw(renderer);

		SDL_RenderPresent(renderer);

		update_tick(ti);
	}
	else {
		SDL_Delay(1);
	}
}

int main(int argc, char** argv)
{
	SDL_Event event; 
	int quit = 0; 

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;

	window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	if (window == NULL) { printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); }

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	update_tick(ti);

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) 
			{
				quit = 1;
			}
		}

		update();
		draw(renderer);
	}

	SDL_Quit();

	return 0;
}

