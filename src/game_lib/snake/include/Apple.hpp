/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Apple
*/

#ifndef APPLE_HPP_
    #define APPLE_HPP_

    #include "Draw.hpp"

class Apple : public Draw {
    public:
        Apple(int y, int x)
        {
            this->y = y;
            this->x = x;
            this->c = '@';
        }
};

#endif /* !APPLE_HPP_ */
