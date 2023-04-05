/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_

class Draw {
    protected:
        int x;
        int y;
        char c;
    public:
        Draw();
        Draw(int y, int x, char c);
        ~Draw();
        int getX();
        int getY();
        char getChar();
};

#endif /* !DRAW_HPP_ */
