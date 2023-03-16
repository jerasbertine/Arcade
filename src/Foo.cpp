/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** Foo
*/

#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
#include "../include/Foo.hpp"

Foo::Foo(std::string name)
{
    this->_name = name;
}

Foo::~Foo()
{
    puts("This is a shared library test...");
}

void Foo::init()
{
    puts("Init this lib");
}

void Foo::stop()
{
    puts("Stop this lib");
}

const std::string &Foo::getName() const
{
    return this->_name;
}

extern "C" {
    void entry_point(std::string name)
    {
        Foo foo(name);
        foo.init();
        foo.stop();
    }
}