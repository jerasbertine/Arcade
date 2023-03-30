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

SfmlArcade::SfmlArcade()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade SFML!");
}

SfmlArcade::~SfmlArcade()
{
    delete(this->_window);
}

void SfmlArcade::display()
{
    this->_window->display();
}

void SfmlArcade::clear()
{
    this->_window->clear();
}

void SfmlArcade::handleTile(std::shared_ptr<arcade::ITile> tile)
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile(tile->getTexture());
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(tile->getPosition().first, tile->getPosition().second));
    this->_window->draw(sprite);
}

void SfmlArcade::handleSound(std::shared_ptr<arcade::ISound> sound)
{

}

void SfmlArcade::handleText(std::shared_ptr<arcade::IText> text)
{

}

void SfmlArcade::draw(std::shared_ptr<arcade::IObject> object)
{
    std::shared_ptr<arcade::ITile> tile = std::dynamic_pointer_cast<arcade::ITile>(object);
    if (tile != nullptr) {
        handleTile(tile);
        return;
    }
    std::shared_ptr<arcade::ISound> sound = std::dynamic_pointer_cast<arcade::ISound>(object);
    if (sound != nullptr) {
        handleSound(sound);
        return;
    }
    std::shared_ptr<arcade::IText> text = std::dynamic_pointer_cast<arcade::IText>(object);
    if (text != nullptr) {
        handleText(text);
        return;
    }
}

arcade::Input SfmlArcade::event()
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
        return new SfmlArcade();
    }
}