#include "conway.h"

/*
** yes, most of this function's body could replaced by an auxiliary
** function pointer array check function. I did not do this because
** I couldn't be arsed to. Maybe it'll be the subject of my next
** update if ever I decide to update this.
*/

void		conway_loop(t_SDL_OBJS *sdl_objs, t_conway_utils *private)
{
	SDL_Event 	event;
	bool 		STATE;
	bool		pause;
	int		key;
	int		updown;

	STATE = true;
	pause = false;
	while (STATE == true)
	{
		while (SDL_PollEvent(&event))
		{
			key = event.key.keysym.sym;
			updown = event.type;
			if (ft_sdl_check_quit(event))
			{
				STATE = false;
				break;
			}
			if (updown == SDL_KEYDOWN && key == SDLK_r)
			{
				reset_field(private);
			}
			if (updown == SDL_KEYDOWN && key == SDLK_f)
			{
				change_speed(private, true);
			}
			if (updown == SDL_KEYDOWN && key == SDLK_s)
			{
				change_speed(private, false);
			}
			if (updown == SDL_KEYDOWN && key == SDLK_1)
			{
				change_population_density(private, LOW);
			}
			if (updown == SDL_KEYDOWN && key == SDLK_2)
			{
				change_population_density(private, MEDIUM);
			}
			if (updown == SDL_KEYDOWN && key == SDLK_3)
			{
				change_population_density(private, HIGH);
			}
			if (updown == SDL_KEYUP && key == SDLK_p)
			{
				pause_animation(&pause);
			}
			if (updown == SDL_KEYUP && key == SDLK_i)
			{
				iterate(sdl_objs, private);
			}
			if (updown == SDL_KEYUP && key == SDLK_d)
			{
				dump_state(private);
			}
		}
		if (!pause)
		{
			iterate(sdl_objs, private);
		}
		SDL_RenderPresent(sdl_objs->renderer);
		SDL_Delay(private->sleep_duration); // 16 for 60fps
	}
}
