##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

SRC = 	main.cpp \
		$(addprefix src/, 	\
		DLLoader.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = arcade

CC = g++

CFLAGS = -Wall -Wextra -std=c++17 -fno-gnu-unique

CPPFLAGS = -I./include

GAMES_LIB = src/game_lib

GRAPH_LIB = src/graph_lib

all: $(NAME)
	make -C $(GAMES_LIB)
	make -C $(GRAPH_LIB)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	rm -f $(OBJ)
	make clean -C $(GAMES_LIB)
	make clean -C $(GRAPH_LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(GAMES_LIB)
	make fclean -C $(GRAPH_LIB)

core: $(NAME)

games:
	make -C $(GAMES_LIB)

graphicals:
	make -C $(GRAPH_LIB)

.PHONY: all re clean fclean debug core games graphicals