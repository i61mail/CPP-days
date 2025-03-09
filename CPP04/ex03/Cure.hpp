#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        Cure(std::string type);
        Cure(const Cure &obj);
        Cure &operator=(const Cure &obj);
        ~Cure();
        void use(ICharacter& target);
        AMateria* clone() const;
};



#endif