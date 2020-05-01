#include "ft_minilibsdl.h"

bool	ft_sdl_check_quit(SDL_Event event)
{
	if (event.type == SDL_QUIT ||
	    (event.type == SDL_KEYDOWN &&
	     event.key.keysym.sym == SDLK_ESCAPE))
		return (true);
	return (false);
}
