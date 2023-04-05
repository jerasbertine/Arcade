/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Ncurses_Arcade
*/

#ifndef NCURSES_ARCADE_HPP_
    #define NCURSES_ARCADE_HPP_
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"
    #include <ncurses.h>

enum Direction {
    UP = -1,
    DOWN = 1,
    LEFT = -2,
    RIGHT = 2
};

class NcursesArcade : public arcade::IGraphics {
    public:
        NcursesArcade();
        ~NcursesArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();
    private:
        WINDOW *mapBorder;
};

#endif /* !NCURSES_ARCADE_HPP_ */
