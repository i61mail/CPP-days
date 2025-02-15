#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private :
        Brain *idea;
    public :
        Dog();
        Dog(std::string type);
        Dog(const Dog &obj);
        Dog &operator=(const Dog &obj);
        ~Dog();
        void    makeSound() const;
};

#endif