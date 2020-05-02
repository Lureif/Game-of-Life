#include "conway.h"
#include <stdio.h>

void		dump_state(t_conway_utils *private)
{
	FILE *file;
	size_t i;

	i = 0;
	file = fopen("state_dump.gol", "w");
	while (i < (private->field_width * private->field_height))
	{
		if ((i % private->field_width == 0) && i != 0)
			fprintf(file, "\n");
		fprintf(file, "%d", private->field[i]);
		i++;
	}
	fprintf(file, "\n");
	fclose (file);
}

void		change_population_density(t_conway_utils *private, t_e_FIELD_POPULATION new_density)
{
	private->density = new_density;
}

void		reset_field(t_conway_utils *private)
{
	bzero(private->next_state, (private->field_width + 1) * (private->field_height + 1));
	bzero(private->field, (private->field_width + 1) * (private->field_height + 1));
	populate_field(&private->field, private->field_width, private->field_height, private->density);
}

void		change_speed(t_conway_utils *private, bool faster)
{
	if (faster && private->sleep_duration - 50 >= 50)
		private->sleep_duration -= 50;
	else if  (!faster && private->sleep_duration <= 1000)
		private->sleep_duration += 50;

}

void		pause_animation(bool *pause)
{
	if (!*pause)
		*pause = true;
	else 
		*pause = false;
}

void		iterate(t_SDL_OBJS *sdl_objs, t_conway_utils *private)
{
	// clear next state
	bzero(private->next_state, (private->field_height + 1) * (private->field_width + 1));
	// clear screen
	SDL_SetRenderDrawColor(sdl_objs->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_objs->renderer);
	// next scene
	get_next_state(private->field,
		       &private->next_state,
		       private->field_width,
		       private->field_height);
	// display scene
	display_scene(sdl_objs->renderer, private->next_state);
	memcpy(private->field, private->next_state, 10000);
}
