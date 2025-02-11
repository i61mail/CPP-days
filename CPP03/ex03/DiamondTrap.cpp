#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->modifyHitPoint(100);
    this->modifyEnergyPoint(50);
    this->modifyAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    this->name = name;
    this->modifyName(name + "_clap_name");
    this->modifyHitPoint(100);
    this->modifyEnergyPoint(50);
    this->modifyAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = obj;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    this->name = obj.name;
    ClapTrap::operator=(obj);
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << this->name;
    std::cout << " and the ClapTrap name is ";
    std::cout << ClapTrap::showName() << std::endl;
}

void DiamondTrap::modifyNameDiamond(std::string name)
{
    this->name = name;
    this->modifyName(name + "_clap_name");
}

std::string DiamondTrap::showNameDiamond()
{
    return (this->name);
}