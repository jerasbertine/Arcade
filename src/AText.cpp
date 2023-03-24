/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** AText
*/

#include "../include/AText.hpp"

AText::AText()
{
}

AText::~AText()
{
}

std::string AText::getText() const
{
    return this->_text;
}

arcade::Color AText::getColorText() const
{
    return this->_color;
}

std::pair<std::size_t, std::size_t> AText::getPosition() const
{
    return this->_position;
}

void AText::setText(std::string text)
{
    this->_text = text;
}

void AText::setColorText(arcade::Color color)
{
    this->_color = color;
}

void AText::setPosition(std::pair<std::size_t, std::size_t> position)
{
    this->_position = position;
}