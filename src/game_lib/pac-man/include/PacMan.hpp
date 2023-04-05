/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_
    #define MAPPATH "src/game_lib/pac-man/assets/map2.txt"
    #include "../../../../include/Arcade-Architecture/IGames.hpp"
    #include "../../../../include/ATile.hpp"
    #include "../../../../include/AText.hpp"
    #include "../../../../include/ASound.hpp"
    #include <fstream>
    #include <array>

enum Cell
{
	Door,
	Empty,
	Energizer,
	PacGum,
	Wall
};

enum Direction
{
    Up = 1,
    Left,
    Down,
    Right
};

struct Position
{
	short x;
	short y;

	bool operator==(const Position& i_position)
	{
		return this->x == i_position.x && this->y == i_position.y;
	}
};

class PacMan : public arcade::IGames {
    public:
        PacMan();
        ~PacMan();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void createObject();
        void getPacmanPos();
        void setMapTile();
        void setText();
        void setWall();
        void setPacmanTile();
        void setGhost();
        void setFood();
        void setEnergizer();
        void setScore();
        void setLevel();
        void restart();
        void gameLoop();
        void movePacman();
        void checkCollision();
        void initMap(std::string path);
        void inputEvent(arcade::Input input);
        void setPacmanPosition(int x, int y);
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
        std::array<Position, 4> _ghostPos;
        std::pair<int, int> _pos;
        std::vector<std::string> _map;
        std::vector<std::shared_ptr<arcade::IObject>> _object;
        int _direction = 4;
        int _score = 0;
        int _level = 1;
        int _pacmanSpeed = 15;
};

#endif /* !PACMAN_HPP_ */
