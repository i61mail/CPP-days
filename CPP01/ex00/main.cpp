#include "Zombie.hpp"

//check new if failed

int main()
{
    Zombie zombie("Zombie");
    zombie.announce();

    Zombie  *zombiePointer;
    zombiePointer = newZombie("ZombiePointer");
    zombiePointer->announce();
    delete(zombiePointer);

    randomChump("zombieRandom");
    return (0);
}