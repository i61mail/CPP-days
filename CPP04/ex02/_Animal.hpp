#ifndef _ANIMAL_HPP
#define _ANIMAL_HPP

#include <iostream>

class _Animal
{
    protected :
        std::string type;
    public :
        _Animal();
        _Animal(std::string type);
        _Animal(const _Animal &obj);
        _Animal &operator=(const _Animal &obj);
        virtual ~_Animal();
        virtual void    makeSound() const = 0;
        std::string getType() const;
};

#endif