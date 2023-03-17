##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-arcade-villon.zhang
## File description:
## Makefile
##

GAME1_PATH = game1 #name a changer

GAME2_PATH = game2 #name a changer

all:
	make -C $(GAME1_PATH)
	make -C $(GAME2_PATH)
#name a changer ^^^^

re: fclean all

clean:
	make clean -C $(GAME1_PATH)
	make clean -C $(GAME2_PATH)
#name a changer ^^^^


fclean: clean
	make fclean -C $(GAME1_PATH)
	make fclean -C $(GAME2_PATH)
#name a changer ^^^^

.PHONY: all re clean fclean