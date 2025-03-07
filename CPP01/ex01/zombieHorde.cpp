#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *multipZombies;
    int i = 0;

    if (N < 0)
        return (NULL);
    multipZombies = new Zombie[N];
    while (i < N)
    {
        multipZombies[i].NameZombie(name);
        i++;
    }
    return (multipZombies);
}