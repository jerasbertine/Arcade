/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Empty
*/

#ifndef EMPTY_HPP_
    #define EMPTY_HPP_

    #include "Draw.hpp"

class Empty : public Draw {
    public:
        Empty(int y, int x)
        {
            this->y = y;
            this->x = x;
            this->c = ' ';
        };
};

#endif /* !EMPTY_HPP_ */
