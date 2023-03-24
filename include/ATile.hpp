/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ATile
*/

#ifndef ATILE_HPP_
    #define ATILE_HPP_
    #include "Arcade-Architecture/IObject.hpp"

class ATile : public arcade::ITile {
    public:
        ATile();
        ~ATile();
        std::string getTexture() const;
        std::pair<float, float> getPosition() const;
        char getCharacter() const;
        arcade::Color getColor() const;
        std::pair<std::size_t, std::size_t> getScale() const;
        float getRotation() const;
        void setTexture(std::string path);
        void setPosition(std::pair<std::size_t, std::size_t> position);
        void setCharacter(char c);
        void setColor(arcade::Color color);
        void setScale(std::pair<std::size_t, std::size_t> scale);
        void setRotation(float rotation);

    protected:
    private:
        std::string _texturePath;
        std::pair<float, float> _position;
        char _char;
        arcade::Color _color;
        std::pair<std::size_t, std::size_t> _scale;
        float _rotation;
};

#endif /* !ATILE_HPP_ */
