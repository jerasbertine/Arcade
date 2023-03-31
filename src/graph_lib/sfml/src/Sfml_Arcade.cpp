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
    this->_window->setFramerateLimit(60);
}

SfmlArcade::~SfmlArcade()
{
    this->_window->close();
    delete(this->_window);
}

void SfmlArcade::display()
{
    this->_window->display();
    this->clear();
}

void SfmlArcade::clear()
{
    this->_window->clear();
}

void SfmlArcade::handleTile(std::shared_ptr<arcade::ITile> tile)
{
    sf::RectangleShape sprite;
    sprite.setFillColor(this->dicolors[tile->getColor()]);
    sprite.setPosition(sf::Vector2f(tile->getPosition().first, tile->getPosition().second));
    sprite.setRotation(0);
    sprite.setScale(2,2);
    sprite.setSize(sf::Vector2f(15,15));
    this->_window->draw(sprite);
}

void SfmlArcade::handleSound(std::shared_ptr<arcade::ISound> sound)
{

}

void SfmlArcade::handleText(std::shared_ptr<arcade::IText> text)
{
    sf::Text _text;
    sf::Font _font;
    _font.loadFromFile("src/game_lib/pac-man/assets/Minecraft.ttf");
    _text.setFont(_font);
    _text.setFillColor(this->dicolors[text->getColorText()]);
    _text.setPosition(sf::Vector2f(text->getPosition().first, text->getPosition().second));
    _text.setRotation(0);
    _text.setScale(1, 1);
    _text.setCharacterSize(55);
    _text.setString(text->getText());
    this->_window->draw(_text);
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
    arcade::Input event = arcade::Input::UNDEFINED;

    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            event = arcade::EXIT;
        if (this->_event.type == sf::Event::KeyPressed) {
            if (this->_event.key.code == sf::Keyboard::Up)
                event = arcade::UP;
            if (this->_event.key.code == sf::Keyboard::Right)
                event = arcade::RIGHT;
            if (this->_event.key.code == sf::Keyboard::Down)
                event = arcade::DOWN;
            if (this->_event.key.code == sf::Keyboard::Left)
                event = arcade::LEFT;
            if (this->_event.key.code == sf::Keyboard::B)
                event = arcade::PREVIOUSGAME;
            if (this->_event.key.code == sf::Keyboard::N)
                event = arcade::NEXTGAME;
            if (this->_event.key.code == sf::Keyboard::G)
                event = arcade::PREVIOUSGRAPH;
            if (this->_event.key.code == sf::Keyboard::H)
                event = arcade::NEXTGRAPH;
            if (this->_event.key.code == sf::Keyboard::Escape)
                event = arcade::EXIT;
        }
    }
    return event;
}

extern "C" {
    void *entryPoint()
    {
        return new SfmlArcade();
    }
}