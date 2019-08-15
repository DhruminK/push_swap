# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:16:52 by trobicho          #+#    #+#              #
#    Updated: 2019/08/15 19:19:23 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = game_op.c game_op_cycle.c get_next_line.c stack_op.c main.c

INCLUDES = -I includes/ -I libft/

OCONV = $(SRCS:.c=.o) $(GNL:.c=.o)

OUTS = $(addprefix srcs/, $(OCONV))

NAME = push_swap

all: $(NAME)

$(NAME): $(OUTS)
	make -C libft
	$(CC) $(OUTS) $(CFLAGS) -lft -Llibft -o $(NAME)

%.o : %.c $(HDRS)
	$(CC) $(INCLUDES) $(LIBFT) $(CFLAGS) -o $@ -c $<

clean:
	make -C libft clean
	rm -f $(OUTS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
