#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &var1, T &var2)
{
    T box = var1;
    var1 = var2;
    var2 = box;
}

template <typename T>
T min(T &var1, T &var2)
{
    if (var1 < var2)
        return var1;
    return var2;
}

template <typename T>
T max(T &var1, T &var2)
{
    if (var1 > var2)
        return var1;
    return var2;
}

#endif