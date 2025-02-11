#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("the punisher");
    ClapTrap clapTrap4("billy russo");
    ClapTrap clapTrap2(clapTrap);

    clapTrap.attack("billy russo");
    clapTrap4.takeDamage(5);
    clapTrap4.beRepaired(5);
    clapTrap4.attack("the punisher");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    return (0);
}