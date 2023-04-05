/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #define MAPPATH "src/game_lib/snake/assets/map.txt"
    #include "../../../../include/Arcade-Architecture/IGames.hpp"
    #include "../../../../include/ATile.hpp"
    #include "../../../../include/AText.hpp"
    #include "../../../../include/ASound.hpp"
    #include "Draw.hpp"
    #include "Apple.hpp"
    #include "Empty.hpp"
    #include "SnakeBody.hpp"
    #include <fstream>
    #include <utility>
    #include <ncurses.h>

class Snake : public arcade::IGames {
    public:
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        Snake(int height, int width, int speed);
        void processInput();
        void updateState();
        bool isOver();
        void construct(int height, int width, int speed);
        void add(Draw draw);
        void addAt(int y, int x, char c);
        void getEmptyCood(int &y, int &x);
        void setTimeout(int timeout);
        void createApple();
        void handlePiece(SnakeBody next);
        void scoreValue(int MaxY, int MaxX);
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
        std::vector<std::shared_ptr<arcade::IObject>> _object;
        bool gameOver;
        WINDOW *mapBorder;
        int height;
        int width;
        Apple *apple;
        SnakePiece snakePiece;
        int timeout;
        int score = 0;
};

#endif /* !SNAKE_HPP_ */
