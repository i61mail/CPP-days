#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t lentgh, void (*f)(T &))
{
    for (size_t i = 0; i < lentgh; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void print(T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void change(T &value)
{
    value += 1;
    std::cout << value << std::endl;
}


#endif