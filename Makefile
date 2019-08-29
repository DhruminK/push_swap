# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:16:52 by trobicho          #+#    #+#              #
#    Updated: 2019/08/29 18:50:04 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = game_op.c ft_validate.c \
		game_op_cycle.c get_next_line.c \
		stack_op.c main.c sort_2.c \
		lst_op.c sort_util.c single_sort.c

INC = game_op.h get_next_line.h list_op.h sort.h stack.h vaildate.h

INCLUDES = -I includes/ -I libft/includes

OBJS = $(SRCS:.c=.o)

SRCS_PATH = srcs/
OBJS_PATH = obj/
INC_PATH = includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS))
OBJ = $(addprefix $(OBJS_PATH), $(OBJS))
DEPS = $(addprefix $(INC_PATH), $(INC))

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
