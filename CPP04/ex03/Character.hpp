#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

struct MateriaNode
{
    AMateria *m;
    MateriaNode *next;
};

class Character : public ICharacter
{
    private :
        static MateriaNode *materiaList;
        std::string name;
        AMateria *materia[4];
    public :
        Character();
        Character(std::string name);
        Character(const Character &obj);
        Character& operator=(const Character &obj);
        ~Character();
        std::string const & getName() const;
        static void deleteMateria(AMateria *m);
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        static void deleteMateriaList();
};

#endif