#include "conway.h"

static void		draw_square(SDL_Renderer *renderer, size_t s_x, size_t s_y)
{
	SDL_SetRenderDrawColor(renderer, rand() % 100, rand() % 10, rand() % 255, rand() % 100);
	
	// square
	SDL_RenderDrawLine(renderer, s_x, s_y, s_x, s_y + 10);
	SDL_RenderDrawLine(renderer, s_x, s_y, s_x + 10, s_y);
	SDL_RenderDrawLine(renderer, s_x + 10, s_y + 10, s_x, s_y + 10);
	SDL_RenderDrawLine(renderer, s_x + 10, s_y, s_x + 10, s_y + 10);

	// cross
	SDL_RenderDrawLine(renderer, s_x, s_y + 10, s_x + 10, s_y);
	SDL_RenderDrawLine(renderer, s_x, s_y, s_x + 10, s_y + 10);				
	
}

void		display_scene(SDL_Renderer *renderer, bool *map)
{
	size_t x;
	size_t y;
	size_t s_x;
	size_t s_y;

	x = 0;
	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			if (map[(y * 100) + x] == 1)
			{
				draw_square(renderer, s_x, s_y);

				s_x = x * 10;
				s_y = y * 10;
			}
			x++;
		}
		y++;
	}
}
