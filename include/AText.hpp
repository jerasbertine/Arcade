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
    
    
        protected:
        private:
            std::string _text;
            arcade::Color _color;
            std::pair<std::size_t, std::size_t> _position;
    };
}

#endif /* !ATEXT_HPP_ */
