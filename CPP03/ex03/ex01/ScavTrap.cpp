#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default constructor is called" << std::endl;
    this->modifyEnergyPoint(50);
    this->modifyHitPoint(100);
    this->modifyAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor is called" << std::endl;
    this->modifyName(name);
    this->modifyEnergyPoint(50);
    this->modifyHitPoint(100);
    this->modifyAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "ScavTrap assignment operator is called" << std::endl;
    ClapTrap::operator=(obj);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor is called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap ";
    std::cout << "in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (showEnergyPoint() == 0 || showHitPoint() == 0)
        return ;
    std::cout << "ScavTrap " << showName() << " ";
    std::cout << "attacks " << target << " ";
    std::cout << "causing " << showAttackDamage() << " ";
    std::cout << "points of damage!" << std::endl;
    modifyEnergyPoint(showEnergyPoint() - 1);
    // std::cout << "status : " << this->energyPoint << std::endl;
}
