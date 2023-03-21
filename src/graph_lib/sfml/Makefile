##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

LIB_PATH = ../../../lib

SRC = $(addprefix src/,	\
	Sfml_Arcade.cpp)

NAME = arcade_sfml.so

CC = g++

CFLAGS = -shared -fPIC

CPPFLAGS = -I./include

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

RED         := $(shell tput -Txterm setaf 1)

GREEN       := $(shell tput -Txterm setaf 2)

PURPLE       := $(shell tput -Txterm setaf 5)

BLUE        := $(shell tput -Txterm setaf 6)

WHITE       := $(shell tput -Txterm setaf 7)

ORANGE		:=	$(shell printf "\e[38;5;208m")

RESET 		:= $(shell tput -Txterm sgr0)

all: $(NAME)
	@echo "$(BLUE)Move [ $(RED)$(NAME) $(BLUE) -> $(PURPLE) $(LIB_PATH) $(BLUE) ]$(RESET)"
	@mv ./$(NAME) $(LIB_PATH)/$(NAME)

$(NAME):
	@echo "$(BLUE)Linking [ $(GREEN)$(subst $(BUILD_DIR)//,,$(SRC)) $(BLUE) -> $(RED) $@ $(BLUE) ]"
	@$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(SFMLFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	@echo "$(ORANGE)Removing $(NAME) file.$(RESET)"

fclean:
	@rm -f $(LIB_PATH)/$(NAME)

.PHONY: all re clean fclean