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
}

NcursesArcade::~NcursesArcade()
{
    endwin();
}

void NcursesArcade::display()
{
    
}

void NcursesArcade::clear()
{
    refresh();
}

void NcursesArcade::handleTile(std::shared_ptr<arcade::ITile> tile)
{

}

void NcursesArcade::handleSound(std::shared_ptr<arcade::ISound> sound)
{

}

void NcursesArcade::handleText(std::shared_ptr<arcade::IText> text)
{
    
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

    switch (key) {
        case KEY_ESC:
            event = arcade::Input::EXIT;
            endwin();
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
            endwin();
            break;
        case KEY_H:
            event = arcade::Input::NEXTGRAPH;
            endwin();
            break;
        default:
            break;
    }

    return event;
}

extern "C" {
    void *entryPoint() {
        return new NcursesArcade();
    }
}