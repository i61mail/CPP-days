#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
    std::string ideas[100];
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "Cat idea";
        i++;
    }
    this->idea = new Brain(ideas);
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor is called" << std::endl;
    this->type = type;
    std::string ideas[100];
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "Cat idea";
        i++;
    }
    this->idea = new Brain(ideas);
}

Cat::Cat(const Cat &obj) : _Animal(obj)
{
    std::cout << "Cat copy constructor is called" << std::endl;
    this->type = obj.type;
    this->idea = new Brain(*obj.idea);
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat assignment operator is called" << std::endl;
    this->type = obj.type;
    this->idea = new Brain(*obj.idea);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor is called" << std::endl;
    delete this->idea;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound is called" << std::endl;
}