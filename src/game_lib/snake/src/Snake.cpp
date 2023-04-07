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
    getSnakePos();
}

void Snake::getSnakePos()
{
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->_map[i][j] == 'S') {
                this->_snakePos.push_back({i, j});
                this->_snakePos.push_back({i, j - 1});
                this->_snakePos.push_back({i, j - 2});
            }
        }
    }
}

Snake::~Snake()
{

}

void Snake::inputEvent(arcade::Input input)
{
    switch (input) {
        case arcade::Input::UP:
            this->_direction = Up;
            break;
        case arcade::Input::DOWN:
            this->_direction = Down;
            break;
        case arcade::Input::LEFT:
            this->_direction = Left;
            break;
        case arcade::Input::RIGHT:
            this->_direction = Right;
            break;
        default:
            break;
    }
}

void Snake::setScore()
{
    std::shared_ptr<arcade::IText> text = createText();
    text->setColorText(arcade::Color::WHITE);
    text->setPosition({700, 50});
    text->setText("Score: " + std::to_string(this->_score));
    this->_object.push_back(text);
}

void Snake::setSnake()
{
    std::shared_ptr<arcade::ITile> head = createTile();
    head->setColor(arcade::Color::GREEN);
    head->setPosition({this->_snakePos[0].second, this->_snakePos[0].first});
    head->setScale({2, 2});
    this->_object.push_back(head);

    std::shared_ptr<arcade::ITile> body = createTile();
    body->setColor(arcade::Color::GREEN);
    body->setPosition({this->_snakePos[1].second, this->_snakePos[1].first});
    body->setScale({2, 2});
    this->_object.push_back(body);

    std::shared_ptr<arcade::ITile> queue = createTile();
    queue->setColor(arcade::Color::GREEN);
    queue->setPosition({this->_snakePos[2].second, this->_snakePos[2].first});
    queue->setScale({2, 2});
    this->_object.push_back(queue);

    // for (int i = 1; i < this->_snakePos.size(); i++) {
    //     std::shared_ptr<arcade::ITile> body = createTile();
    //     body->setColor(arcade::Color::GREEN);
    //     body->setPosition({this->_snakePos[i].second, this->_snakePos[i].first});
    //     body->setScale({2, 2});
    //     this->_object.push_back(body);
    // }
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
                wall->setPosition({j, i});
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

void Snake::snakeMoveBody()
{
    for (int i = this->_snakePos.size(); i > 0; i--) {
        this->_snakePos[i].first = this->_snakePos[i - 1].first;
        this->_snakePos[i].second = this->_snakePos[i - 1].second;
    }
}

void Snake::checkCollision()
{
    if (this->_snakePos[0].first < 0 || this->_snakePos[0].first > 29 || this->_snakePos[0].second < 0 || this->_snakePos[0].second > 19) {
        restart();
    }
    for (int i = 1; i < this->_snakePos.size(); i++) {
        if (this->_snakePos[0].first == this->_snakePos[i].first && this->_snakePos[0].second == this->_snakePos[i].second) {
            restart();
        }
    }

    if (this->_map[this->_snakePos[0].first][this->_snakePos[0].second] == '#') {
        restart();
    }
}

void Snake::snakeMove()
{
    snakeMoveBody();
    switch (this->_direction) {
        case Up:
            this->_snakePos[0].first -= 1;
            break;
        case Down:
            this->_snakePos[0].first += 1;
            break;
        case Left:
            this->_snakePos[0].second -= 1;
            break;
        case Right:
            this->_snakePos[0].second += 1;
            break;
        default:
            break;
    }
    checkCollision();
}

void Snake::gameLoop()
{
    snakeMove();
}

std::vector<std::shared_ptr<arcade::IObject>> Snake::loop(arcade::Input input)
{
    inputEvent(input);
    gameLoop();
    createObject();
    return this->_object;
}

void Snake::restart()
{
    this->_snakePos.clear();
    getSnakePos();
    this->_direction = Right;
    this->_score = 0;
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