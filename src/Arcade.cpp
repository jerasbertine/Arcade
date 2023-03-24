/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Arcade
*/

#include "../include/Arcade.hpp"
#include <memory>

Arcade::Arcade(std::string path)
{
    this->_sharedLib = std::make_shared<DLLoader<arcade::IGraphics>>(path);
}

Arcade::~Arcade()
{

}

void Arcade::check_up()
{
    arcade::Input state = arcade::Input::UNDEFINED;
    std::vector<std::shared_ptr<arcade::IObject>> test;
    std::shared_ptr<arcade::ATile> check = std::make_shared<arcade::ATile>();
    check->setTexture("src/graph_lib/sfml/assets/background.jpg");
    while ((state = this->_sharedLib->getInstance()->event()) != arcade::Input::EXIT) {
        this->_sharedLib->getInstance()->display();
        this->_sharedLib->getInstance()->clear();
        for (int i = 0; (std::size_t) i < test.size(); ++i) {
            this->_sharedLib->getInstance()->draw(check);
        }
    }
}