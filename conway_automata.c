#include "conway.h"

void		populate_field(bool **field, size_t width, size_t height, t_e_FIELD_POPULATION POP_DENSITY)
{
	size_t x;
	size_t y;
	size_t x_offset;
	size_t y_offset;

	x = 0;
	y = 0;
	x_offset = 0;
	y_offset = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			switch (POP_DENSITY)
			{
			case LOW:
				x_offset = rand() % 10;
				y_offset = rand() % 5;
				break ;
			case MEDIUM:
				x_offset = rand() % 5;
				y_offset = rand() % 2;
				break ;
			case HIGH:
				x_offset = rand() % 2;
				y_offset = rand() % 2;
				break ;
			}
			(*field)[(y * width) + x] = (rand() % 2);
			x += x_offset;
		}
		y += y_offset;
	}
}

unsigned int	count_neighbours(bool *field, unsigned int field_width, unsigned int x, unsigned int y)
{
	unsigned int neighbour_count;

	neighbour_count = 0;
	//cardinals
	if (field[(((y - 1) * field_width) + x)]) 		//n
		neighbour_count++;
	if (field[(((y + 1) * field_width) + x)]) 		//s
		neighbour_count++;
	if (field[((y * field_width) + (x - 1))]) 		//w
		neighbour_count++;
	if (field[((y * field_width) + (x + 1))]) 		//e
		neighbour_count++;
	//combinations
	if (field[(((y - 1) * field_width) + (x - 1))]) 	//nw
		neighbour_count++;
	if (field[(((y - 1) * field_width) + (x + 1))]) 	//ne
		neighbour_count++;
	if (field[(((y + 1) * field_width) + (x - 1))]) 	//sw
		neighbour_count++;
	if (field[(((y + 1) * field_width) + (x + 1))]) 	//se
		neighbour_count++;
	return (neighbour_count);
}

bool	*get_field(size_t width, size_t height)
{
	bool *field;

	field = (bool *)malloc(sizeof(bool) * ((width + 1) * (height + 1)));
	if (!field)
		return NULL;
	bzero(field, (sizeof(bool) * (width + 1) * (height + 1)));
	return (field);
}


void	get_next_state(bool *field, bool **next_state, unsigned int field_width, unsigned int field_height)
{
	size_t neighbour_count;
	size_t x;
	size_t y;

	x = 1;
	y = 1;
	while (y < field_height - 1)
	{
		x = 1;
		while (x < field_width - 1)
		{
			neighbour_count = count_neighbours(field, field_width, x, y);
			if (field[(y * field_width) + x] == 1 && (neighbour_count > 3 || neighbour_count < 2))	// ded
				(*next_state)[(y * field_width) + x] = 0;
			else if (field[(y * field_width) + x] == 1 && (neighbour_count == 3 || neighbour_count == 2))
				(*next_state)[(y * field_width) + x] = 1;
			else if (field[(y * field_width) + x] == 0 && neighbour_count == 3)
				(*next_state)[(y * field_width) + x] = 1;
			x++;
		}
		y++;
	}
}

int	main(/* int ac, char **av */)
{	
	t_conway_utils	event_loop_utils;
	t_SDL_OBJS   	sdlobj;
	size_t		field_width;
	size_t		field_height;
	size_t		sleep_duration;


	if (!ft_sdl_full_init(&sdlobj, (size_t [2]){1000,1000}, "Conway's Game of Life", true))
	{
		printf("et nn mgl\n");
		ft_sdl_cleanup(&sdlobj, false);
		SDL_Quit();
		return (-1);
	}
	field_width = 100; 
	field_height = 100;
	sleep_duration = 1000;

	event_loop_utils = (t_conway_utils) {
		.field = get_field(field_width, field_height),
		.next_state = get_field(field_width, field_height),
		.field_width = field_width,
		.field_height = field_height,
		.sleep_duration =  sleep_duration,
		.density = MEDIUM,
	};
	populate_field(&event_loop_utils.field, field_width, field_height, MEDIUM),
	conway_loop(&sdlobj, &event_loop_utils);
	free(event_loop_utils.field);
	free(event_loop_utils.next_state);
	ft_sdl_cleanup(&sdlobj, false);
	SDL_Quit();
	return (0);
}
