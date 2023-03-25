/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** ASound
*/

#ifndef ASOUND_HPP_
    #define ASOUND_HPP_
    #include "Arcade-Architecture/IObject.hpp"

namespace arcade {
    class ASound : public arcade::ISound {
        public:
            ASound();
            ~ASound();
            std::string getSoundPath() const;
            float getVolume() const;
            void setSoundPath(std::string path);
            void setVolume(float volume);
            void pauseSound();
            void playSound();
            void stopSound();
    
        protected:
        private:
            std::string _soundPath;
            float _volume;
    };
}

#endif /* !ASOUND_HPP_ */
