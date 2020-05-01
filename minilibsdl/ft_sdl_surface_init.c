#include "ft_minilibsdl.h"

bool	surface_init(SDL_Surface **win_surface, SDL_Window *window)
{
	if (!(*win_surface = SDL_GetWindowSurface(window)))
	{
		error_handler("SDL", "surface_init", SDL_ERROR);
		return (false);
	}
	return (true);
}
