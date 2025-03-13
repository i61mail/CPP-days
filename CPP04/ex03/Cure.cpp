#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure default constructor is called" << std::endl;
    this->type = "cure";
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
    std::cout << "Cure copy constructor is called" << std::endl;
    *this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
    std::cout << "assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor is called" << std::endl;
}

AMateria *Cure::clone() const
{
    AMateria *newCure = new Cure();
    Character::deleteMateria(newCure);
    return (newCure);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}