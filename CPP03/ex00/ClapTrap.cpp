#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoint(10), energyPoint(10), attackDamage(10)
{
    std::cout << "Default Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(10)
{
    std::cout << "Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "Assignation operator is called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->hitPoint = obj.hitPoint;
        this->energyPoint = obj.energyPoint;
        this->attackDamage = obj.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoint == 0 || this->hitPoint == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " ";
    std::cout << "attacks " << target << " ";
    std::cout << "causing " << this->attackDamage << " ";
    std::cout << "points of damage!" << std::endl;
    this->energyPoint -= 1;
    // std::cout << "status : " << this->energyPoint << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->energyPoint == 0 || this->hitPoint == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " ";
    std::cout << "takes " << amount << " ";
    std::cout << "points of damage!" << std::endl;
    this->hitPoint -= amount;
    // std::cout << "status : " << this->hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoint == 0 || this->hitPoint == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " ";
    std::cout << "gained " << amount << " ";
    std::cout << "points!" << std::endl;
    this->energyPoint -= 1;
    this->hitPoint += amount;
    // std::cout << "status : " << this->hitPoint << std::endl;
    // std::cout << "status : " << this->energyPoint << std::endl;
}