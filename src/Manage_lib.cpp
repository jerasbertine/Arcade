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

void menu() {

}

void check_up(std::string path)
{
    std::shared_ptr<DLLoader<arcade::IGraphics>> sharedLib = std::make_shared<DLLoader<arcade::IGraphics>>(path);
    arcade::Input state = arcade::Input::UNDEFINED;
    std::shared_ptr<arcade::ATile> check = std::make_shared<arcade::ATile>();
    check->setTexture("src/graph_lib/sfml/assets/background.jpg");
    while ((state = sharedLib->getInstance()->event()) != arcade::Input::EXIT) {
        sharedLib->getInstance()->display();
        sharedLib->getInstance()->clear();
        sharedLib->getInstance()->draw(check);
    }
}