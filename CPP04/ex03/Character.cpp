#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    std::cout << "Character default constructor is called" << std::endl;
    name = "default";
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

Character::Character(std::string name)
{
    std::cout << "Character constructor is called" << std::endl;
    this->name = name;
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

Character::Character(const Character &obj) : ICharacter(obj)
{
    std::cout << "Character copy constructor is called " << std::endl;
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
    *this = obj;
}

Character &Character::operator=(const Character &obj)
{
    std::cout << "Character assignment operator is called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materia[i] != NULL)
            {
                delete materia[i];
                materia[i] = NULL;
            }
        }
        this->name = obj.name;
        for (int i = 0; i < 4; i++)
        {
            if (obj.materia[i])
                materia[i] = obj.materia[i]->clone();
            else
                materia[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor is called" << std::endl;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    int i = 0;
    while (i < 4)
    {
        if (materia[i] == NULL)
        {
            materia[i] = m;
            break;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && materia[idx] != NULL) {
        // collect materia[idx]
        // be careful of re-equip
        materia[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && materia[idx] != NULL)
        materia[idx]->use(target);
}

