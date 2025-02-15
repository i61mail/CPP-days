#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor is called" << std::endl;
    this->type = "Dog";
    std::string ideas[100];
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "Dog idea ";
        i++;
    }
    this->idea = new Brain(ideas);
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor is called" << std::endl;
    this->type = type;
    std::string ideas[100];
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "Dog idea ";
        i++;
    }
    this->idea = new Brain(ideas);
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor is called" << std::endl;
    this->type = obj.type;
    this->idea = new Brain(*obj.idea);
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog assignment operator is called" << std::endl;
    this->type = obj.type;
    this->idea = new Brain(*obj.idea);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor is called" << std::endl;
    delete this->idea;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound is called" << std::endl;
}