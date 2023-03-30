/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_
    #include <dlfcn.h>
    #include <map>
    #include "DLLoader.hpp"
    #include "Error.hpp"
    #include "Arcade-Architecture/IGraphics.hpp"
    #include "Arcade-Architecture/IGames.hpp"
    #include "../include/ASound.hpp"
    #include "../include/ATile.hpp"
    #include "../include/AText.hpp"

class Arcade {
    public:
        Arcade(std::string path);
        ~Arcade();
        void check_up();
        void checkLibPath(std::string path);
        void fillLibVector(std::string lib);
    
    protected:
    private:
        std::string _selectedGraph;
        std::string _selectedGame;
        std::string _libDir;
        std::map<std::string, std::shared_ptr<DLLoader<arcade::IGraphics>>> _graphLib;
        std::map<std::string, std::shared_ptr<DLLoader<arcade::IGames>>> _gameLib;
    
};

#endif /* !ARCADE_HPP_ */
