#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

class customException : public std::exception
{
    public :
        virtual const char *what() const throw()
        {
            return "No occurence is found";
        }
};

template <typename T>
bool easyfind(T& container, int value)
{
    std::vector<int>::iterator first = container.begin();
    std::vector<int>::iterator last = container.end();

    while (first != last)
    {
        if (*first == value)
            return std::cout << "true" << std::endl;;
        first++;
    }
    throw customException();
}

#endif