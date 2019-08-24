# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:16:52 by trobicho          #+#    #+#              #
#    Updated: 2019/08/24 18:54:24 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = game_op.c ft_validate.c \
		game_op_cycle.c get_next_line.c \
		stack_op.c main.c sort.c \
		lst_op.c

INCLUDES = -I includes/ -I libft/includes

OBJS = $(SRCS:.c=.o)

SRCS_PATH = srcs/
OBJS_PATH = obj/

SRC = $(addprefix $(SRCS_PATH), $(SRCS))
OBJ = $(addprefix $(OBJS_PATH), $(OBJS))

NAME = push_swap

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<

all: abc $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -lft -Llibft -o $(NAME)

abc:
	@$(MAKE) -C libft

clean:
	@$(MAKE) -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
