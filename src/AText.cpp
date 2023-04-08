/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** AText
*/

#include "../include/AText.hpp"

arcade::AText::AText()
{
    this->_text = "";
    this->_color = arcade::Color::WHITE;
    this->_position = {0, 0};
    this->_rotation = 0;
    this->_name = "";
    this->_event = arcade::Input::UNDEFINED;
    this->_originPosition = {0, 0};
    this->_originScale = {1, 1};
}

arcade::AText::~AText()
{
}

std::string arcade::AText::getText() const
{
    return this->_text;
}

arcade::Color arcade::AText::getColorText() const
{
    return this->_color;
}

std::pair<std::size_t, std::size_t> arcade::AText::getPosition() const
{
    return this->_position;
}

void arcade::AText::setText(std::string text)
{
    this->_text = text;
}

void arcade::AText::setColorText(arcade::Color color)
{
    this->_color = color;
}

void arcade::AText::setPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_position = position;
}


std::pair<float, float> arcade::AText::getOriginScale()
{
    return this->_originScale;
}

std::pair<std::size_t, std::size_t> arcade::AText::getOriginPosition()
{
    return this->_originPosition;
}

void arcade::AText::setOriginScale(std::pair<float, float> scale)
{
    this->_originScale = scale;
}

void arcade::AText::setOriginPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_originPosition = position;
}

void arcade::AText::setEvent(arcade::Input event)
{
    this->_event = event;
}

arcade::Input arcade::AText::getEvent() const
{
    return this->_event;
}

void arcade::AText::setName(std::string name)
{
    this->_name = name;
}

std::string arcade::AText::getName() const
{
    return this->_name;
}

void arcade::AText::setScale(std::pair<float, float> scale)
{
    this->_scale = scale;
}

std::pair<float, float> arcade::AText::getScale() const
{
    return this->_scale;
}

void arcade::AText::setRotation(float rotation)
{
    this->_rotation = rotation;
}

float arcade::AText::getRotation() const
{
    return this->_rotation;
}