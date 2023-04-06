/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu()
{
    this->_selectedOption = 0;
    this->_selectedGame = 0;
    this->_state = HOME;
}

Menu::~Menu()
{
    this->_vector.clear();
}

void Menu::pushHomeMenu()
{
    std::shared_ptr<arcade::ITile> texture[2];

    for (int i = 0; i < 2; ++i)
        texture[i] = createTile();
    // Background du menu
    texture[0]->setTexture("src/game_lib/menu/assets/background.jpg");
    // Panneau contenant le text "Arcade"
    texture[1]->setTexture("src/game_lib/menu/assets/sign.png");
    texture[1]->setPosition({460, 100});
    for (int i = 0; i < 2; ++i)
        this->_vector.push_back(texture[i]);
}

void Menu::pushSound()
{
    std::shared_ptr<arcade::ISound> sound = createSound();
}

void Menu::pushCredText()
{
    std::shared_ptr<arcade::IText> text[4];

    this->_vector.clear();
    for (int i = 0; i < 4; ++i) {
        text[i] = createText();
        text[i]->setColorText(arcade::Color::WHITE);
    }
    text[0]->setText("Jeras BERTINE (jeras.bertine@epitech.eu)");
    text[0]->setPosition({440, 580});
    text[1]->setText("David LIN (david1.lin@epitech.eu)");
    text[1]->setPosition({540, 660});
    text[2]->setText("Villon ZHANG (villon.zhang@epitech.eu)");
    text[2]->setPosition({480, 740});
    text[3]->setText("Credits Arcade:");
    text[3]->setPosition({800, 100});
    for (int i = 0; i < 4; ++i)
        this->_vector.push_back(text[i]);
}

void Menu::pushGameText()
{
    std::shared_ptr<arcade::IText> text[2];

    for (int i = 0; i < 2; ++i)
        text[i] = createText();
    text[0]->setText("Snake");
    text[0]->setPosition({900, 660});
    text[1]->setText("PacMan");
    text[1]->setPosition({885, 740});
    text[this->_selectedGame]->setColorText(arcade::Color::BLUE);
    for (int i = 0; i < 2; ++i)
        this->_vector.push_back(text[i]);
}

void Menu::pushHomeText()
{
    std::shared_ptr<arcade::IText> text[2];

    for (int i = 0; i < 2; ++i)
        text[i] = createText();
    text[0]->setText("Play");
    text[0]->setPosition({920, 660});
    text[1]->setText("Credits");
    text[1]->setPosition({885, 740});
    text[this->_selectedOption]->setColorText(arcade::Color::BLUE);
    for (int i = 0; i < 2; ++i)
        this->_vector.push_back(text[i]);
}

void Menu::switchToSnake()
{
    std::shared_ptr<arcade::ITile> snake = createTile();

    snake->setTexture("snakeGame");
    this->_vector.push_back(snake);
}

void Menu::switchToPacMan()
{
    std::shared_ptr<arcade::ITile> pacman = createTile();

    pacman->setTexture("pacmanGame");
    this->_vector.push_back(pacman);
}

int Menu::handleEvent(arcade::Input input, int selected)
{
    if (input == arcade::Input::RIGHT && this->_state == GAME)
        this->_selectedGame == 0 ? switchToSnake() : switchToPacMan();
    switch (input) {
        case arcade::Input::DOWN:
            ++selected;
            break;
        case arcade::Input::UP:
            --selected;
            break;
        case arcade::Input::LEFT:
            this->_state = HOME;
            break;
        case arcade::Input::RIGHT:
            this->_state = this->_state == HOME ? this->_selectedOption == 0 ? GAME : CREDITS : this->_state;
            break;
        default:
            break;
    }
    return selected = selected > 1 ? 1 : selected < 0 ? 0 : selected;
}

std::vector<std::shared_ptr<arcade::IObject>> Menu::loop(arcade::Input input)
{
    this->_vector.clear();
    pushHomeMenu();
    switch (this->_state) {
        case HOME:
            this->_selectedOption = handleEvent(input, this->_selectedOption);
            pushHomeText();
            break;
        case GAME:
            this->_selectedGame = handleEvent(input, this->_selectedGame);
            pushGameText();
            break;
        case CREDITS:
            handleEvent(input, 0);
            pushCredText();
            break;
        default:
            break;
    }
    pushSound();
    return this->_vector;
}

void Menu::restart()
{
    return;
}

std::shared_ptr<arcade::ITile> Menu::createTile()
{
    return std::make_shared<arcade::ATile>();
}

std::shared_ptr<arcade::ISound> Menu::createSound()
{
    return std::make_shared<arcade::ASound>();
}

std::shared_ptr<arcade::IText> Menu::createText()
{
    return std::make_shared<arcade::AText>();
}

extern "C" {
    void *entryPoint() {
        return new Menu();
    }
}