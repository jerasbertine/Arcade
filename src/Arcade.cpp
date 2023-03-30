/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Arcade
*/

#include "../include/Arcade.hpp"
#include <memory>
#include <filesystem>

Arcade::Arcade(std::string path)
{
    int occ = path.find("arcade_");

    if ((size_t)occ == std::string::npos)
        throw Error("No lib where name start with \"arcade_\"", "Error: ");
    this->_libDir = path.substr(0, occ);
    for (const auto &entry : std::filesystem::directory_iterator(this->_libDir)) {
        std::string lib(entry.path());
        if (lib.find("arcade_") != std::string::npos)
            fillLibVector(lib);
    }
    checkLibPath(path);
}

void Arcade::fillLibVector(std::string lib)
{
    const std::string graphDico[] = {"sdl2.so", "sfml.so", "ncurses.so"};
    const std::string gameDico[] = {"pacman.so", "snake.so", "menu.so"};

    for (int i = 0; i < 3; ++i)
        if (lib == this->_libDir + "arcade_" + graphDico[i]) {
            std::shared_ptr<DLLoader<arcade::IGraphics>> loadedLib;
            this->_graphLib[graphDico[i].substr(0, graphDico[i].find(".so"))] = (loadedLib = std::make_shared<DLLoader<arcade::IGraphics>>(lib));
            return;
        }
    for (int i = 0; i < 3; ++i)
        if (lib == this->_libDir + "arcade_" + gameDico[i]) {
            std::shared_ptr<DLLoader<arcade::IGames>> loadedLib;
            this->_gameLib[gameDico[i].substr(0, gameDico[i].find(".so"))] = (loadedLib = std::make_shared<DLLoader<arcade::IGames>>(lib));
            return;
        }
    throw Error("We don't handle this kind of shared library.", "Error: ");
}

void Arcade::checkLibPath(std::string path)
{
    std::string gameDico[] = {"arcade_snake.so", "arcade_pacman.so", "arcade_menu.so"};
    std::string graphDico[] = {"arcade_sdl2.so", "arcade_sfml.so", "arcade_ncurses.so"};
    if (this->_graphLib.size() == 0)
        throw Error("There's no graphical library loaded.", "Error: ");
    if (this->_gameLib.size() == 0)
        throw Error("There's no game loaded.", "Error: ");
    for (int i = 0; i < 3; ++i)
        if (this->_libDir + gameDico[i] == path) {
            this->_selectedGraph = "sfml";
            this->_selectedGame = gameDico[i].substr(gameDico[i].find("_") + 1);
            this->_selectedGame = this->_selectedGame.substr(0, this->_selectedGame.find(".so"));
            return;
        }
    for (int i = 0; i < 3; ++i)
        if (this->_libDir + graphDico[i] == path) {
            this->_selectedGraph = graphDico[i].substr(graphDico[i].find("_") + 1);
            this->_selectedGraph = this->_selectedGraph.substr(0, this->_selectedGraph.find(".so"));
            this->_selectedGame = "menu";
            return;
        }
}

Arcade::~Arcade()
{
}

void Arcade::check_up()
{
    arcade::Input state = arcade::Input::UNDEFINED;
    while ((state = this->_graphLib[this->_selectedGraph]->getInstance()->event()) != arcade::Input::EXIT) {
        this->_graphLib[this->_selectedGraph]->getInstance()->display();
        this->_graphLib[this->_selectedGraph]->getInstance()->clear();
        for (int i = 0; (std::size_t) i < this->_gameLib[_selectedGame]->getInstance()->loop(state).size(); ++i) {
            this->_graphLib[_selectedGraph]->getInstance()->draw(this->_gameLib[_selectedGame]->getInstance()->loop(state).at(i));
        }
    }
}