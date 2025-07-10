#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename C>
void iter(T* array, size_t lentgh, C f)
{
    for (size_t i = 0; i < lentgh; i++)
        f(array[i]);
}

template <typename T>
void printValue(T &value)
{
    std::cout << value << std::endl;
}

#endif