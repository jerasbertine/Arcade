/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Snake
*/

#include "../include/Snake.hpp"

Snake::Snake()
{

}

Snake::~Snake()
{

}

std::vector<std::shared_ptr<arcade::IObject>> Snake::loop(arcade::Input input)
{
    // TODO loop
    std::vector<std::shared_ptr<arcade::IObject>> vector;
    return vector;
}

void Snake::restart()
{
    return;
}

std::shared_ptr<arcade::ITile> Snake::createTile()
{
    // TODO createTile
    std::shared_ptr<arcade::ITile> tile;
    return tile;
}

std::shared_ptr<arcade::ISound> Snake::createSound()
{
    // TODO createSound
    std::shared_ptr<arcade::ISound> sound;
    return sound;
}

std::shared_ptr<arcade::IText> Snake::createText()
{
    //TODO createText
    std::shared_ptr<arcade::IText> text;
    return text;
}

extern "C" {
    void *entryPoint() {
        return new Snake();
    }
}