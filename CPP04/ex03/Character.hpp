#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    protected :
        std::string name;
        AMateria *materia[4];
    public :
        Character();
        Character(std::string name);
        Character(const Character &obj);
        Character& operator=(const Character &obj);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif