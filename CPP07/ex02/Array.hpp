#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
    private :
        T *_array;
        unsigned int _size;
    public :
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();
        T &operator[](unsigned int index);

        unsigned int size() const;
};

#include "Array.tpp"

#endif