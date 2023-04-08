/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** AText
*/

#ifndef ATEXT_HPP_
    #define ATEXT_HPP_
    #include "Arcade-Architecture/IObject.hpp"

namespace arcade {
    class AText : public arcade::IText {
        public:
            AText();
            ~AText();
            std::string getText() const;
            arcade::Color getColorText() const;
            std::pair<std::size_t, std::size_t> getPosition() const;
            void setText(std::string text);
            void setColorText(arcade::Color color);
            void setPosition(std::pair<std::size_t, std::size_t> position);
            std::pair<float, float> getOriginScale();
            std::pair<std::size_t, std::size_t> getOriginPosition();
            void setOriginScale(std::pair<float, float> scale);
            void setOriginPosition(std::pair<std::size_t, std::size_t> position);
            void setEvent(arcade::Input event);
            void setRotation(float rotation);
            arcade::Input getEvent() const;
            void setName(std::string name);
            std::string getName() const;
            void setScale(std::pair<float, float> scale);
            std::pair<float, float> getScale() const;
            float getRotation() const;

        protected:
        private:
            std::string _text;
            arcade::Color _color;
            std::pair<std::size_t, std::size_t> _position;
            std::pair<float, float> _originScale;
            std::pair<std::size_t, std::size_t> _originPosition;
            arcade::Input _event;
            std::string _name;
            std::pair<std::size_t, std::size_t> _scale;
            float _rotation;
    };
}

#endif /* !ATEXT_HPP_ */
