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
    #include <fstream>

enum Direction
{
    Up = 1,
    Left,
    Down,
    Right
};

class Snake : public arcade::IGames {
    public:
        Snake();
        ~Snake();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void createObject();
        void setMapTile();
        void setText();
        void setScore();
        void setSnake();
        void getSnakePos();
        void restart();
        void gameLoop();
        void snakeMove();
        void snakeMoveBody();
        void checkCollision();
        void setFood();
        void checkFood();
        void createFood();
        void addCellSnake();
        void inputEvent(arcade::Input input);
        void initMap(std::string path);
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
        std::vector<std::string> _map;
        std::vector<std::pair<int, int>> _snakePos;
        std::vector<std::shared_ptr<arcade::IObject>> _object;
        int _score = 0;
        int _direction = 4;
};

#endif /* !SNAKE_HPP_ */
