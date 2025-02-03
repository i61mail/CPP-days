#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *multipZombies;
    int i = 0;

    multipZombies = new Zombie[N];
    while (i < N)
    {
        multipZombies[i].NameZombie(name);
        i++;
    }
    return (multipZombies);
}