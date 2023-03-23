/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Sfml_Arcade
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include "../include/Sfml_Arcade.hpp"

Sfml_Arcade::Sfml_Arcade()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade SFML!");
}

Sfml_Arcade::~Sfml_Arcade()
{
    delete(this->_window);
}

void Sfml_Arcade::display()
{
    this->_window->display();
}

void Sfml_Arcade::clear()
{
    this->_window->clear();
}

void Sfml_Arcade::draw(std::shared_ptr<arcade::IObject> object)
{
}

arcade::Input Sfml_Arcade::event()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            this->_window->close();
            return arcade::Input::EXIT;
        }
    }
    return arcade::Input::UNDEFINED;
}

extern "C" {
    void *entryPoint()
    {
        return new Sfml_Arcade();
    }
}