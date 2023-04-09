/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Ncurses_Arcade
*/

#include "../include/Ncurses_Arcade.hpp"

NcursesArcade::NcursesArcade()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    refresh();
    start_color();
    init_pair(arcade::Color::BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(arcade::Color::GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(arcade::Color::RED, COLOR_RED, COLOR_RED);
    init_pair(arcade::Color::YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(arcade::Color::WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(arcade::Color::DARK, COLOR_BLACK, COLOR_BLACK);
}

NcursesArcade::~NcursesArcade()
{
    echo();
    nodelay(stdscr, FALSE);
    endwin();
}

void NcursesArcade::display()
{
    
}

void NcursesArcade::clear()
{
    ::clear();
    refresh();
    wrefresh(stdscr);
}

void NcursesArcade::handleTile(std::shared_ptr<arcade::ITile> tile)
{
    if (tile->getTexture() == "snakeGame" || tile->getTexture() == "pacmanGame") {
        this->_game = tile->getTexture().substr(0, tile->getTexture().find("Game"));
        return;
    }
    attron(COLOR_PAIR(tile->getColor()));
    mvwprintw(stdscr, tile->getPosition().second, tile->getPosition().first, "%c", tile->getCharacter());
    attroff(COLOR_PAIR(tile->getColor()));
}

void NcursesArcade::handleSound(std::shared_ptr<arcade::ISound> sound)
{

}

void NcursesArcade::closeWin()
{
    ::clear();
    refresh();
    echo();
    endwin();
}

void NcursesArcade::handleText(std::shared_ptr<arcade::IText> text)
{
    mvwprintw(stdscr, (text->getPosition().second / 100) + 20, (text->getPosition().first / 100) + 20, "%s", text->getText().c_str());
}

void NcursesArcade::draw(std::shared_ptr<arcade::IObject> object)
{
    std::shared_ptr<arcade::ITile> tile = std::dynamic_pointer_cast<arcade::ITile>(object);
    if (tile != nullptr) {
        handleTile(tile);
        return;
    }
    std::shared_ptr<arcade::ISound> sound = std::dynamic_pointer_cast<arcade::ISound>(object);
    if (sound != nullptr) {
        handleSound(sound);
        return;
    }
    std::shared_ptr<arcade::IText> text = std::dynamic_pointer_cast<arcade::IText>(object);
    if (text != nullptr) {
        handleText(text);
        return;
    }
}

arcade::Input NcursesArcade::event()
{
    int key = getch();
    arcade::Input event = arcade::Input::UNDEFINED;

    timeout(120);
    switch (key) {
        case KEY_ESC:
            event = arcade::Input::EXIT;
            closeWin();
            break;
        case KEY_UP:
            event = arcade::Input::UP;
            break;
        case KEY_DOWN:
            event = arcade::Input::DOWN;
            break;
        case KEY_RIGHT:
            event = arcade::Input::RIGHT;
            break;
        case KEY_LEFT:
            event = arcade::Input::LEFT;
            break;
        case KEY_B:
            event = arcade::Input::PREVIOUSGAME;
            break;
        case KEY_N:
            event = arcade::Input::NEXTGAME;
            break;
        case KEY_G:
            event = arcade::Input::PREVIOUSGRAPH;
            closeWin();
            break;
        case KEY_H:
            event = arcade::Input::NEXTGRAPH;
            closeWin();
            break;
        default:
            break;
    }
    if (this->_game == "snake")
        event = arcade::Input::SNAKE;
    if (this->_game == "pacman")
        event = arcade::Input::PACMAN;
    this->_game = "";
    return event;
}

extern "C" {
    void *entryPoint() {
        return new NcursesArcade();
    }
}