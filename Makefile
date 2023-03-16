##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

SRC = 	main.cpp \
		$(addprefix src/, 	\
		)

OBJ = $(SRC:.cpp=.o)

NAME = arcade

CC = g++

CFLAGS = -Wall -Wextra -std=c++17

CPPFLAGS = -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean debug