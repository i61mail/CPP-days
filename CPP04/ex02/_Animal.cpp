#include "_Animal.hpp"

_Animal::_Animal()
{
    std::cout << "_Animal default constructor is called" << std::endl;
    this->type = "Empty";
}

_Animal::_Animal(std::string type)
{
    std::cout << "_Animal constructor is called" << std::endl;
    this->type = type;
}

_Animal::_Animal(const _Animal &obj)
{
    std::cout << "_Animal copy constructor is called" << std::endl;
    this->type = obj.type;
}

_Animal &_Animal::operator=(const _Animal &obj)
{
    std::cout << "_Animal assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

_Animal::~_Animal()
{
    std::cout << "_Animal destructor is called" << std::endl;
}

std::string _Animal::getType() const
{
    return (this->type);
}
