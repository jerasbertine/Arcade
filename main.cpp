/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** main
*/

#include <iostream>
#include "include/Arcade.hpp"

static void usage(void)
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t./arcade lib" << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\tlib\tlibrary in which the game will be played" << std::endl;
    std::cout << "\tYou might be able to find them in the lib/ folder" << std::endl;
    std::cout << "\tafter doing a \"make\" cmd" << std::endl;
}

int main(int ac, char **av)
{
    *av = NULL;
    std::shared_ptr<Arcade> arcade;

    if (ac != 2) {
        usage();
        return 84;
    }
    try {
        arcade = std::make_shared<Arcade>(av[1]);
        arcade->check_up();
    } catch (const Error &e) {
        std::cerr << e.what() << e.message() << std::endl;
        return 84;
    }
    return 0;
}
