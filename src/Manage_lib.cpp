/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Manage_lib
*/

#include "../include/Manage_lib.hpp"
#include <memory>

Manage_lib::Manage_lib()
{
}

Manage_lib::~Manage_lib()
{
}

void check_up(std::string path)
{
    std::shared_ptr<DLLoader<arcade::IGraphics>> libSfml = std::make_shared<DLLoader<arcade::IGraphics>>(path);
    arcade::Input state = arcade::Input::UNDEFINED;
    std::shared_ptr<arcade::IObject> check;
    while ((state = libSfml->getInstance()->event()) != arcade::Input::EXIT) {
        libSfml->getInstance()->display();
        libSfml->getInstance()->clear();
        libSfml->getInstance()->draw(check);
    }
}