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

std::vector<std::shared_ptr<arcade::IObject>> Menu::loop(arcade::Input input)
{
    // TODO loop
    std::vector<std::shared_ptr<arcade::IObject>> vector;
    return vector;
}

void Menu::restart()
{
    return;
}

std::shared_ptr<arcade::ITile> Menu::createTile()
{
    // TODO createTile
    std::shared_ptr<arcade::ITile> tile;
    return tile;
}

std::shared_ptr<arcade::ISound> Menu::createSound()
{
    // TODO createSound
    std::shared_ptr<arcade::ISound> sound;
    return sound;
}

std::shared_ptr<arcade::IText> Menu::createText()
{
    //TODO createText
    std::shared_ptr<arcade::IText> text;
    return text;
}

extern "C" {
    void *entryPoint() {
        return new Menu();
    }
}