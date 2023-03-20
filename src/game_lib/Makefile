##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

PACMAN_PATH = pac-man

SNAKE_PATH = snake

all:
	@make -C $(PACMAN_PATH)
	@make -C $(SNAKE_PATH)

re: fclean all

clean:
	make clean -C $(PACMAN_PATH)
	make clean -C $(SNAKE_PATH)


fclean: clean
	make fclean -C $(PACMAN_PATH)
	make fclean -C $(SNAKE_PATH)

.PHONY: all re clean fclean