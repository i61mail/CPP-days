#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor is called" << std::endl;
    this->type = "WrongAnimal Empty";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal constructor is called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal copy constructor is called" << std::endl;
    this->type = obj.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor is called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound hh" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
