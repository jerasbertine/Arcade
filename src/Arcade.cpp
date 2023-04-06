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
    if (std::filesystem::exists(path) == false)
        throw Error("File doesn't exist", "Error: ");
    checkLibPath(path);
}

void Arcade::fillLibVector(std::string lib)
{
    const std::string graphDico[] = {"sdl2.so", "sfml.so", "ncurses.so"};
    const std::string gameDico[] = {"pacman.so", "snake.so", "menu.so"};

    for (int i = 0; i < 3; ++i)
        if (lib == this->_libDir + "arcade_" + graphDico[i]) {
            this->_graphLib[graphDico[i].substr(0, graphDico[i].find(".so"))] = lib;
            return;
        }
    for (int i = 0; i < 3; ++i)
        if (lib == this->_libDir + "arcade_" + gameDico[i]) {
            this->_gameLib[gameDico[i].substr(0, gameDico[i].find(".so"))] = lib;
            return;
        }
    throw Error("We don't handle this kind of shared library.", "Error: ");
}

void Arcade::checkLibPath(std::string path)
{
    std::string gameDico[] = {"snake.so", "pacman.so", "menu.so"};
    std::string graphDico[] = {"sdl2.so", "sfml.so", "ncurses.so"};
    if (this->_graphLib.size() == 0)
        throw Error("There's no graphical library loaded.", "Error: ");
    if (this->_gameLib.size() == 0)
        throw Error("There's no game loaded.", "Error: ");
    for (int i = 0; i < 3; ++i)
        if (this->_libDir + "arcade_" + gameDico[i] == path) {
            this->_selectedGraph = std::make_shared<DLLoader<arcade::IGraphics>>(this->_graphLib["sfml"]);
            this->_selectedGame = std::make_shared<DLLoader<arcade::IGames>>(this->_gameLib[gameDico[i].substr(0, gameDico[i].find(".so"))]);
            this->_selectedGameStr = gameDico[i].substr(0, gameDico[i].find(".so"));
            this->_selectedGraphStr = "sfml";
            return;
        }
    for (int i = 0; i < 3; ++i)
        if (this->_libDir + "arcade_" + graphDico[i] == path) {
            this->_selectedGraph = std::make_shared<DLLoader<arcade::IGraphics>>(this->_graphLib[graphDico[i].substr(0, graphDico[i].find(".so"))]);
            this->_selectedGame = std::make_shared<DLLoader<arcade::IGames>>(this->_gameLib["menu"]);;
            this->_selectedGameStr = "menu";
            this->_selectedGraphStr = graphDico[i].substr(0, graphDico[i].find(".so"));
            return;
        }
}

void Arcade::handleChanges(arcade::Input state)
{
    switch (state) {
        case arcade::Input::NEXTGAME:
            if (this->_selectedGameStr != "menu") {
                this->_selectedGameStr = (this->_selectedGameStr == "snake" ? "pacman" : "snake");
                this->_selectedGame->changeInstance(this->_gameLib[this->_selectedGameStr]);
            }
            break;
        case arcade::Input::PREVIOUSGAME:
            if (this->_selectedGameStr != "menu") {
                this->_selectedGameStr = (this->_selectedGameStr == "snake" ? "pacman" : "snake");
                this->_selectedGame->changeInstance(this->_gameLib[this->_selectedGameStr]);
            }
            break;
        case arcade::Input::NEXTGRAPH:
            this->_selectedGraphStr = (this->_selectedGraphStr == "sfml" ? "sdl2" :
            this->_selectedGraphStr == "sdl2" ? "ncurses" : "sfml");
            this->_selectedGraph->changeInstance(this->_graphLib[this->_selectedGraphStr]);
            break;
        case arcade::Input::PREVIOUSGRAPH:
            this->_selectedGraphStr = (this->_selectedGraphStr == "sfml" ? "ncurses" :
            this->_selectedGraphStr == "ncurses" ? "sdl2" : "sfml");
            this->_selectedGraph->changeInstance(this->_graphLib[this->_selectedGraphStr]);
            break;
        default:
            break;
    }
}

void Arcade::menuChanges(arcade::Input state)
{
    switch (state) {
        case arcade::Input::RESTART:
            this->_selectedGameStr = "snake";
            this->_selectedGame->changeInstance(this->_gameLib[this->_selectedGameStr]);
            break;
        case arcade::Input::ACTION1:
            this->_selectedGameStr = "pacman";
            this->_selectedGame->changeInstance(this->_gameLib[this->_selectedGameStr]);
            break;
        default:
            break;
    }
}

Arcade::~Arcade()
{
}

void Arcade::check_up()
{
    arcade::Input state = arcade::Input::UNDEFINED;
    while ((state = this->_selectedGraph->getInstance()->event()) != arcade::Input::EXIT) {
        std::vector<std::shared_ptr<arcade::IObject>> vector;
        this->_selectedGraph->getInstance()->clear();
        vector.clear();
        vector = this->_selectedGame->getInstance()->loop(state);
        for (int i = 0; (std::size_t) i < vector.size(); ++i)
            this->_selectedGraph->getInstance()->draw(vector.at(i));
        this->_selectedGraph->getInstance()->display();
        handleChanges(state);
        if (this->_selectedGameStr == "menu")
            menuChanges(state);
    }
}