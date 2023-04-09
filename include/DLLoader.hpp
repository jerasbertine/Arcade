/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <iostream>
#include "Error.hpp"
template<typename T>
class DLLoader {
    public:
        DLLoader(std::string path) {
            loadInstance(path);
        };
        ~DLLoader() {
            delete _instance;
            dlclose(_handle);
        };
        T *getInstance() const {
            return _instance;
        };
        void loadInstance(std::string path) {
            void *(*instanceCreator)(void);
            this->_handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
            if (!this->_handle)
                throw Error(dlerror(), "Error: ");
            instanceCreator = (void* (*)()) dlsym(this->_handle, "entryPoint");
            if (!instanceCreator)
                throw Error(dlerror(), "Error: ");
            this->_instance = (T *) instanceCreator();
        };
        void changeInstance(std::string path) {
            // delete (_instance); // Si non bug
            dlclose(_handle);
            loadInstance(path);
        };

    protected:
    private:
        void *_handle;
        T *_instance;
};

#endif /* !DLLOADER_HPP_ */
