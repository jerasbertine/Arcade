/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Error
*/

#include "../include/Error.hpp"

Error::Error(const std::string &message = "Error", const std::string &what = "Error") : _message(message), _what(what)
{
}

const char *Error::message() const noexcept
{
    return _message.c_str();
}

const char *Error::what() const noexcept
{
    return _what.c_str();
}

