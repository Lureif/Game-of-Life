#include "ft_minilibsdl.h"

bool	window_init(SDL_Window **window, const char *win_name, const size_t width, const size_t height)
{
	if (!win_name || !width || !height)
	{
		error_handler("USER", "window_init", MISSING_WIN_SPEC);
		return (false);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	if (!(*window = SDL_CreateWindow(win_name,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width,
					height,
					/*SDL_WINDOW_SHOWN*/ 0)))
	{
		error_handler("SDL", "window_init", SDL_ERROR);
		return (false);
	}
	return (true);
}
