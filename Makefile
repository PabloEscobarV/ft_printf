# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:57:24 by polenyc           #+#    #+#              #
#    Updated: 2023/12/07 13:43:20 by polenyc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

HEADERS_DIR = headers

HEADERS = -I$(HEADERS_DIR)

FILES = ft_printf.c ft_sprintf.c inttostr.c floattostr.c strtostr.c\
	adrtostr.c hextostr.c numtostr.c str_addfunc.c str_tolist.c findspec.c\
	add_func.c\

FILES_BONUS = ft_printf_bonus.c ft_sprintf_bonus.c inttostr_bonus.c\
	floattostr_bonus.c strtostr_bonus.c adrtostr_bonus.c hextostr_bonus.c\
	numtostr_bonus.c str_addfunc_bonus.c str_tolist_bonus.c findspec_bonus.c\
	add_fun_bonus.c uinttostr_bonus.c setflags_bonus.c\

OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
SRC_DIR = printf
SRC_DIR_BONUS = printf_bonus
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS))
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)
CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror

.PHONY: all, re, clean, fclean

all: $(NAME)
	

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) ./
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGSO) $(HEADERS) $< -o $@

$(LIBFT):
	$(MAKE) -C libft re
	$(MAKE) -C libft bonus

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

bonus: fclean $(OBJECTS_BONUS) $(LIBFT)
	cp $(LIBFT) ./
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS_BONUS)
	ranlib $(NAME)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGSO) $(HEADERS) $< -o $@

re_bonus: fclean bonus