/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** main
*/

#include <iostream>

static void usage(void)
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t./arcade lib" << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\tlib\tlibrary in which the game will be played" << std::endl;
    std::cout << "You might be able to find them in the lib/ folder" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        usage();
    else
        std::cout << "You chose " << av[1] << std::endl;
    return 0;
}
