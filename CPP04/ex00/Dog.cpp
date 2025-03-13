#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor is called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor is called" << std::endl;
    this->type = type;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor is called" << std::endl;
    this->type = obj.type;
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}