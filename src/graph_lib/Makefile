##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

NCURSES_PATH = ncurses

SDL2_PATH = sdl2

all:
	@make -C $(NCURSES_PATH)
	@make -C $(SDL2_PATH)

re: fclean all

clean:
	make clean -C $(NCURSES_PATH)
	make clean -C $(SDL2_PATH)

fclean: clean
	make fclean -C $(NCURSES_PATH)
	make fclean -C $(SDL2_PATH)

.PHONY: all re clean fclean