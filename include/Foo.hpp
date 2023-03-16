/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Foo
*/

#ifndef FOO_HPP_
#define FOO_HPP_

#include "IDisplayModule.hpp"

class Foo : public IDisplayModule {
    public:
        Foo(std::string name);
        ~Foo();

        void init();
        void stop();
        const std::string &getName() const;

    protected:
    private:
        std::string _name;
};

#endif /* !FOO_HPP_ */
