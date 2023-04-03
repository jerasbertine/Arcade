/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../../../../include/Arcade-Architecture/IGames.hpp"
    #include "../../../../include/ATile.hpp"
    #include "../../../../include/AText.hpp"
    #include "../../../../include/ASound.hpp"

    #define ASSETS_PATH "src/game_lib/menu/assets/"

enum State {
    HOME,
    GAME,
    CREDITS,
};

class Menu : public arcade::IGames {
    public:
        Menu();
        ~Menu();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
        void restart();
        std::shared_ptr<arcade::ITile> createTile();
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::IText> createText();
        void pushHomeMenu();
        void pushGameText();
        void pushCredText();
        void pushSound();
        void pushHomeText();
        int handleEvent(arcade::Input input, int selected);
        void switchToSnake();
        void switchToPacMan();

    protected:
    private:
        std::vector<std::shared_ptr<arcade::IObject>> _vector;
        int _selectedOption;
        int _selectedGame;
        std::size_t _state;
};

#endif /* !MENU_HPP_ */
