/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ATile
*/

#include "../include/ATile.hpp"

ATile::ATile()
{
}

ATile::~ATile()
{
}

std::string ATile::getTexture() const
{
    return this->_texturePath;
}

std::pair<float, float> ATile::getPosition() const
{
    return this->_position;
}

char ATile::getCharacter() const
{
    return this->_char;
}

arcade::Color ATile::getColor() const
{
    return this->_color;
}

std::pair<std::size_t, std::size_t> ATile::getScale() const
{
    return this->_scale;
}

float ATile::getRotation() const
{
    return this->_rotation;
}

void ATile::setTexture(std::string path)
{
    this->_texturePath = path;
}

void ATile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_position = position;
}

void ATile::setCharacter(char c)
{
    this->_char = c;
}

void ATile::setColor(arcade::Color color)
{
    this->_color = color;
}

void ATile::setScale(std::pair<std::size_t, std::size_t> scale)
{
    this->_scale = scale;
}

void ATile::setRotation(float rotation)
{
    this->_rotation = rotation;
}
