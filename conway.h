#ifndef CONWAY_H
# define CONWAY_H
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "./minilibsdl/ft_minilibsdl.h"

typedef enum	e_FIELD_POPULATION
{
	LOW,
	MEDIUM,
	HIGH,
}		t_e_FIELD_POPULATION;

typedef struct		s_conway_utils
{
	bool 	*field;
	bool 	*next_state;
	size_t 	field_width;
	size_t 	field_height;
	size_t	sleep_duration;
	t_e_FIELD_POPULATION density;
}			t_conway_utils;




bool		*get_field(size_t width, size_t height);
void		get_next_state(bool *field, bool **next_state, unsigned int field_width, unsigned int field_height);
unsigned int	count_neighbours(bool *field, unsigned int field_width, unsigned int x, unsigned int y);
void		populate_field(bool **field, size_t width, size_t height, t_e_FIELD_POPULATION POP_DENSITY);
void		display_scene(SDL_Renderer *renderer, bool *map);

void		conway_loop(t_SDL_OBJS *sdl_objs, t_conway_utils *private);
void		reset_field(t_conway_utils *private);
void		change_speed(t_conway_utils *private, bool faster);
void		pause_animation(bool *pause);
void		iterate(t_SDL_OBJS *sdl_objs, t_conway_utils *private);
void		change_population_density(t_conway_utils *private, t_e_FIELD_POPULATION new_density);
void		dump_state(t_conway_utils *private);

#endif
