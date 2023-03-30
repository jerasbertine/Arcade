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

void Menu::pushHomeMenu()
{
    std::shared_ptr<arcade::ITile> texture[3];

    for (int i = 0; i < 2; ++i)
        texture[i] = createTile();
    // Background du menu
    texture[0]->setTexture("src/game_lib/menu/assets/background.jpg");
    // Panneau contenant le text "Arcade"
    texture[1]->setTexture("src/game_lib/menu/assets/sign.png");
    texture[1]->setPosition({460, 100});
    for (int i = 0; i < 2; ++i)
        this->_vector.push_back(texture[i]);
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
    pushHomeMenu();
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