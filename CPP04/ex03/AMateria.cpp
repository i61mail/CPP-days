#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor is called" << std::endl;
    this->type = "default";
}

AMateria::AMateria(AMateria const & obj)
{
    std::cout << "AMateria copy constructor is called" << std::endl;
    *this = obj;
}

AMateria & AMateria::operator=(AMateria const & obj)
{
    std::cout << "AMateria assignment operator is called" << std::endl;
    this->type = obj.type;
    return (*this);
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria constructor is called" << std::endl;
    this->type = type;
}
AMateria::~AMateria()
{
    std::cout << "AMateria destructor is called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (type);
}

void    AMateria::setType(const std::string &type)
{
    this->type = type;
}

void    AMateria::use(ICharacter &target)
{
    if (this->type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (this->type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
