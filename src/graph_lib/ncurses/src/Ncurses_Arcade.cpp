/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Ncurses_Arcade
*/

#include "../include/Ncurses_Arcade.hpp"

NcursesArcade::NcursesArcade()
{
}

NcursesArcade::~NcursesArcade()
{
}

void NcursesArcade::display()
{
    std::cout << "Display ncurses" << std::endl;
}

void NcursesArcade::clear()
{
    std::cout << "Refresh ncurses" << std::endl;
}

void NcursesArcade::draw(std::shared_ptr<arcade::IObject> object)
{
}

arcade::Input NcursesArcade::event()
{
    return arcade::Input::PREVIOUSGRAPH;
}

extern "C" {
    void *entryPoint() {
        return new NcursesArcade();
    }
}