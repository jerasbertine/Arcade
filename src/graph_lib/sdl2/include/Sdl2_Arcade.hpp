/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#ifndef SDL2_ARCADE_HPP_
    #define SDL2_ARCADE_HPP_
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include <map>
    #include "../../../../include/Error.hpp"
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"

class SdlArcade : public arcade::IGraphics {
    public:
        SdlArcade();
        ~SdlArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();
        void handleTile(std::shared_ptr<arcade::ITile> tile);
        void handleSound(std::shared_ptr<arcade::ISound> sound);
        void handleText(std::shared_ptr<arcade::IText> text);
        void closeWin();

    protected:
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        std::string _game;
        TTF_Font *_font;
        int _width;
        int _height;
        std::map<arcade::Color, SDL_Color> dicolors = {
            {arcade::Color::BLUE, {0, 0, 255, 0}},
            {arcade::Color::RED, {255, 0, 0, 0}},
            {arcade::Color::GREEN, {0, 255, 0, 0}},
            {arcade::Color::YELLOW, {255, 255, 0, 0}},
            {arcade::Color::WHITE, {255, 255, 255, 0}},
            {arcade::Color::DARK, {0, 0, 0, 0}},
        };
};

#endif /* !ARCADE_MANAGEMENT_HPP_ */
