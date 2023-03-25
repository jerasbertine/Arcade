/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ATile
*/

#include "../include/ATile.hpp"

arcade::ATile::ATile()
{
}

arcade::ATile::~ATile()
{
}

std::string arcade::ATile::getTexture() const
{
    return this->_texturePath;
}

std::pair<float, float> arcade::ATile::getPosition() const
{
    return this->_position;
}

char arcade::ATile::getCharacter() const
{
    return this->_char;
}

arcade::Color arcade::ATile::getColor() const
{
    return this->_color;
}

std::pair<std::size_t, std::size_t> arcade::ATile::getScale() const
{
    return this->_scale;
}

float arcade::ATile::getRotation() const
{
    return this->_rotation;
}

void arcade::ATile::setTexture(std::string path)
{
    this->_texturePath = path;
}

void arcade::ATile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_position = position;
}

void arcade::ATile::setCharacter(char c)
{
    this->_char = c;
}

void arcade::ATile::setColor(arcade::Color color)
{
    this->_color = color;
}

void arcade::ATile::setScale(std::pair<std::size_t, std::size_t> scale)
{
    this->_scale = scale;
}

void arcade::ATile::setRotation(float rotation)
{
    this->_rotation = rotation;
}
