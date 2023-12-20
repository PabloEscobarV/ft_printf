# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 14:44:45 by polenyc           #+#    #+#              #
#    Updated: 2023/12/20 18:24:43 by polenyc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC = test.c
OBJECTS = $(SRC:%.c=%.o)
LIB = libftprintf.a
HEAD_DIR = headers
HEADERS = -I$(HEAD_DIR)

CC = gcc
CFLAGSO = -c -Wall -Wextra
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS)
	rm -f $(LIB)
	cp ../res/res1/$(LIB) ./
	$(CC) $(OBJECTS) -g -o $(NAME) $(HEADERS) -L. $(LIB)

%.o: %.c
	$(CC) $(CFLAGSO) $(HEADERS) -g $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)