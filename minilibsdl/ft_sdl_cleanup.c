#include "ft_minilibsdl.h"

void	ft_sdl_cleanup(t_SDL_OBJS *sdl_objs, bool surfacep)
{
	if (surfacep == true)
	{
		SDL_FreeSurface(sdl_objs->surface);
		printf("freed surface\n");
	}
	if (sdl_objs->renderer)
	{
		SDL_DestroyRenderer(sdl_objs->renderer);
		printf("doestroyed renderer\n");
	}
	if (sdl_objs->window)
	{
		SDL_DestroyWindow(sdl_objs->window);
		printf("destroyed window\n");
	}
}
