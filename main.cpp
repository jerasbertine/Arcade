/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** main
*/

#include <dlfcn.h>

int main(int ac, char **av)
{
    void *handle;
    void *(*function)(void);
    handle = dlopen("./libfoo.so", RTLD_LAZY);
    if (!handle)
        return 84;
    function = (void *(*)()) dlsym(handle, "entry_point");
    function();
    dlclose(handle);
    return 0;
}