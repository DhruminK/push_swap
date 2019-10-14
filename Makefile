# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:16:52 by trobicho          #+#    #+#              #
#    Updated: 2019/10/14 20:16:10 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = game_op.c ft_validate.c \
		game_op_cycle.c get_next_line.c \
		stack_op.c sort_bubble.c sort.c \
		lst_op.c sort_util.c quicksort_arr.c \
		get_ins.c sort_quick.c sort_quick2.c \
		sort_insertion.c game_rules.c ft_sort_b_less.c

PS = main.c
CH = checker_main.c

INC = game_op.h get_next_line.h list_op.h sort.h stack.h vaildate.h

INCLUDES = -I includes/ -I libft/includes

OBJS = $(SRCS:.c=.o)

ALOBJ = $(OBJS) $(PS:.c=.o) $(CH:.c=.o)

SRCS_PATH = srcs/
OBJS_PATH = obj/
INC_PATH = includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS))
OBJ = $(addprefix $(OBJS_PATH), $(ALOBJ))
DEPS = $(addprefix $(INC_PATH), $(INC))

NAME_PS = push_swap
NAME_CH = checker

%.o: $(SRCS_PATH)%.c includes/main.h
	$(CC) $(INCLUDES) $(CFLAGS) -o $(OBJS_PATH)$@ -c $<

all: abc $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(ALOBJ)
	$(CC) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(PS:.c=.o)) $(CFLAGS) -lft -Llibft -o $(NAME_PS)

$(NAME_CH): $(ALOBJ)
	$(CC) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(CH:.c=.o)) $(CFLAGS) -lft -Llibft -o $(NAME_CH)

abc:
	@$(MAKE) -C libft

clean:
	@$(MAKE) -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft/ fclean
	rm -f $(NAME_PS) $(NAME_CH)

re: fclean all

vpath %.c srcs

vpath %.h includes

.PHONY: all clean fclean re
