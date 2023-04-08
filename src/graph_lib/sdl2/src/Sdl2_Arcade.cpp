/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#include "../include/Sdl2_Arcade.hpp"

SdlArcade::SdlArcade()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Error("Failed to initialize the SDL2 library", "Error: ");
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
        throw Error("Failed to initialize img to png or jpg", "Error: ");
    this->_window = SDL_CreateWindow("SDL2 Arcade!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    if (!this->_window)
        throw Error("Failed to create window", "Error: ");
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
    if (!this->_renderer)
        throw Error("Failed to create a renderer", "Error: ");
    TTF_Init();
    this->_font = TTF_OpenFont("src/game_lib/pac-man/assets/Minecraft.ttf", 55);
    SDL_ShowWindow(this->_window);
}

SdlArcade::~SdlArcade()
{
    this->dicolors.clear();
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void SdlArcade::display()
{
    SDL_RenderPresent(this->_renderer);
}

void SdlArcade::clear()
{
    SDL_RenderClear(this->_renderer);
    SDL_UpdateWindowSurface(this->_window);
}

void SdlArcade::handleTile(std::shared_ptr<arcade::ITile> tile)
{
    SDL_Rect rect;
    SDL_Color color = this->dicolors[tile->getColor()];

    if (tile->getTexture() != "") {
        if (tile->getTexture() == "snakeGame" || tile->getTexture() == "pacmanGame") {
            this->_game = tile->getTexture().substr(0, tile->getTexture().find("Game"));
            return;
        }
        SDL_Texture *texture;
        texture = IMG_LoadTexture(this->_renderer, tile->getTexture().c_str());
        if (!texture)
            throw Error("While creating the texture an error opered", "Error: ");
        SDL_QueryTexture(texture, NULL, NULL, &this->_width, &this->_height);
        rect.x = tile->getPosition().first;
        rect.y = tile->getPosition().second;
        rect.w = this->_width;
        rect.h = this->_height;
        SDL_RenderCopy(this->_renderer, texture, NULL, &rect);
        SDL_DestroyTexture(texture);
    } else {
        SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
        rect.x = tile->getPosition().first * 30;
        rect.y = tile->getPosition().second * 30;
        rect.w = 30;
        rect.h = 30;
        SDL_RenderDrawRect(this->_renderer, &rect);
        SDL_RenderFillRect(this->_renderer, &rect);
        SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, color.a);
    }
}

void SdlArcade::handleSound(std::shared_ptr<arcade::ISound> sound)
{

}

void SdlArcade::handleText(std::shared_ptr<arcade::IText> text)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Color color = this->dicolors[text->getColorText()];
    SDL_Rect rect;

    surface = TTF_RenderText_Solid(this->_font, text->getText().c_str(), color);
    texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    rect.x = text->getPosition().first;
    rect.y = text->getPosition().second;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(this->_renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void SdlArcade::draw(std::shared_ptr<arcade::IObject> object)
{
    std::shared_ptr<arcade::ITile> tile = std::dynamic_pointer_cast<arcade::ITile>(object);
    if (tile != nullptr) {
        handleTile(tile);
        return;
    }
    std::shared_ptr<arcade::ISound> sound = std::dynamic_pointer_cast<arcade::ISound>(object);
    if (sound != nullptr) {
        handleSound(sound);
        return;
    }
    std::shared_ptr<arcade::IText> text = std::dynamic_pointer_cast<arcade::IText>(object);
    if (text != nullptr) {
        handleText(text);
        return;
    }
}

void SdlArcade::closeWin()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

arcade::Input SdlArcade::event()
{
    arcade::Input event = arcade::Input::UNDEFINED;

    SDL_Delay(100);
    while (SDL_PollEvent(&this->_event)) {
        if (this->_event.type == SDL_QUIT) {
            event = arcade::Input::EXIT;
            closeWin();
        }
        if (this->_event.type == SDL_KEYUP) {
            switch (this->_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    event = arcade::Input::EXIT;
                    closeWin();
                    break;
                case SDLK_UP:
                    event = arcade::Input::UP;
                    break;
                case SDLK_DOWN:
                    event = arcade::Input::DOWN;
                    break;
                case SDLK_RIGHT:
                    event = arcade::Input::RIGHT;
                    break;
                case SDLK_LEFT:
                    event = arcade::Input::LEFT;
                    break;
                case SDLK_b:
                    event = arcade::Input::PREVIOUSGAME;
                    break;
                case SDLK_n:
                    event = arcade::Input::NEXTGAME;
                    break;
                case SDLK_g:
                    event = arcade::Input::PREVIOUSGRAPH;
                    closeWin();
                    break;
                case SDLK_h:
                    event = arcade::Input::NEXTGRAPH;
                    closeWin();
                    break;
                default:
                    break;
            }
        }
    }
    if (this->_game == "snake")
        event = arcade::Input::SNAKE;
    if (this->_game == "pacman")
        event = arcade::Input::PACMAN;
    this->_game = "";

    return event;
}

extern "C" {
    void *entryPoint()
    {
        return new SdlArcade();
    }
}