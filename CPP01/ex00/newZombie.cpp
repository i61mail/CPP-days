#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  *zombiePointer;

    zombiePointer = new Zombie(name);
    return (zombiePointer);
}
