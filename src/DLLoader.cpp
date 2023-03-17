/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** DLLoader
*/

#include "../include/DLLoader.hpp"

template<typename T>
DLLoader<T>::DLLoader()
{
}


template<typename T>
DLLoader<T>::~DLLoader()
{
}

template<typename T>
T *DLLoader<T>::getInstance() const
{
    return _instance;
}