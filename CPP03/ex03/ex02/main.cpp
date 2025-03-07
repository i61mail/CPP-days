#include "FragTrap.hpp"

int main()
{
	FragTrap frag1;
	FragTrap frag2("billy russo");
	FragTrap frag3(frag2);

	frag1.modifyName("billy russo");
	frag1.attack("the punisher");
	frag2.takeDamage(5);
	frag2.highFivesGuys();
	frag3 = frag1;
	frag3.attack("billy russo");
	frag3.beRepaired(5);
	return (0);
}