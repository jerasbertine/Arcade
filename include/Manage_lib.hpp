/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Manage_lib
*/

#ifndef MANAGE_LIB_HPP_
#define MANAGE_LIB_HPP_

#include <dlfcn.h>
#include "DLLoader.hpp"
#include "Arcade-Architecture/IGraphics.hpp"

class Manage_lib {
    public:
        Manage_lib();
        ~Manage_lib();
    
    protected:
    private:
};

void check_up(std::string path);

#endif /* !MANAGE_LIB_HPP_ */
