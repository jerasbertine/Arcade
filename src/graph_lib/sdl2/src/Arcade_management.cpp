/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#include "../include/Arcade_management.hpp"

SdlArcade::SdlArcade()
{
}

SdlArcade::~SdlArcade()
{
}

void SdlArcade::display()
{
    std::cout << "Display" << std::endl;
}

void SdlArcade::clear()
{
    std::cout << "Refresh" << std::endl;
}

void SdlArcade::draw(std::shared_ptr<arcade::IObject> object)
{
}

arcade::Input SdlArcade::event()
{
    return arcade::Input::ACTION1;
}

extern "C" {
    void *entryPoint()
    {
        return new SdlArcade();
    }
}