# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 11:17:23 by dkhatri           #+#    #+#              #
#    Updated: 2019/10/15 15:42:56 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

MANDATORY = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c

ADDITIONAL = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			 ft_striter.c  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			 ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			 ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c \
			 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c

SRCC = $(MADATORY) $(ADDITIONAL) $(BONUS)
SRCO = $(MANDATORY:.c=.o) $(ADDITIONAL:.c=.o) $(BONUS:.c=.o)

SRC_PATH = srcs/
OBJ_PATH = obj/

OBJC = $(addprefix $(SRC_PATH), $(SRCC))
OBJO = $(addprefix $(OBJ_PATH), $(SRCO))

DEPS = libft.h

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/libft.h
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[1m$(NAME)\033[0m \
		: Compiling $< --> $@ \033[1;32m[OK]\033[0m"

all: $(NAME)

$(NAME): $(OBJO)
	@ar -rc $(NAME) $(OBJO)
	@echo "Compiling $@ \033[1;32m[OK]\033[0m"
	@ranlib $(NAME)
	@echo "Indexing $@ \033[1;32m[OK]\033[0m"

clean:
	@/bin/rm -f $(OBJO)
	@echo "\033[1m$(NAME)\033[0m : \
		$(OBJ_PATH) directory cleared \033[1;32m[OK]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) binary removed \033[1;32m[OK]\033[0m"

re: fclean all
