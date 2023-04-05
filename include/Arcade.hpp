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
        void handleChanges(arcade::Input state);
        void menuChanges(arcade::Input state);
    
    protected:
    private:
        std::shared_ptr<DLLoader<arcade::IGraphics>> _selectedGraph;
        std::shared_ptr<DLLoader<arcade::IGames>> _selectedGame;
        std::string _selectedGameStr;
        std::string _selectedGraphStr;
        std::map<std::string, std::string> _graphLib;
        std::map<std::string, std::string> _gameLib;
        std::string _libDir;
    
};

#endif /* !ARCADE_HPP_ */
