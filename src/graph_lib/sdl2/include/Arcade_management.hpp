/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Menu
*/

#ifndef ARCADE_MANAGEMENT_HPP_
    #define ARCADE_MANAGEMENT_HPP_
    #include "../../../../include/Arcade-Architecture/IGraphics.hpp"

class SdlArcade : public arcade::IGraphics {
    public:
        SdlArcade();
        ~SdlArcade();
        void display();
        void clear();
        void draw(std::shared_ptr<arcade::IObject> object);
        arcade::Input event();

    protected:
    private:
};

#endif /* !ARCADE_MANAGEMENT_HPP_ */
