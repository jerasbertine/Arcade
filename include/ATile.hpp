/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ATile
*/

#ifndef ATILE_HPP_
    #define ATILE_HPP_
    #include "Arcade-Architecture/IObject.hpp"

namespace arcade {
    class ATile : public arcade::ITile {
        public:
            ATile();
            ~ATile();
            std::string getTexture() const;
            std::pair<std::size_t, std::size_t> getPosition() const;
            char getCharacter() const;
            arcade::Color getColor() const;
            std::pair<float, float> getScale() const;
            float getRotation() const;
            void setTexture(std::string path);
            void setPosition(std::pair<std::size_t, std::size_t> position);
            void setCharacter(char c);
            void setColor(arcade::Color color);
            void setScale(std::pair<float, float> scale);
            void setRotation(float rotation);
            std::pair<float, float> getOriginScale();
            std::pair<std::size_t, std::size_t> getOriginPosition();
            void setOriginScale(std::pair<float, float> scale);
            void setOriginPosition(std::pair<std::size_t, std::size_t> position);
            void setEvent(arcade::Input event);
            arcade::Input getEvent() const;
            void setName(std::string name);
            std::string getName() const;
    
        protected:
        private:
            std::string _texturePath;
            std::pair<float, float> _position;
            char _char;
            arcade::Color _color;
            std::pair<std::size_t, std::size_t> _scale;
            float _rotation;
            std::pair<float, float> _originScale;
            std::pair<std::size_t, std::size_t> _originPosition;
            arcade::Input _event;
            std::string _name;
    };
}

#endif /* !ATILE_HPP_ */
