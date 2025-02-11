#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor is called" << std::endl;
    this->modifyHitPoint(100);
    this->modifyEnergyPoint(100);
    this->modifyAttackDamage(30);
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor is called" << std::endl;
    this->modifyName(name);
    this->modifyEnergyPoint(100);
    this->modifyHitPoint(100);
    this->modifyAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << "FragTrap assignment operator is called" << std::endl;
    ClapTrap::operator=(obj);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor is called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap ";
    std::cout << "asking for a high five!" << std::endl;
}