/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeBody
*/

#ifndef SNAKEBODY_HPP_
    #define SNAKEBODY_HPP_

    #include "Draw.hpp"
    #include <queue>

enum Direction {
    UP = -1,
    DOWN = 1,
    LEFT = -2,
    RIGHT = 2
};

class SnakeBody : public Draw{
    private:
    public:
        SnakeBody();
        SnakeBody(int y, int x);
        ~SnakeBody();
};

class SnakePiece {
    private:
        std::queue<SnakeBody> prevPiece;
        Direction dir;
    public:
        SnakePiece();
        ~SnakePiece();
        void addPiece(SnakeBody piece);
        void removePiece();
        SnakeBody tall();
        SnakeBody head();
        Direction getDirection();
        void setDirection(Direction d);
        SnakeBody nextHead();
};

#endif /* !SNAKEBODY_HPP_ */
