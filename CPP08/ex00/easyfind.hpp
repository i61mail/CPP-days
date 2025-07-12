#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw "No occurence has found";
    return it;
}

template <typename S, typename K>
void    print(S &contPrint, K it)
{
    for (; it != contPrint.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

#endif