/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_
    #include <dlfcn.h>
    #include "DLLoader.hpp"
    #include "Error.hpp"
    #include "Arcade-Architecture/IGraphics.hpp"
    #include "../include/ASound.hpp"
    #include "../include/ATile.hpp"
    #include "../include/AText.hpp"

class Arcade {
    public:
        Arcade(std::string path);
        ~Arcade();
        void check_up();
    
    protected:
    private:
        std::shared_ptr<DLLoader<arcade::IGraphics>> _sharedLib;
        std::string _libDir;
    
};

#endif /* !ARCADE_HPP_ */
