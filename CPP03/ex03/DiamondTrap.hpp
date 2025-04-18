#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string name;
    public :
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &obj);
        DiamondTrap &operator=(const DiamondTrap &obj);
        ~DiamondTrap();
        void whoAmI();
        void modifyNameDiamond(std::string name);
        std::string showNameDiamond();
};

#endif
