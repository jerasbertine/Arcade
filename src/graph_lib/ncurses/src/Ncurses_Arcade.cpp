/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Ncurses_Arcade
*/

#include "../include/Ncurses_Arcade.hpp"

NcursesArcade::NcursesArcade()
{
}

NcursesArcade::~NcursesArcade()
{
}

void NcursesArcade::display()
{
    int MaxX;
    int MaxY;
    initscr();
    refresh();
    getmaxyx(stdscr, MaxY, MaxX);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    snake(MaxY, MaxX - 40, 200);
    while(!snake.isOver()){
        snake.processInput();
        snake.updateState();
        snake.scoreValue(MaxY, MaxX);
        refresh();
    }
    endwin();
}

void NcursesArcade::clear()
{
    std::cout << "Refresh ncurses" << std::endl;
}

void NcursesArcade::draw(std::shared_ptr<arcade::IObject> object)
{
}

arcade::Input NcursesArcade::event()
{
    int input = wgetch(mapBorder);

    switch (input) {
    case 'w':
        snakePiece.setDirection(UP);
        break;
    case 's':
        snakePiece.setDirection(DOWN);
        break;
    case 'a':
        snakePiece.setDirection(LEFT);
        break;
    case 'd':
        snakePiece.setDirection(RIGHT);
        break;
    case 'p':
        setTimeout(-1);
        while (wgetch(mapBorder) != 'p');
        setTimeout(timeout);
        break;
    case 27:
        endwin();
        exit(0);
    }
    return arcade::Input::ACTION1;
}

extern "C" {
    void *entryPoint() {
        return new NcursesArcade();
    }
}