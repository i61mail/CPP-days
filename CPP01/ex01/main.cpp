#include "Zombie.hpp"

int main()
{
    Zombie *multipZombie;

    int N = -45;
    multipZombie = zombieHorde(N, "Zombies");
    int i = 0;
    while (i < N)
    {
        multipZombie[i].announce();
        i++;
    }
    delete[] multipZombie;
    return (0);
}