# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:57:24 by polenyc           #+#    #+#              #
#    Updated: 2024/02/23 17:03:46 by blackrider       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = libft.a

HEADERS_DIR = headers

HEADERS = -I$(HEADERS_DIR)

OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
SRC_DIR = printf
SRC_DIR_BONUS = printf_bonus
SRC := $(wildcard $(SRC_DIR)/*.c)
SRC_BONUS := $(wildcard $(SRC_DIR_BONUS)/*.c)
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)
CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror

.PHONY: all, re, clean, fclean

all: $(NAME)
	

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT_DIR)/$(LIBFT) ./
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGSO) $(HEADERS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) re
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

bonus: fclean $(OBJECTS_BONUS) $(LIBFT)
	cp $(LIBFT_DIR)/$(LIBFT) ./
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS_BONUS)
	ranlib $(NAME)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGSO) $(HEADERS) $< -o $@

re_bonus: fclean bonus