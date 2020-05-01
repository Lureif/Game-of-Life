# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:44:13 by brjorgen          #+#    #+#              #
#    Updated: 2020/02/03 08:27:39 by brjorgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = 	libft.a

CC     =	gcc

CFLAGS =	-Wall -Werror -Wextra -g

NAME   =	minilibsdl.a

SRCS   =	ft_sdl_error_handler.c 		\
		ft_sdl_check_quit.c		\
		ft_sdl_generic_event_loop.c 	\
		ft_sdl_renderer_init.c 		\
		ft_sdl_window_init.c		\
		ft_sdl_surface_init.c  		\
		ft_sdl_cleanup.c		\
		ft_sdl_full_init.c		


OBJ     =	$(SRCS:%.c=%.o)

HEADER  =	ft_minilibsdl.h

%.o	: 	%.c $(HEADER)
		$(CC) -o $@  -c $< $(CFLAGS)

all 	:	$(NAME)

$(NAME) : 	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean	:
		rm -rf $(OBJ)

fclean  : 	clean
		rm -rf $(NAME)

re 	: 	fclean all
