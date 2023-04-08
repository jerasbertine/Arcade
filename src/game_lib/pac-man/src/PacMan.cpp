/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** PacMan
*/

#include "../include/PacMan.hpp"

PacMan::PacMan()
{
    this->initMap(MAPPATH);
    getPacmanPos();
}

void PacMan::getPacmanPos()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (this->_map[i][j] == 'P') {
                this->_pos.first = i;
                this->_pos.second = j;
            }
        }
    }
}

void PacMan::setPacmanPosition(int x, int y)
{
    this->_pos.first = x;
    this->_pos.second = y;
}

PacMan::~PacMan()
{
}

void PacMan::checkCollision()
{
    if (this->_map[this->_pos.first][this->_pos.second] == '.') {
        this->_score += 10;
        this->_map[this->_pos.first][this->_pos.second] = ' ';
    }
    if (this->_map[this->_pos.first][this->_pos.second] == 'o') {
        this->_score += 50;
        this->_map[this->_pos.first][this->_pos.second] = ' ';
    }
}

void PacMan::movePacman()
{
    switch (this->_direction) {
        case Up:
            if (this->_map[this->_pos.first - 1][this->_pos.second] != '#')
                setPacmanPosition(this->_pos.first - this->_pacmanSpeed, this->_pos.second);
            break;
        case Down:
            if (this->_map[this->_pos.first + 1][this->_pos.second] != '#')
                setPacmanPosition(this->_pos.first + this->_pacmanSpeed, this->_pos.second);
            break;
        case Left:
            if (this->_map[this->_pos.first][this->_pos.second - 1] != '#')
                setPacmanPosition(this->_pos.first, this->_pos.second - this->_pacmanSpeed);
            break;
        case Right:
            if (this->_map[this->_pos.first][this->_pos.second + 1] != '#')
                setPacmanPosition(this->_pos.first, this->_pos.second + this->_pacmanSpeed);
            break;
        default:
            break;
    }
}

void PacMan::inputEvent(arcade::Input input)
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
    checkCollision();
}

void PacMan::setScore()
{
    std::shared_ptr<arcade::IText> score = createText();
    score->setText("Score: " + std::to_string(this->_score));
    score->setColorText(arcade::Color::WHITE);
    score->setPosition({700, 50});
    this->_object.push_back(score);
}

void PacMan::setLevel()
{
    std::shared_ptr<arcade::IText> level = createText();
    level->setText("Level: ");
    level->setColorText(arcade::Color::WHITE);
    level->setPosition({700, 150});
    this->_object.push_back(level);
}

void PacMan::setEnergizer()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (this->_map[i][j] == 'o') {
                std::shared_ptr<arcade::ITile> energizer = createTile();
                energizer->setCharacter('o');
                energizer->setColor(arcade::Color::GREEN);
                energizer->setPosition({j, i});
                this->_object.push_back(energizer);
            }
        }
    }
}

void PacMan::setFood()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (this->_map[i][j] == '.') {
                std::shared_ptr<arcade::ITile> food = createTile();
                food->setCharacter('.');
                food->setColor(arcade::Color::YELLOW);
                food->setPosition({j, i});
                this->_object.push_back(food);
            }
        }
    }
}

void PacMan::setGhost()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (this->_map[i][j] == '0') {
                std::shared_ptr<arcade::ITile> ghost1 = createTile();
                ghost1->setCharacter('G');
                this->_ghostPos[0].x = j;
                this->_ghostPos[0].x = i;
                ghost1->setColor(arcade::Color::RED);
                ghost1->setPosition({j, i});
                this->_object.push_back(ghost1);
            }
            if (this->_map[i][j] == '1') {
                std::shared_ptr<arcade::ITile> ghost2 = createTile();
                ghost2->setCharacter('G');
                this->_ghostPos[1].x = j;
                this->_ghostPos[1].x = i;
                ghost2->setColor(arcade::Color::RED);
                ghost2->setPosition({j, i});
                this->_object.push_back(ghost2);
            }
            if (this->_map[i][j] == '2') {
                std::shared_ptr<arcade::ITile> ghost3 = createTile();
                ghost3->setCharacter('G');
                this->_ghostPos[2].x = j;
                this->_ghostPos[2].x = i;
                ghost3->setColor(arcade::Color::RED);
                ghost3->setPosition({j, i});
                this->_object.push_back(ghost3);
            }
            if (this->_map[i][j] == '3') {
                std::shared_ptr<arcade::ITile> ghost4 = createTile();
                ghost4->setCharacter('G');
                this->_ghostPos[3].x = j;
                this->_ghostPos[3].x = i;
                ghost4->setColor(arcade::Color::RED);
                ghost4->setPosition({j, i});
                this->_object.push_back(ghost4);
            }
        }
    }
}

void PacMan::setWall()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (this->_map[i][j] == '#') {
                std::shared_ptr<arcade::ITile> wall = createTile();
                wall->setCharacter('#');
                wall->setColor(arcade::Color::BLUE);
                wall->setPosition({j, i});
                this->_object.push_back(wall);
            }
        }
    }
}

void PacMan::setPacmanTile()
{
    std::shared_ptr<arcade::ITile> pacman = createTile();
    pacman->setCharacter('P');
    pacman->setColor(arcade::Color::WHITE);
    pacman->setPosition({this->_pos.second, this->_pos.first});
    pacman->setRotation(0);
    this->_object.push_back(pacman);
}

void PacMan::setText()
{
    setScore();
    setLevel();
}

void PacMan::setMapTile()
{
    setWall();
    setFood();
    setEnergizer();
    setGhost();
    setPacmanTile();
}

void PacMan::createObject()
{
    this->_object.clear();
    setMapTile();
    setText();
}

void PacMan::gameLoop()
{
    movePacman();
}

std::vector<std::shared_ptr<arcade::IObject>> PacMan::loop(arcade::Input input)
{
    inputEvent(input);
    gameLoop();
    createObject();
    return this->_object;
}

void PacMan::restart()
{
    return;
}

void PacMan::initMap(std::string path)
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

std::shared_ptr<arcade::ITile> PacMan::createTile()
{
    return std::make_shared<arcade::ATile>();
}

std::shared_ptr<arcade::ISound> PacMan::createSound()
{
    return std::make_shared<arcade::ASound>();
}

std::shared_ptr<arcade::IText> PacMan::createText()
{
    return std::make_shared<arcade::AText>();
}

arcade::Input PacMan::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

extern "C" {
    void *entryPoint() {
        return new PacMan();
    }
}