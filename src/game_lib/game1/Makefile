##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

LIB_PATH = ../../../lib

SRC = 	main.cpp \
		$(addprefix src/,)

OBJ = $(SRC:.cpp=.o)

NAME = game1.so #name a changer

CC = g++

CFLAGS = -shared -fPIC

CPPFLAGS = -I./include

all: $(NAME)
	mv ./$(NAME) $(LIB_PATH)/$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_PATH)/$(NAME)

.PHONY: all re clean fclean