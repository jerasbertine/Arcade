/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ASound
*/

#include "../include/ASound.hpp"

arcade::ASound::ASound()
{
    this->_soundPath = "";
    this->_volume = 0;
}

arcade::ASound::~ASound()
{
}

std::string arcade::ASound::getSoundPath() const
{
    return this->_soundPath;
}

float arcade::ASound::getVolume() const
{
    return this->_volume;
}

void arcade::ASound::setSoundPath(std::string path)
{
    this->_soundPath = path;
}

void arcade::ASound::setVolume(float volume)
{
    this->_volume = volume;
}

void arcade::ASound::pauseSound()
{
    return;
}

void arcade::ASound::playSound()
{
    return;
}

void arcade::ASound::stopSound()
{
    return;
}