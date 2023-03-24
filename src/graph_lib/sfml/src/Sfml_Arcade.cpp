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
    std::shared_ptr<arcade::ITile> tile = std::dynamic_pointer_cast<arcade::ITile>(object);
    if (tile != nullptr) {
        this->_texture.loadFromFile(tile->getTexture());
        this->_sprite.setTexture(this->_texture);
        this->_window->draw(this->_sprite);
        return;
    }
    std::shared_ptr<arcade::ISound> sound = std::dynamic_pointer_cast<arcade::ISound>(object);
    if (sound != nullptr) {
        // this->_texture.loadFromFile(tile->getTexture());
        // this->_sprite.setTexture(this->_texture);
        // this->_window->draw(this->_sprite);
        return;
    }
    std::shared_ptr<arcade::IText> text = std::dynamic_pointer_cast<arcade::IText>(object);
    if (text != nullptr) {
        // this->_texture.loadFromFile(tile->getTexture());
        // this->_sprite.setTexture(this->_texture);
        // this->_window->draw(this->_sprite);
        return;
    }
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