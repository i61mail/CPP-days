#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor is called" << std::endl;
    this->type = type;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat copy constructor is called" << std::endl;
    this->type = obj.type;
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}