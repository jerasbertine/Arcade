/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Sfml_Arcade
*/

#include <SFML/Graphics.hpp>
#include "../include/Sfml_Arcade.hpp"

Sfml_Arcade::Sfml_Arcade()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

Sfml_Arcade::~Sfml_Arcade()
{
}

void Sfml_Arcade::display()
{
    std::cout << "display" << std::endl;
}

void Sfml_Arcade::clear()
{
}

void Sfml_Arcade::draw(std::shared_ptr<arcade::IObject> object)
{

}

arcade::Input Sfml_Arcade::event()
{
    return arcade::Input::ACTION1;
}

extern "C" {
    void *entryPoint()
    {
        return new Sfml_Arcade();
    }
}