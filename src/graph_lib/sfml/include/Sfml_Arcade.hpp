/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Sfml_Arcade
*/

#ifndef SFML_ARCADE_HPP_
    #define SFML_ARCADE_HPP_
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"
    #include <SFML/Graphics.hpp>

    #define ASSETS_PATH "src/graph_lib/sfml/assets/"

class SfmlArcade : public arcade::IGraphics {
    public:
        SfmlArcade();
        ~SfmlArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        void handleTile(std::shared_ptr<arcade::ITile> tile);
        void handleSound(std::shared_ptr<arcade::ISound> sound);
        void drawText(arcade::IText *text);
        void drawSprite(arcade::ITile *tile);
        arcade::Input event();

    protected:
    private:
        sf::RenderWindow *_window;
        sf::Event _event;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Text _text;
};

#endif /* !SFML_ARCADE_HPP_ */
