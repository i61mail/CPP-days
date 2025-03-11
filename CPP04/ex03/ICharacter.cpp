#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor is called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &obj)
{
    std::cout << "ICharacter copy constructor is called" << std::endl;
    *this = obj;
}

ICharacter & ICharacter::operator=(ICharacter const &obj)
{
    std::cout << "ICharacter assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructor is called" << std::endl;
}
