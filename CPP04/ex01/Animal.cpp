#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor is called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(std::string type)
{
    std::cout << "Animal constructor is called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal copy constructor is called" << std::endl;
    this->type = obj.type;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor is called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
