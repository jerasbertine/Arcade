/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ATile
*/

#include "../include/ATile.hpp"

arcade::ATile::ATile()
{
    this->_texturePath = "";
    this->_position = {0, 0};
    this->_color = (arcade::Color) -1;
    this->_scale = {1, 1};
    this->_rotation = 0;
    this->_name = "";
    this->_event = arcade::Input::UNDEFINED;
    this->_originPosition = {0, 0};
    this->_originScale = {1, 1};
}

arcade::ATile::~ATile()
{
}

std::string arcade::ATile::getTexture() const
{
    return this->_texturePath;
}

std::pair<std::size_t, std::size_t> arcade::ATile::getPosition() const
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

std::pair<float, float> arcade::ATile::getScale() const
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

void arcade::ATile::setScale(std::pair<float, float> scale)
{
    this->_scale = scale;
}

void arcade::ATile::setRotation(float rotation)
{
    this->_rotation = rotation;
}

std::pair<float, float> arcade::ATile::getOriginScale()
{
    return this->_originScale;
}

std::pair<std::size_t, std::size_t> arcade::ATile::getOriginPosition()
{
    return this->_originPosition;
}

void arcade::ATile::setOriginScale(std::pair<float, float> scale)
{
    this->_originScale = scale;
}

void arcade::ATile::setOriginPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_originPosition = position;
}

void arcade::ATile::setEvent(arcade::Input event)
{
    this->_event = event;
}

arcade::Input arcade::ATile::getEvent() const
{
    return this->_event;
}

void arcade::ATile::setName(std::string name)
{
    this->_name = name;
}

std::string arcade::ATile::getName() const
{
    return this->_name;
}
