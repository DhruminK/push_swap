# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:16:52 by trobicho          #+#    #+#              #
#    Updated: 2019/10/15 16:04:36 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = game_op.c ft_validate.c ft_validate_util.c \
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

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(DEPS)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
	@echo "Compiling $< to $@ \033[1;32m[OK]\033[0m"

$(INC_PATH)%.h:
	@echo $<

all: abc $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ)
	@$(CC) $(addprefix $(OBJS_PATH), $(OBJS)) \
		$(addprefix $(OBJS_PATH), $(PS:.c=.o)) \
		$(CFLAGS) -lft -Llibft -o $(NAME_PS)
	@echo "Compiling $@ \033[1;32m[OK]\033[0m"

$(NAME_CH): $(OBJ)
	@$(CC) $(addprefix $(OBJS_PATH), $(OBJS)) \
		$(addprefix $(OBJS_PATH), $(CH:.c=.o)) \
		$(CFLAGS) -lft -Llibft -o $(NAME_CH)
	@echo "Compiling $@ \033[1;32m[OK]\033[0m"

abc:
	@$(MAKE) -C libft

clean:
	@$(MAKE) -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\033[1m$(NAME_PS)\033[0m \
		: Cleaned $(OBJS_PATH) \033[1;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@/bin/rm -f $(NAME_PS) $(NAME_CH)
	@echo "$(NAME_PS) $(NAME_CH) binary deleted \033[1;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
