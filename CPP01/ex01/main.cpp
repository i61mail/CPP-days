#include "Zombie.hpp"

int main()
{
    Zombie *multipZombie;

    multipZombie = zombieHorde(7, "Zombies");
    int i = 0;
    while (i < 7)
    {
        multipZombie[i].announce();
        i++;
    }
    delete[] multipZombie;
    return (0);
}