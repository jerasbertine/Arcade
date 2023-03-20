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

NAME = arcade_pacman.so

CC = g++

CFLAGS = -shared -fPIC

CPPFLAGS = -I./include

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

$(NAME): $(OBJ)
	@echo "$(BLUE)Linking [ $(GREEN)$(subst $(BUILD_DIR)//,,$(OBJ)) $(BLUE) -> $(RED) $@ $(BLUE) ]"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	@rm -f $(OBJ)
	@echo "$(ORANGE)Removing $(NAME)file.$(RESET)"

fclean: clean
	@rm -f $(LIB_PATH)/$(NAME)

.PHONY: all re clean fclean