#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource default constructor is called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &obj)
{
    std::cout << "IMateriaSource copy constructor is called" << std::endl;
    *this = obj;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &obj)
{
    std::cout << "IMateriaSource assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource destructor is called" << std::endl;
}