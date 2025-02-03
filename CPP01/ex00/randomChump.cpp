#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie  *zombieRandom;

    zombieRandom = newZombie(name);
    zombieRandom->announce();
    delete(zombieRandom);
}
