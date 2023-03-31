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

enum Cell
{
	Door,
	Empty,
	Energizer,
	PacGum,
	Wall
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
        void setMap();
        void setText();
        void setWall();
        void setPacman();
        void setGhost();
        void setFood();
        void setEnergizer();
        void setScore();
        void setLevel();
        void restart();
        void initMap(std::string path);
        void inputEvent(arcade::Input input);
        void setPosition(short i_x, short i_y);
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
        Position _pacmanPos;
        std::array<Position, 4> _ghostPos;
        std::vector<std::string> _map;
        std::vector<std::shared_ptr<arcade::IObject>> _object;
};

#endif /* !PACMAN_HPP_ */
