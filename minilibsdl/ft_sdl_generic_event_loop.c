#include "ft_minilibsdl.h"

/*
**	This function is to be used as a template.
**	I personally have it in a yasnippet snippet.
*/

void		ft_sdl_generic_event_loop(t_SDL_OBJS *sdl_objs, void *private)
{
	SDL_Event 	event;	
	bool 		STATE;

	(void)private;
	(void)sdl_objs;
	STATE = true;
	while (STATE == true)
	{
		while (SDL_PollEvent(&event))
		{
			/* ================================================= */
			/* =============== EVENTS GO HERE ==================*/
			/* ================================================= */
			if (ft_sdl_check_quit(event))
			{
				STATE = false;
				break;
			}
//			SDL_RenderPresent(sdl_objs->renderer);
		}
		SDL_Delay(16); // 16 for 60fps
	}
}
