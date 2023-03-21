##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

SRC = 	main.cpp \
		$(addprefix src/, 	\
		DLLoader.cpp,		\
		Error.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = arcade

CC = g++

CFLAGS = -Wall -Wextra -std=c++17 -fno-gnu-unique -ldl

CPPFLAGS = -I./include

GAMES_LIB = src/game_lib

GRAPH_LIB = src/graph_lib

RED         := $(shell tput -Txterm setaf 1)

GREEN       := $(shell tput -Txterm setaf 2)

BLUE        := $(shell tput -Txterm setaf 6)

WHITE       := $(shell tput -Txterm setaf 7)

ORANGE		:=	$(shell printf "\e[38;5;208m")

RESET 		:= $(shell tput -Txterm sgr0)

all: $(NAME)
	@make -s -C $(GAMES_LIB)
	@make -s -C $(GRAPH_LIB)
	@echo "$(GREEN)All done$(RESET)"

$(NAME): $(OBJ)
	@echo "$(BLUE)Linking [ $(GREEN)$(subst $(BUILD_DIR)//,,$(OBJ)) $(BLUE) -> $(RED) $@ $(BLUE) ]"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

%.o:	%.cpp
	@echo "$(BLUE)Compiling [ $(GREEN)$(notdir $<)$(BLUE) -> $(ORANGE)$(notdir $@)$(BLUE) ]"
	@$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

debug: CFLAGS += -g3
debug: re

re: fclean all

clean:
	@rm -f $(OBJ)
	@echo "$(BLUE)Clean Game Lib$(RESET)"
	@make clean -s -C $(GAMES_LIB)
	@echo "$(BLUE)Clean Graph Lib$(RESET)"
	@make clean -s -C $(GRAPH_LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(GAMES_LIB)
	@make fclean -s -C $(GRAPH_LIB)
	@echo "$(ORANGE)Removing $(RED)$(NAME) $(RESET)"

core: $(NAME)

games:
	make -C $(GAMES_LIB)

graphicals:
	make -C $(GRAPH_LIB)

.PHONY: all re clean fclean debug core games graphicals