#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private :
        std::string name;
        int hitPoint;
        int energyPoint;
        int attackDamage;
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string  showName();
        int  showHitPoint();
        int  showEnergyPoint();
        int  showAttackDamage();
        void  modifyName(std::string name);
        void  modifyHitPoint(int hitPoint);
        void  modifyEnergyPoint(int energyPoint);
        void  modifyAttackDamage(int attackDamage);
};

#endif