/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Sfml_Arcade
*/

#ifndef SFML_ARCADE_HPP_
    #define SFML_ARCADE_HPP_
    #define ASSETS_PATH "src/graph_lib/sfml/assets/"
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"
    #include <SFML/Graphics.hpp>

class Sfml_Arcade : public arcade::IGraphics {
    public:
        Sfml_Arcade();
        ~Sfml_Arcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();

    protected:
    private:
        sf::RenderWindow *_window;
        sf::Event _event;
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !SFML_ARCADE_HPP_ */
