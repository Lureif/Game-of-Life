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

NAME   = 	game_of_life

CC     =	gcc

CFLAGS =	-Wall -Werror -Wextra -g

SRCS   =	./conway_automata.c \
		./conway_display.c \
		./conway_events.c \
		./conway_loop.c


OBJ     =	$(SRCS:%.c=%.o)

HEADER  =	conway.h ft_minilibsdl.h

INC	=	-I ./minilibsdl/

LIB	=	-L ./minilibsdl/SDL_SOURCE/lib/

%.o	: 	%.c $(HEADER)
		$(CC) $(INC) $(CFLAGS) -c $< -o $@

all 	:	$(NAME)

minilibsdl/minilibsdl.a:
		cd minilibsdl && make

$(NAME) : 	$(OBJ) minilibsdl/minilibsdl.a
		$(CC) $(OBJ) ./minilibsdl/minilibsdl.a $(CFLAGS) -o $(NAME) -lSDL2

clean	:
		rm -rf $(OBJ)
		cd minilibsdl && make clean

fclean  : 	clean
		rm -rf $(NAME)
		cd minilibsdl && make fclean

re 	: 	fclean all
