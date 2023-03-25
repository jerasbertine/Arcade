/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_
    #include "../../../../include/Arcade-Architecture/IGames.hpp"

class PacMan : public arcade::IGames {
    public:
        PacMan();
        ~PacMan();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void restart();
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
};

#endif /* !PACMAN_HPP_ */
