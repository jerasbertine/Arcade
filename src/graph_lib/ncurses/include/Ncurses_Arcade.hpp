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
    #include "../../../../include/Error.hpp"
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"

    #define KEY_ESC 27
    #define KEY_B 98
    #define KEY_G 103
    #define KEY_H 104
    #define KEY_N 110

class NcursesArcade : public arcade::IGraphics {
    public:
        NcursesArcade();
        ~NcursesArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();
        void handleTile(std::shared_ptr<arcade::ITile> tile);
        void handleSound(std::shared_ptr<arcade::ISound> sound);
        void handleText(std::shared_ptr<arcade::IText> text);

    protected:
    private:
};

#endif /* !NCURSES_ARCADE_HPP_ */
