#include "ft_minilibsdl.h"

bool	ft_sdl_full_init(t_SDL_OBJS *sdl_objs, const size_t dim[2], const char *wintitle, bool renderer) // this is going to have to change.
{
	unsigned char state[2];

	state[0] = window_init(&sdl_objs->window, wintitle, dim[0], dim[1]);
	if (renderer == true)
		state[1] = renderer_init(sdl_objs->window, &sdl_objs->renderer, dim[0], dim[1]);
	else
		state[1] = surface_init(&sdl_objs->surface, sdl_objs->window);
	return(state[0] & state[1]);
}
