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
    setFood();
}

void Snake::getSnakePos()
{
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->_map[i][j] == 'S') {
                this->_snakePos.push_back({i, j});
                this->_snakePos.push_back({i, j - 1});
                this->_snakePos.push_back({i, j - 2});
                this->_snakePos.push_back({i, j - 3});
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
            if (this->_direction != Down)
                this->_direction = Up;
            break;
        case arcade::Input::DOWN:
            if (this->_direction != Up)
                this->_direction = Down;
            break;
        case arcade::Input::LEFT:
            if (this->_direction != Right)
                this->_direction = Left;
            break;
        case arcade::Input::RIGHT:
            if (this->_direction != Left)
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
    head->setCharacter('@');
    head->setColor(arcade::Color::GREEN);
    head->setPosition({this->_snakePos[0].second, this->_snakePos[0].first});
    this->_object.push_back(head);

    std::shared_ptr<arcade::ITile> body1 = createTile();
    body1->setCharacter('@');
    body1->setColor(arcade::Color::GREEN);
    body1->setPosition({this->_snakePos[1].second, this->_snakePos[1].first});
    this->_object.push_back(body1);

    std::shared_ptr<arcade::ITile> body2 = createTile();
    body2->setCharacter('@');
    body2->setColor(arcade::Color::GREEN);
    body2->setPosition({this->_snakePos[2].second, this->_snakePos[2].first});
    this->_object.push_back(body2);

    std::shared_ptr<arcade::ITile> queue = createTile();
    queue->setCharacter('@');
    queue->setColor(arcade::Color::GREEN);
    queue->setPosition({this->_snakePos[3].second, this->_snakePos[3].first});
    this->_object.push_back(queue);

    for (int i = 1; i < this->_snakePos.size(); i++) {
        std::shared_ptr<arcade::ITile> body = createTile();
        body->setColor(arcade::Color::GREEN);
        body->setPosition({this->_snakePos[i].second, this->_snakePos[i].first});
        this->_object.push_back(body);
    }
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
                wall->setCharacter('#');
                wall->setColor(arcade::Color::WHITE);
                wall->setPosition({j, i});
                this->_object.push_back(wall);
            }
        }
    }
}

void Snake::createFood()
{
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->_map[i][j] == 'F') {
                std::shared_ptr<arcade::ITile> food = createTile();
                food->setCharacter('$');
                food->setColor(arcade::Color::RED);
                food->setPosition({j, i});
                this->_object.push_back(food);
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
    createFood();
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

void Snake::setFood()
{
    int x = rand() % 30;
    int y = rand() % 20;

    if (this->_map[x][y] == '#') {
        setFood();
    } else {
        this->_map[x][y] = 'F';
    }
}

void Snake::addCellSnake()
{
    this->_snakePos.push_back({this->_snakePos[this->_snakePos.size() - 1].first, this->_snakePos[this->_snakePos.size() - 1].second});
}

void Snake::checkFood()
{
    if (this->_map[this->_snakePos[0].first][this->_snakePos[0].second] == 'F') {
        this->_map[this->_snakePos[0].first][this->_snakePos[0].second] = ' ';
        this->_score += 1;
        setFood();
        addCellSnake();
    }
}

void Snake::snakeMove()
{
    checkFood();
    snakeMoveBody();
    switch (this->_direction) {
        case Up:
            if (this->_direction == Up)
                this->_snakePos[0].first -= 1;
            break;
        case Down:
            if (this->_direction == Down)
                this->_snakePos[0].first += 1;
            break;
        case Left:
            if (this->_direction == Left)
                this->_snakePos[0].second -= 1;
            break;
        case Right:
            if (this->_direction == Right)
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

arcade::Input Snake::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

extern "C" {
    void *entryPoint() {
        return new Snake();
    }
}