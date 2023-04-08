/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Ncurses_Arcade
*/

#ifndef NCURSES_ARCADE_HPP_
    #define NCURSES_ARCADE_HPP_
    #include <ncurses.h>
    #include <sys/stat.h>
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"

class NcursesArcade : public arcade::IGraphics {
    public:
        NcursesArcade();
        ~NcursesArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();

    protected:
    private:
};

#endif /* !NCURSES_ARCADE_HPP_ */
