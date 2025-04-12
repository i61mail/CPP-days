#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    // std::cout << "Default constructor is called" << std::endl;
    _array = NULL;
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    // std::cout << "Constructor is called" << std::endl;
    if (n == 0)
        throw std::length_error("Array size cannot be zero");
    _array = new T[n];
    _size = n;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
    // std::cout << "Copy constructor is called" << std::endl;
    this->_array = new T[obj.size()];
    this->_size = obj.size();
    for (size_t i = 0; i < obj.size(); i++)
        this-> _array[i] = obj._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
    // std::cout << "Copy assignment operator is called" << std::endl;
    if (this != &obj)
    {
        delete[] this->_array;
        this->_array = new T[obj.size()];
        this->_size = obj.size();
        for (size_t i = 0; i < obj.size(); i++)
            this->_array[i] = obj._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    // std::cout << "Destructor is called" << std::endl;
    delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}