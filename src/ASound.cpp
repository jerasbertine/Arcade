/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ASound
*/

#include "../include/ASound.hpp"

ASound::ASound()
{
}

ASound::~ASound()
{
}

std::string ASound::getSoundPath() const
{
    return this->_soundPath;
}

float ASound::getVolume() const
{
    return this->_volume;
}

void ASound::setSoundPath(std::string path)
{
    this->_soundPath = path;
}

void ASound::setVolume(float volume)
{
    this->_volume = volume;
}

void ASound::pauseSound()
{
    return;
}

void ASound::playSound()
{
    return;
}

void ASound::stopSound()
{
    return;
}