/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** PacMan
*/

#include "../include/PacMan.hpp"

PacMan::PacMan()
{
}

PacMan::~PacMan()
{
}

std::vector<std::shared_ptr<arcade::IObject>> PacMan::loop(arcade::Input input)
{
    // TODO loop
    std::vector<std::shared_ptr<arcade::IObject>> vector;
    return vector;
}

void PacMan::restart()
{
    return;
}

std::shared_ptr<arcade::ITile> PacMan::createTile()
{
    // TODO createTile
    std::shared_ptr<arcade::ITile> tile;
    return tile;
}

std::shared_ptr<arcade::ISound> PacMan::createSound()
{
    // TODO createSound
    std::shared_ptr<arcade::ISound> sound;
    return sound;
}

std::shared_ptr<arcade::IText> PacMan::createText()
{
    //TODO createText
    std::shared_ptr<arcade::IText> text;
    return text;
}

extern "C" {
    void *entryPoint() {
        return new PacMan();
    }
}