/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::pushTile()
{
    std::shared_ptr<arcade::ITile> tile = createTile();
    tile->setTexture("src/graph_lib/sfml/assets/background.jpg");
    this->_vector.push_back(tile);
    std::shared_ptr<arcade::ITile> jeras = createTile();
    jeras->setTexture("src/graph_lib/sfml/assets/jeras.jpg");
    jeras->setPosition({50, 50});
    this->_vector.push_back(jeras);
}

void Menu::pushSound()
{
    std::shared_ptr<arcade::ISound> sound = createSound();
}

void Menu::pushText()
{
    std::shared_ptr<arcade::IText> text = createText();

}

std::vector<std::shared_ptr<arcade::IObject>> Menu::loop(arcade::Input input)
{
    this->_vector.clear();
    pushTile();
    pushSound();
    pushText();
    return this->_vector;
}

void Menu::restart()
{
    return;
}

std::shared_ptr<arcade::ITile> Menu::createTile()
{
    return std::make_shared<arcade::ATile>();
}

std::shared_ptr<arcade::ISound> Menu::createSound()
{
    return std::make_shared<arcade::ASound>();
}

std::shared_ptr<arcade::IText> Menu::createText()
{
    return std::make_shared<arcade::AText>();
}

extern "C" {
    void *entryPoint() {
        return new Menu();
    }
}