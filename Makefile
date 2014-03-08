#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:46 by vlehuger          #+#    #+#              #
#    Updated: 2014/03/08 17:58:12 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC =		cc

FLAGS =		-Wall -Wextra -Werror

NAME =		puissance_4

SRCS =		\
			srcs/main.c\
			srcs/create_grid.c\
			srcs/display.c\
			srcs/two_players.c\
			srcs/one_player.c\
			srcs/get_token.c\
			srcs/place_token.c\
			srcs/test_win.c\
			srcs/tabdup.c\
			srcs/freetab.c\
			srcs/ai.c\

OBJS =		$(SRCS:.c=.o)

LIBFT =		-L ./libft -lft

HEADLIB =	-I ./libft/includes

LEMINLIB = -I ./includes

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) -o $(NAME) $(OBJS) $(LIBFT)

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $< $(HEADLIB) $(LEMINLIB)

clean:
			make clean -C libft/
			rm -f $(OBJS)

fclean:		clean
			make fclean -C libft/
			rm -f $(NAME)

re :		fclean all

.PHONY:		clean
