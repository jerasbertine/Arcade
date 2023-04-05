/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Snake
*/

#include "../include/Snake.hpp"

Snake::Snake(int height, int width, int speed)
{
    construct(height, width, speed);
    gameOver = false;
    apple = NULL;
    score = 0;
    srand(time(NULL));

    snakePiece.setDirection(DOWN);
    handlePiece(SnakeBody(1, 1));
    handlePiece(snakePiece.nextHead());
    handlePiece(snakePiece.nextHead());
    snakePiece.setDirection(RIGHT);
    handlePiece(snakePiece.nextHead());

    if (apple == NULL)
        createApple();
}

void Snake::processInput()
{
    int input = wgetch(mapBorder);

    switch (input) {
    case 'w':
        snakePiece.setDirection(UP);
        break;
    case 's':
        snakePiece.setDirection(DOWN);
        break;
    case 'a':
        snakePiece.setDirection(LEFT);
        break;
    case 'd':
        snakePiece.setDirection(RIGHT);
        break;
    case 'p':
        setTimeout(-1);
        while (wgetch(mapBorder) != 'p');
        setTimeout(timeout);
        break;
    case 27:
        endwin();
        exit(0);
    }
}

void Snake::updateState()
{
    handlePiece(snakePiece.nextHead());

    if (apple == NULL)
        createApple();
}

bool Snake::isOver()
{
    return gameOver;
}

void Snake::construct(int height, int width, int speed)
{
    this->height = height;
    this->width = width;
    mapBorder = newwin(height, width, 0, 0);
    timeout = speed;
    setTimeout(speed);
    wclear(mapBorder);
    box(mapBorder, 0, 0);
    wrefresh(mapBorder);
}

void Snake::add(Draw draw)
{
    addAt(draw.getY(), draw.getX(), draw.getChar());
}

void Snake::addAt(int y, int x, char c)
{
    mvwaddch(mapBorder, y, x, c);
}

void Snake::getEmptyCood(int &y, int &x)
{
    while ((mvwinch(mapBorder, y = rand() % height, x = rand() % width)) != ' ');
}

void Snake::setTimeout(int timeout)
{
    wtimeout(mapBorder, timeout);
}

void Snake::createApple()
{
    int x;
    int y;

    getEmptyCood(y, x);
    apple = new Apple(y, x);
    add(*apple);
}

void Snake::handlePiece(SnakeBody next)
{
    int emptyRow;
    int emptyCol;

    if (apple != NULL) {
        switch (mvwinch(mapBorder, next.getY(), next.getX())) {
        case '@':
            delete apple;
            apple = NULL;
            score += 100;
            break;
        case ' ': {
            emptyRow = snakePiece.tall().getY();
            emptyCol = snakePiece.tall().getX();
            add(Empty(emptyRow, emptyCol));
            snakePiece.removePiece();
            break;
        }
        default:
            gameOver = true;
            break;
        }
    }

    add(next);
    snakePiece.addPiece(next);
}

void Snake::scoreValue(int MaxY, int MaxX)
{
    mvprintw(MaxY / 3, MaxX - 30, "Score : %d", score);
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