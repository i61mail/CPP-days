#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav1;
	ScavTrap scav2("billy russo");
	ScavTrap scav3(scav2);

	scav1.attack("the punisher");
	scav2.takeDamage(5);
	scav2.guardGate();
	scav3 = scav1;
	scav3.attack("billy russo");
	scav3.beRepaired(5);
	return (0);
}