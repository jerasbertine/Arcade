/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** main
*/

#include <iostream>

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade lib" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tlib\t\tlibrary in which the game will be played" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    return 0;
}
