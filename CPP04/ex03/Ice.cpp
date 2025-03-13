#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Ice default constructor is called" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
    std::cout << "Ice copy constructor is called" << std::endl;
    *this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
    std::cout << "assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor is called" << std::endl;
}

AMateria *Ice::clone() const
{
    AMateria *newIce = new Ice();
    Character::deleteMateria(newIce);
    return (newIce);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}