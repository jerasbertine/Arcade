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

void SfmlArcade::drawText(arcade::IText *text)
{
    sf::Font font;

    // font.loadFromFile();         in case we have a font
    // this->_text.setFont(font);    same
    this->_text.setString(text->getText());
    this->_text.setCharacterSize(30);
    this->_text.setFillColor(sf::Color::White);
    this->_text.setPosition(text->getPosition().first, text->getPosition().second);
    this->_window->draw(this->_text);
}

void SfmlArcade::drawSprite(arcade::ITile *tile)
{
    this->_texture.loadFromFile(tile->getTexture());
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setPosition(tile->getPosition().first, tile->getPosition().second);
    this->_window->draw(this->_sprite);
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