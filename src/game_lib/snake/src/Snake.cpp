/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Snake
*/

#include "../include/Snake.hpp"

Snake::Snake()
{
    this->initMap(MAPPATH);
}

Snake::~Snake()
{

}

void Snake::inputEvent(arcade::Input input)
{
    switch (input) {
        case arcade::Input::UP:
            std::cout << "up" << std::endl;
            break;
        case arcade::Input::DOWN:
            std::cout << "down" << std::endl;
            break;
        case arcade::Input::LEFT:
            std::cout << "left" << std::endl;
            break;
        case arcade::Input::RIGHT:
            std::cout << "right" << std::endl;
            break;
        default:
            break;
    }
}

void Snake::setSnake()
{
    std::shared_ptr<arcade::ITile> snake = createTile();
    snake->setColor(arcade::Color::GREEN);
    snake->setPosition({300, 300});
    snake->setScale({2, 2});
    this->_object.push_back(snake);
}

void Snake::setScore()
{
    std::shared_ptr<arcade::IText> text = createText();
    text->setColorText(arcade::Color::WHITE);
    text->setPosition({700, 50});
    text->setText("Score: " + std::to_string(this->_score));
    this->_object.push_back(text);
}

void Snake::setText()
{
    setScore();
}

void Snake::setMapTile()
{
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->_map[i][j] == '#') {
                std::shared_ptr<arcade::ITile> wall = createTile();
                wall->setColor(arcade::Color::WHITE);
                wall->setPosition({j * 30, i * 30});
                wall->setScale({2, 2});
                this->_object.push_back(wall);
            }
        }
    }
}

void Snake::createObject()
{
    this->_object.clear();
    setMapTile();
    setText();
    setSnake();
}

std::vector<std::shared_ptr<arcade::IObject>> Snake::loop(arcade::Input input)
{
    inputEvent(input);
    createObject();
    return this->_object;
}

void Snake::restart()
{
    return;
}

void Snake::initMap(std::string path)
{
    std::string line;
    std::ifstream file(path);

    if (file.is_open()) {
        while (getline(file, line)) {
            this->_map.push_back(line);
        }
        file.close();
    }
}

std::shared_ptr<arcade::ITile> Snake::createTile()
{
    return std::make_shared<arcade::ATile>();
}

std::shared_ptr<arcade::ISound> Snake::createSound()
{
    return std::make_shared<arcade::ASound>();
}

std::shared_ptr<arcade::IText> Snake::createText()
{
    return std::make_shared<arcade::AText>();
}

extern "C" {
    void *entryPoint() {
        return new Snake();
    }
}