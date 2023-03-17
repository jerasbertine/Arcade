/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-villon.zhang
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

template<typename T>
class DLLoader {
    public:
        DLLoader();
        ~DLLoader();
        T *getInstance() const;

    protected:
    private:
        void *_handle;
        T _instance;
};

#endif /* !DLLOADER_HPP_ */
