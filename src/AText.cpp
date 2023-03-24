/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** AText
*/

#include "../include/AText.hpp"

arcade::AText::AText()
{
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