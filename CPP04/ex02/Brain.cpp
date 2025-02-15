#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor is called" << std::endl;
}

Brain::Brain(std::string ideas[100])
{
    std::cout << "Brain constructor is called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = ideas[i];
        i++;
    }
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain copy constructor is called" << std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain assignment operator is called" << std::endl;
    if (this != &obj)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = obj.ideas[i];
            i++;
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor is called" << std::endl;
}
