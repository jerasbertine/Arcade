/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../../../../include/Arcade-Architecture/IGames.hpp"

class Menu : public arcade::IGames {
    public:
        Menu();
        ~Menu();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void restart();
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();

    protected:
    private:
};

#endif /* !MENU_HPP_ */
